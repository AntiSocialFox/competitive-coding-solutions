#include <stdio.h>
int main()
{
	unsigned long n, temp;
	int digit, l = 0, sum = 0;
	scanf("%lu", &n);
	temp = n;
	while(temp)
	{
		l++;
		temp /= 10 ;
	}
	if(l != 10)
	{
		printf("Illegal ISBN\n");
	}
	else
	{
		while(n)
		{
			sum += l * (n % 10);
			n /= 10;
			l--;
		}
		if(sum % 11 == 0) printf("Legal ISBN\n");
		else printf("Illegal ISBN\n"); 
	}
}