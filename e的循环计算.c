#include<stdio.h>
int main()
{
	float n, i, e, f;
	f=1.0;e=1.0;
	for(n=1.0;n<=50.0;n++)
	{
	for(i=n;i>=1.0;i--)
	{
	f=f*i;
	}
	e=e+(1/f);
	printf("%f\n", e);
	}
	printf("Answer=%f", e);
	return 0;
}
