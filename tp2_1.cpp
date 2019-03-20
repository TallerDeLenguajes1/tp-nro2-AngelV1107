#include <stdio.h>


void main(){
	int buff[5] = {5,15,30,10,35};
	int *p;
	int i;

	p = buff;

	printf("Accediendo a los elementos mediante notacion subindexada:\n");
	for (i=0;i<5;i++)
	{
		printf("%d\n", buff[i]);
	}



	printf("Accediendo a los elementos mediante puntero p con aritmetica de punteros:\n");
	for (i=0;i<5;i++)
	{
		printf("%d\n", *(p+i));
	}


	printf("Accediendo a los elementos mediante el areglo con aritmetica de punteros:\n");
	for (i=0;i<5;i++)
	{
		printf("%d\n", *(buff+i));
	}


	printf("Accediendo a la direccion de memoria de cada elemento:\n");
	for (i=0;i<5;i++)
	{
		printf("%p\n", (p+i));
	}

	printf("El arreglo tiene un tamanio de %d bytes y el puntero %d bytes", sizeof(buff), sizeof(p));


	return;
}