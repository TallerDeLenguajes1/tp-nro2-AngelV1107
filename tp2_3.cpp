#include <stdio.h>
#include <stdlib.h>


char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};



typedef struct compu {
int velocidad;//entre 1 y 3 GHertz
int anio;//entre 2000 y 2017
int cantidad;//entre 1 y 4
char *tipo_cpu;//valores del arreglo tipos
} compu;



int intervRand (int min, int max);
void mostrarPC (compu PC);
void cargarDatosListaPc (compu *array_pcs, int tama_array);
void mostrarListaPc (compu *array_pcs, int tama_array);
void mostrarPcVieja (compu *array_pcs, int tama_array);
void mostrarPcVeloz (compu *array_pcs, int tama_array);

int main()
{
	int tama_array;
	compu *array_pcs;

	printf("Ingrese la cantidad de PCs que quiere:\n");
	scanf("%d", &tama_array);

	//Alojar memoria para el listado de PCs
	array_pcs = (compu *) malloc (sizeof(compu) * tama_array);


	cargarDatosListaPc(array_pcs, tama_array);
	mostrarListaPc(array_pcs, tama_array);
	mostrarPcVieja(array_pcs, tama_array);
	mostrarPcVeloz(array_pcs, tama_array);

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


void mostrarPC (compu pc) {
	printf("Velocidad de prcesamiento: %d GHz\n", pc.velocidad);
	printf("Anio de fabricacion: %d\n", pc.anio);
	printf("Cantidad de nucleos: %d\n", pc.cantidad);
	printf("Tipo de procesador: %s\n", pc.tipo_cpu);

	return;
}

void cargarDatosListaPc (compu *array_pcs, int tama_array) {

	for (int i = 0; i < tama_array; i++)
	{
		array_pcs[i].velocidad = intervRand(1, 3);
		array_pcs[i].anio = intervRand(2000, 2017);
		array_pcs[i].cantidad = intervRand(1, 4);
		array_pcs[i].tipo_cpu = tipos[(intervRand(0, 5))];
	}	

	return;
}

void mostrarListaPc (compu *array_pcs, int tama_array) {

	printf("\nListado de PCs: \n\n");
	for (int i = 0; i < tama_array; i++) 
	{
		printf("PC #%d\n", i+1);
		mostrarPC(array_pcs[i]);
		printf("\n");
	}

	return;
}

void mostrarPcVieja (compu *array_pcs, int tama_array) {

	int mas_vieja = 0;

	for (int i = 0; i < tama_array; ++i)
	{
		if (array_pcs[i].anio <= array_pcs[mas_vieja].anio) {
			mas_vieja = i;
		}		
	}
	printf("\nDatos de la PC mas antigua:\n");
	printf("PC #%d\n", mas_vieja+1);
	mostrarPC(array_pcs[mas_vieja]);
	printf("\n");

	return;
}

void mostrarPcVeloz (compu *array_pcs, int tama_array) {

	int mas_veloz = 0;

	for (int i = 0; i < tama_array; ++i)
	{
		if (array_pcs[i].velocidad >= array_pcs[mas_veloz].velocidad) {
			mas_veloz = i;
		}		
	}
	printf("\nDatos de la PC mas rapida:\n");
	printf("PC #%d\n", mas_veloz+1);
	mostrarPC(array_pcs[mas_veloz]);
	printf("\n");

	return;
}