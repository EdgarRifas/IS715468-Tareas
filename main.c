/*IS715468
 * main.c
 *
 *  Created on: 05/06/2018
 *      Author: Edgar Francisco Medina Rifas.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <inttypes.h>
//Variable global para la aproximación de PI.
double suma=0;
DWORD WINAPI piA(void *);

typedef struct
{
	long long int limiteI;
	long long int limiteM;
}param;

int main()
{
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	//Arreglo de Handles
	HANDLE h[16];
	int hilos;
	//Arreglo de parametros para los futuros hilos.
	param datos[16];
	long long int razon=50000000000;
	printf("Cuantos hilos quieres: ");
	scanf("%d",&hilos);
	razon=razon/hilos;
	//Comienza el cronometro de milisegundos.
	clock_t start=clock();
	//Creación de hilos y sus respectivos rangos. Mediante formula de diferenciales en calculo.
	for (int i=0;i<hilos;i++)
	{
		datos[i].limiteI=(razon*i)+1;
		datos[i].limiteM=razon*(i+1);
		h[i]=CreateThread(NULL,0,piA,(void *)&datos[i],0,NULL);
	}
	//For para esperar que todos los hilos terminen de correr.
	for (int i=0; i<hilos;i++)
	{
		WaitForSingleObject(h[i],INFINITE);
	}
	clock_t stop= clock();
	int ms = 1000 * (stop-start)/CLOCKS_PER_SEC;
	printf("PI: %.10lf\n",suma);
	printf("Tiempo: %d ms\n",ms);
	system("Pause");
	return 0;
}
//Función para hilos que aproxima el valor a Pi con 50,000,000,000.
DWORD WINAPI piA(void * arg)
{
	param *arreglo= (param *) arg;
	double temp=0;
	long long int i;
	for (i=arreglo->limiteI;i<=arreglo->limiteM; i++)
	{
		temp+=((i + 1) & 1 ? -1.0 : 1.0)/(2*i-1);
	}
	temp*=4;
	suma+=temp;
	return 0;
}
