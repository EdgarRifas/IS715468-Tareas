/*Edgar Francisco Medina Rifas
 IS715468
 Instituto Técnologico de Estudios Superiores
 Programación con Memoria Dinámica
 Dr. Francisco Cervantes.
 */
//Librerias y Constantes
#include <stdio.h>
#include <stdlib.h>
#include "Combinacion.h"
#include <string.h>
//Prototipo de funciones
bool balancedBrackets(char* exp);


char * infixToPosfix(char * exp);
bool hasHigherPrecedence(char* top, char *operator);
int value (char *x);
int main()
{
    //Buffer
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
	char ecuacion[100];
	printf("Primer programa:\n");
	printf("Ingresa la ecuacion aritmetica: ");
	gets(ecuacion);
	if(balancedBrackets(ecuacion)==true)
	{
		printf("¡Ecuacion balanceada!\n");
	}
	else
	{
		printf("¡Ecuacion no balanceada!\n");
	}
	printf("Segundo programa: \n");
	infixToPosfix("8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8");
	system("Pause");
	return 0;

}
//Desarrollo de funciones
bool balancedBrackets(char* exp)
{
    Stack s1;
    s1=createStack();
    int i=0;
    char *temp;
    while(exp[i]!='\0')
    {
        if (exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            pushStack(s1,(void *)&exp[i]);
        }
        else if (exp[i]==')')
		{
         if(isEmptyStack(s1)==true)
        {
        		return false;
        }
			temp=(char*)popStack(s1);
			if (*temp!='(')
			{
				return false;
			}
		}
        else if (exp[i]=='}')
		{
            if(isEmptyStack(s1)==true)
           {
           		return false;
           }
			temp=(char*)popStack(s1);
			if (*temp!='{')
			{
				return false;
			}
		}
        else if (exp[i]==']')
		{
            if(isEmptyStack(s1)==true)
           {
           		return false;
           }
			temp=(char*)popStack(s1);
			if (*temp!='[')
			{
				return false;
			}
		}
        i++;
    }
    if(isEmptyStack(s1)==true)
    {
    	return true;
    }
    else
    {
        return false;
    }

}

char * infixToPosfix(char * exp)
{
	Stack s1 = createStack();
	Queue resultado = queueCreate();
	Queue tempR = queueCreate();
	char cadf[200];
	char * dcad;
	char * prueba;
	char * espacio;
	char *topePila;
	char *topeCola;
	int condition;
	int i=0;

	while(exp[i]!='\0')
	{
		OfferQueue(tempR, (void *)&exp[i]);
		i++;
	}

	while(isEmptyQueue(tempR)!=true)
	{
		prueba = (char *)PollQueue(tempR);
		condition = value(prueba);
		switch(condition)
		{
		case 0:
			pushStack(s1, prueba);
			break;
		case 1:
			topePila = (char *)topStack(s1);
			while(isEmptyStack(s1)!=true && *topePila!='(')
			{
				if(hasHigherPrecedence(topePila, prueba)==true)
				{
					topePila=popStack(s1);
					OfferQueue(resultado, topePila);
					topePila = topStack(s1);
				}
				else
				{
					break;
				}
			}
			pushStack(s1, prueba);
			break;
		case 2:
			topePila = (char *)topStack(s1);
			while(isEmptyStack(s1)!=true && *topePila!='(')
			{
				if(hasHigherPrecedence(topePila, prueba)==true)
				{
					topePila=popStack(s1);
					OfferQueue(resultado, topePila);
					topePila = topStack(s1);
				}
				else
				{
					break;
				}
			}
			pushStack(s1, prueba);
			break;
		case 3:
			topePila = (char *)topStack(s1);
			while(isEmptyStack(s1)!=true && *topePila!='(')
			{
				topePila=popStack(s1);
				OfferQueue(resultado, topePila);
				topePila = topStack(s1);
			}
			if(isEmptyStack(s1)!=true && *topePila=='(')
			{
				popStack(s1);
			}
			break;
		case 4:
			OfferQueue(resultado, prueba);
			espacio = peekQueue (tempR);
			if (espacio!=NULL && (*espacio < 48 || *espacio > 57) && (*espacio < 65 || *espacio > 90) && (*espacio < 97 || *espacio > 122))
			{
				OfferQueue (resultado, espacio);
			}
			break;
		default:
			break;
		}
	}
	while(isEmptyStack(s1)!=true)
	{
		topePila=popStack(s1);
		OfferQueue(resultado, topePila);
	}

	while(isEmptyQueue(resultado)!=true)
	{
		topeCola=(char *)PollQueue(resultado);
		printf("%c",*topeCola);
	}
	dcad=cadf;
	return dcad;
}

int value (char *x)
{
    int num;
	if(*x == '(')
    {
		num=0;
        return num;
    }
	else if(*x == '+' || *x == '-')
    {
       num=1;
    	return num;
    }
	else if(*x == '*' || *x == '/')
    {
        num=2;
    	return num;
    }
	else if(*x == ')')
    {
		num=3;
        return num;
    }
	else
	{
		num=4;
		return num;
	}
}

bool hasHigherPrecedence(char *top, char *operator)
{
	int a, b;
	a=value(top);
	b=value(operator);
	if(a>b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
