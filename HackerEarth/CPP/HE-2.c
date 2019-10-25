#include <stdio.h>
#include <string.h>
int main()
{
	char a[10000], b[10000];
	int al = 0, bl = 0, same =0;
	scanf("%s %s", &a, &b);
	al = strlen(a);
	bl = strlen(b);
	if (al >= bl)
	{
		for (int i = 0; a[i] != '\0'; ++i)
		{
			for (int j = 0; b[j] != '\0'; ++j)
			{
				if (a[i] == b[j]) 
				{
					same++;
					printf("%c\n", a[i]);
				}
			}
		}
	}
	else
	{
		for (int i = 0;b[i] != '\0'; ++i)
		{
			for (int j = 0;a[j] != '\0'; ++j)
			{
				if (b[i] == a[j])
				{
					same++;
					printf("%c\n", a[i]);
				}
			}
		}

	}
	printf("%i\n", same);
}