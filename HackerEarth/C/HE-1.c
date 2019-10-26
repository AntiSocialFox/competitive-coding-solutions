#include <stdio.h>

int main(){
	char a[10];
	scanf("%s",&a);
	int d0,d1,d3,d4,d5,d7,d8;
	d0 = a[0] - '0';
	d1 = a[1] - '0';
	d3 = a[3] - '0';
	d4 = a[4] - '0';
	d5 = a[5] - '0';
	d7 = a[7] - '0';
	d8 = a[8] - '0';
	if(
		((d0 + d1) % 2 == 0)&&
		((d3 + d4) % 2 == 0)&&
		((d4 + d5) % 2 == 0)&&
		((d7 + d8) % 2 == 0)&&
		a[6] == '-'
		)
	{
		if(
			a[2] != 'A' &&
			a[2] != 'E' &&
			a[2] != 'I' &&
			a[2] != 'O' &&
			a[2] != 'U' &&
			a[2] != 'Y' 
			)
		{
			printf("valid\n");
		}
		else
		{
			printf("invalid\n");
		}
	}
	else
	{
		printf("invalid\n");
	}
}