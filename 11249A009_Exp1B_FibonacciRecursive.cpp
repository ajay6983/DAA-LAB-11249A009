#include <stdio.h>
int fb(int n)
{
	if (n==0)
	{
		return 0;
	}
	else if (n==1|n==2)
	{
		return 1;
	}
	else
	return fb(n-1)+fb(n-2);
	
}
int main()
{
	int i;
	printf("Enter a number:");
	scanf("%d",&i);
	printf("The %dth term of the fibonacci series is: %d",i,fb(i));
	return 0;
}
