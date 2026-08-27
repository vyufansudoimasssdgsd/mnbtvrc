#include <stdio.h>
#define N 5

int main()
{
	int i,j,x;
	
	//primero definir bien matriz, luego poblarla
	
	int matriz [N][N];
	
	//a poblarla
	x=0;
	for (i=0 ; i<5 ; i++)
	{
		x=10*i;
		for (j=0 ; j<5 ; j++)
		{
			matriz[i][j] = x;
			printf("%d ",matriz[i][j]);
			x+=1;
		}
		printf("\n");
	}
	
printf("\n");
	i=0;
	j=0;
	x=0;
	for (j=0 ; j<5 ; j++)
	{
		x+=1;
		for (i=0 ; i<5 ; i++)
		{
			x=10*i;
			matriz[i][j] = x;
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
	
}
