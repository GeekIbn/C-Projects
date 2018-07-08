#include<stdio.h>
int main()
{
	int x, y, con;
	for(x=1;x<=9;x++)
	{
	for(y=1;y<=x;y++)
	{
		con=x*y;
		printf("%d*%d=%d ",y,x,con);
	}
	printf("\n");
	}
	return 0;
}
