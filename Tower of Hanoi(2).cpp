#include <stdio.h>
int toh(int n, char from,char to,char aux)
{
	if(n==1)
	{
		printf("move disk from %c to %c\n",from,to);
		return 0;	
	}
	toh(n-1,from,aux,to);
	printf("move disk  from %c to %c\n",from,to);
	toh(n-1,to,aux,from);
}
int main()
{
	int n;
	printf("Enter number of disks:");
	scanf("%d",&n);
	toh(n,'A','B','C');
	return 0;
}
