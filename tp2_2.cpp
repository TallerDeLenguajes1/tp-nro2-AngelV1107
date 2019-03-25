#include <stdio.h>
#include <stdlib.h>
#define N 4
#define M 5

int intervRand (int min, int max);

int main()
{
	int columnas, i, j, pares;
	
	int * matriz[15]; 
	int * vectorPares;
	columnas = intervRand(10,15);

	//Generar matriz dinamica
	for (i=0; i<15; i++) {
		matriz[i] = (int *) malloc(sizeof(int) * columnas);
	}

	//Generar vector dinamico de cantidad de pares
	vectorPares = (int *) malloc (sizeof(int) * 15);

	//Llenar matriz con valores aleatorios
	for (i=0; i<15; i++) {
		for (j=0; j<columnas; j++) {
			*(matriz[i] + j) = intervRand(100, 999);
		}
	}

	//Mostrar matriz por pantalla
	for (i=0; i<15; i++) {
		for (j=0; j<columnas; j++) {
			printf("%d  ", *(matriz[i] + j));			
		}
		printf("\n");
	}

	//Alojar cantidad de pares en vector correspondiente
	printf("\n");
	for (i=0; i<15; i++) {
		pares = 0;
		for (j=0; j<columnas; j++) {
			if ((*(matriz[i] + j) % 2) == 0) {
				pares++;
			}
		}
		*(vectorPares + i)= pares;
	}

	//Mostrar por pantalla el vector
	for (i=0; i<15; i++) {
		printf("%d  ", *(vectorPares + i));
	}




	return 0;
}


int intervRand (int min, int max) {
	int intervalo, random, i;
	float paso;

	if (min > max) {
		min = min + max;
		max = min - max;
	}

	intervalo = max-min +1;
	paso = (float) RAND_MAX/intervalo;

	random = rand();
	i = 1;

	while (i * paso <  random) {
		i++;
	};
	
	return (i + min - 1);
}