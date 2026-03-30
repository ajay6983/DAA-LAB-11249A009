#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print bins (shows remaining capacity in each bin)
void printBins(int bin_rem[], int binsUsed) {
    printf("Total bins used: %d\n", binsUsed);
    for (int i = 0; i < binsUsed; i++) {
        printf("Bin %d remaining capacity: %d\n", i + 1, bin_rem[i]);
    }
    printf("\n");
}

/* ---------------- FIRST FIT ---------------- */
void firstFit(int weight[], int n, int capacity) {
    int bin_rem[MAX];
    int binsUsed = 0;
    
    for (int i = 0; i < n; i++) {
        int placed = 0;
        for (int j = 0; j < binsUsed; j++) {
            if (bin_rem[j] >= weight[i]) {
                bin_rem[j] -= weight[i];
                placed = 1;
                break;
            }
        }
        if (!placed) {
            bin_rem[binsUsed] = capacity - weight[i];
            binsUsed++;
        }
    }
    
    printf("First Fit:\n");
    printBins(bin_rem, binsUsed);
}

/* ---------------- FIRST FIT DECREASING ---------------- */
// Comparator for sorting in descending order
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

void firstFitDecreasing(int weight[], int n, int capacity) {
    int sorted[MAX];
    
    // Create sorted copy of weights
    for (int i = 0; i < n; i++) {
        sorted[i] = weight[i];
    }
    
    // Sort in decreasing order
    qsort(sorted, n, sizeof(int), compare);
    
    firstFit(sorted, n, capacity);
    printf("First Fit Decreasing applied.\n");
}

/* ---------------- BEST FIT ---------------- */
void bestFit(int weight[], int n, int capacity) {
    int bin_rem[MAX];
    int binsUsed = 0;
    
    for (int i = 0; i < n; i++) {
        int min_space = capacity + 1;
        int bestIndex = -1;
        
        // Find bin with minimum remaining space that can accommodate item
        for (int j = 0; j < binsUsed; j++) {
            if (bin_rem[j] >= weight[i] && 
                bin_rem[j] - weight[i] < min_space) {
                bestIndex = j;
                min_space = bin_rem[j] - weight[i];
            }
        }
        
        if (bestIndex != -1) {
            bin_rem[bestIndex] -= weight[i];
        } else {
            bin_rem[binsUsed] = capacity - weight[i];
            binsUsed++;
        }
    }
    
    printf("Best Fit:\n");
    printBins(bin_rem, binsUsed);
}

/* ---------------- MAIN FUNCTION ---------------- */
int main() {
    int n, capacity;
    int weight[MAX];
    
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);
    
    printf("Enter item weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    
    firstFit(weight, n, capacity);
    firstFitDecreasing(weight, n, capacity);
    bestFit(weight, n, capacity);
    
    return 0;
}
