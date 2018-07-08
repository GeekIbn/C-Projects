#include<stdio.h>
#include<math.h> 
float distance(int x,int y)
{
	int gougu;
	float dis;
	if(x>=0&&y>=0)
	{
		gougu=(x-5)*(x-5)+(y-5)*(y-5);
		dis=sqrt(gougu);
		return dis;
	}
	else if(x<0&&y>0)
	{
		gougu=(x+5)*(x+5)+(y-5)*(y-5);
		dis=sqrt(gougu);
		return dis;
	}
	else if(x<=0&&y<=0)
	{
		gougu=(x+5)*(x+5)+(y+5)*(y+5);
		dis=sqrt(gougu);
		return dis;
	}
	else if(x>0&&y<0)
	{
		gougu=(x-5)*(x-5)+(y+5)*(y+5);
		dis=sqrt(gougu);
		return dis;
	}
}
int main(int x,int y)
{
	float temp;
	for(y=50;y>=(-50);y--)
	{
		for(x=(-50);x<=50;x++)
		{
			temp=distance(x,y);
			if(temp>5)
			{
				printf("-");
			}
			else
			{
				printf(" ");
			}
			if(x==50)
			{
				printf("\n");
			}
		}
	}
	return 0;
}
