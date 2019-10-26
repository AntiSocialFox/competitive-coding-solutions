#include <stdio.h>
int check_prime(int x)
{
	for(int i = 2; i < x / 2; i++)
	{
		if(x % i == 0) return 0;
	}
	return 1;
}
int main()
{
	int t, n, dp, dn, temp;
	char a[500];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		scanf("%s", &a);
		for(int i = 0; i < n; i++)
		{
			dp = 0;
			dn = 0;
			temp = a[i];
			if(temp >= 33 && temp <= 64) temp = 65;
			else if(temp >= 91 && temp <= 93) temp = 89;
			else if(temp >= 94 && temp <= 96) temp = 97;
			else if(temp >= 123) temp = 122;
			for(int j = temp; check_prime(j) != 1; j--)
			{
				if(j == 65) 
				{
					dn = 32767;
					break;
				}
				else if(j == 97)
				{
					dn = 32767;
					break;
				}
				else dn++;
			} 
			
			for(int j = temp; check_prime(j) != 1; j++) 
			{
				if(j == 90)
				{
					dp = 32767;
					break;
				}
				else if(j == 122)
				{
					dp = 32767;
					break;
				}
				else dp++;
			}
			
			if(dp < dn) a[i] = temp + dp;
			else a[i] = temp - dn;
			printf("%c", a[i]);
		}
		printf("\n");
	}
}
