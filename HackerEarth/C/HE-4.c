#include <stdio.h>
int main()
{
	unsigned long n, m, l , r, k, j = 0, i, ans = 0;
	int a;
	scanf ("%lu %lu", &n, &m);
	scanf ("%lu %lu", &l, &r);
	scanf ("%lu", &k);
	unsigned long b[r - l];
	a = n % m;
	if (l <= m && r >= m)
	{
		for(i = l; i < m ; i++)
		{
			if(n % i == a)
			{
				ans++;
				b[j] = i;
				j++;
			}
		}
		for(i = m + 1; i <= r ; i++)
		{
			if(n % i == a)
			{
				ans++;
				b[j] = i;
				j++;
			}
		}
	}
	else
	{
		for(i = l; i <= r ; i++)
		{
			if(n % i == a)
			{
				ans++;
				b[j] = i;
				j++;
			}
		}		
	}

	printf("%lu\n", ans);
	if (ans > k) printf("-1\n");
	else
	{
		for (i = 0; i < ans; ++i)
		{
			printf("%lu ", b[i]);
		}
	}
}