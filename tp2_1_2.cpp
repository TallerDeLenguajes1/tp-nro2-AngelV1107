#include <stdio.h>
#define N 4
#define M 5



int main()
{
	int f,c;
	double mt[N][M], cont;
	cont = 1.0;

	mt[0][0] = 1.0;
	mt[0][1] = 1.0;
	mt[0][2] = 1.0;
	mt[0][3] = 1.0;


	for (f=0; f<N; f++) 
	{
		for (c=0; c<M; c++)
		{
			mt[f][c] = cont;
			cont+= 1.0;
		}
	}


	for (f=0; f<N; f++) 
	{
		for (c=0; c<M; c++)
		{
			printf("%lf    ", *(*(mt+f) + c));
		}
		printf("\n");
	}

	return 0;
}