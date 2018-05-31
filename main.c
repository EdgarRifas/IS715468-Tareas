//*Edgar Francisco Medina Rifas
//IS715468

//Librerías, funciones, enumeraciones
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
		char nombre[15];
		float calificacion;
	} Profesor;

float averageArray(Profesor prof[] , int w, char *name);
void readArray(Profesor obj[], int n);
void mergeArrays(Profesor obj[], int n, Profesor obj1[], int m, Profesor obj2[], int o);
void sortArray(Profesor obj[], int n);
void printArray(Profesor obj[], int n);
//Main
int main()
{
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	Profesor arr1[20];  //Primer arreglo
	Profesor arr2[20];  //Segundo arreglo
	Profesor arrF[40];  //Arreglo final, con elementos fusionados y ordenados
	int n1, n2, n3; //Longitud de los arreglos
	printf("Bienvenido al programa -Recomendación de Profesores.\n");
	printf("Ingresa el la cantidad de profesores que tiene la lista de Ingenieria [1-20]: ");
	scanf("%d",&n1);
	while (n1<1 || n1>20)
	{
		printf("Ingresa un numero dentro del rango[1-20]:\n");
		scanf("%d",&n1);
	}
	readArray(arr1, n1); //leer el primer arreglo
//	fflush(stdin);
	printf("Ingresa el la cantidad de profesores que tiene la lista de Licenciados [1-20]: ");
	scanf("%d",&n2);
	while (n2<1 || n2>20)
	{
		printf("Ingresa un numero dentro del rango[1-20]:\n");
		scanf("%d",&n2);
	}
	readArray(arr2, n2); //leer el segundo arreglo
//	printArray(arr1,n1);
//	printArray(arr2,n2);
	n3= n1+n2;
	mergeArrays(arr1, n1, arr2, n2, arrF, n3);//Fusionar los dos arreglos en un tercer arreglo
//
//	sortArray(arrF,n3 );
//	printArray(arrF,40);
	return 0;
}
//Desarrollo de Funciones
float averageArray(Profesor prof[] , int w, char *name){
    Profesor *ap=prof;
	float suma = 0;
    float elements = 0;

    for (int i = 0; i < w; i++) {
        if (strcmp((ap+i)->nombre,name)==0) {
            suma+=(ap+i)->calificacion;
            elements++;
        }
    }

    return suma/elements;

}
void readArray(Profesor obj[], int n)
{
	Profesor *ap=obj;
	printf("Nombre - Calificacion\n");
	for (int i=0; i<n; i++)
	{
		scanf("%s[^\n]",(*(ap+i)).nombre);
		scanf("%f",&(*(ap+i)).calificacion);
		while((*(ap+i)).calificacion<1 || (*(ap+i)).calificacion>10)
		{
			printf("Ingresa una calificación valida [1-10]: ");
			scanf("%f",&(*(ap+i)).calificacion);
		}
	}
}

void sortArray(Profesor obj[], int n)
{
	Profesor *ap1=obj;
	Profesor temp;
	for(int i=0;i<n-1;i++)
	{
		for (int j=0; j<n-1-i; j++)
		{
			if((*(ap1+j)).calificacion<(*(ap1+j+1)).calificacion)
			{
				temp.calificacion=(*(ap1+j)).calificacion;
				strcpy(temp.nombre,(*(ap1+i)).nombre);

				(*(ap1+j)).calificacion=(*(ap1+j+1)).calificacion;
				strcpy((*(ap1+j)).nombre,(*(ap1+j+1)).nombre);

				(*(ap1+j+1)).calificacion=temp.calificacion;
				strcpy((*(ap1+j+1)).nombre,temp.nombre);
				}
			}

		}
}
void printArray(Profesor obj[], int n)
{
	Profesor *ap=obj;
	for (int i=0; i<n; i++)
	{
		if(strcmp((*(ap+i)).nombre," ")!=0)
		{
			printf("%s ",(*(ap+i)).nombre);
			printf("%.2f\n",(*(ap+i)).calificacion);
		}

	}
}

void mergeArrays(Profesor obj[], int n, Profesor obj1[], int m, Profesor obj2[], int o)
{
	Profesor *ap1=obj, *ap2=obj1, *ap3=obj2;
	Profesor temp[40];
	Profesor *t=temp;
	int i, j; //tam=0;
	//int *pt=&tam;

	for (i=0; i<n;i++)
	{
		strcpy((*(t+i)).nombre,(*(ap1+i)).nombre);
		(*(t+i)).calificacion=(*(ap1+i)).calificacion;
	}
	//For inicializador arrF
	for (j=0;j<m;j++)
	{
		strcpy((*(t+i)).nombre, (*(ap2+j)).nombre);
		(*(t+i)).calificacion=(*(ap2+j)).calificacion;
		i++;
	}
//	printArray(temp, o);
	int var=0;
	int condition = 0;
	for (i=0;i<40;i++)
	{
		strcpy((*(ap3+i)).nombre, "empty");
		(ap3+i)->calificacion=0;
	}
	for (i=0; i<o;i++)
	{
		condition=0;
//		printf("Item: %s\n", (t+i)->nombre);
//		printf("Condicion= %d\n",condition);
		for(int x=0; x<o;x++){
//			printf("Comparacion con %s\n",(ap3+x)->nombre);
			if(strcmp((ap3+x)->nombre,(t+i)->nombre)==0){
				condition = 1;
//				printf("Se ejecuto %s\n", (t+i)->nombre);
			}
		}

		if(condition==0){
//			printf("Se copio %s a final\n", (t+i)->nombre);
			strcpy((ap3+var)->nombre,(t+i)->nombre);
			(ap3+var)->calificacion = 0;
			var++;

		}

	}
//	printf("\n var=%d\n", var);
//	printf("\n");
////	printArray(obj2, var);
//	printf("\n");
//
	for (i=0;i<var;i++)
	{
		(ap3+i)->calificacion=averageArray(temp,o,(ap3+i)->nombre);
	}
	sortArray(obj2,var);
	printf("\n-Recomendacion de profesores-\n");
	printArray(obj2, var);
//	printf("\n");
//	printArray(temp,o);
//	int var=averageArray(temp, o, obj2);
//	sortArray(obj2, var);
//	printf("Hola");
//	printf("Nombre - Calificacion.\n");
//	printArray(obj2, var);
}

