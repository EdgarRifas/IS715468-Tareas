#include <stdio.h>
#include <stdlib.h>
#include "Combinacion.h"

struct strSNode
{
	Type data;
	struct strSNode *prior;
};

typedef struct strSNode NodeS;

struct strStack
{
	NodeS *top;
	int size;
};

Stack createStack()
{
	Stack new = (Stack) malloc(sizeof(struct strStack));
	if (new==NULL)
	{
		return NULL;
	}
	new->size=0;
	new->top=NULL;
	return new;
}

void destroyStack(Stack who)
{
	while(isEmptyStack(who)!=true)
	{
		popStack(who);
	}
	free(who);
}

bool pushStack(Stack who, Type data)
{
	NodeS *nNode = (NodeS *)malloc(sizeof(NodeS));
	if(nNode==NULL)
	{
		return false;
	}
	nNode->prior=who->top;
	nNode->data=data;
	who->size++;
	who->top=nNode;
	return true;
}

Type popStack(Stack who)
{
	if(who->top==NULL)
	{
		return NULL;
	}
	Type temp;
	NodeS *nNode;
	temp=who->top->data;
	who->size--;
	nNode=who->top;
	who->top=who->top->prior;
	free(nNode);
	return temp;
}

Type topStack(Stack who)
{
	if(who->top==NULL)
	{
		return NULL;
	}
	return who->top->data;
}

bool isEmptyStack(Stack who)
{
	if(who->size==0)
	{
		return true;
	}
	else
	{
	return false;
	}
}

int sizeStack(Stack who)
{
	return who->size;
}




/*
 * Queue *
 */

struct strQNode
{
	Type data;
	struct strQNode *next;
};

typedef struct strQNode NodeQ;

struct strQueue
{
	NodeQ* first;
	NodeQ* last;
	int size;
};

Queue queueCreate()
{
	Queue new = (Queue)malloc(sizeof(struct strQueue));
	if(new==NULL)
	{
		return 0;
	}
	new->first=NULL;
	new->last=NULL;
	new->size=0;
	return new;
}

bool isEmptyQueue(Queue who)
{
	if(who->size==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Type peekQueue (Queue who)
{
	if(who->size==0)
	{
		return NULL;
	}
	else
	{
		return who->first->data;
	}
}

int sizeQueue(Queue who)
{
	return who->size;
}

void OfferQueue (Queue who, Type data)
{
	NodeQ* newNode = (NodeQ*)malloc(sizeof(struct strQNode));
	if(newNode==NULL)
	{
		return;
	}
	newNode->next=NULL;
	newNode->data=data;
	if(who->size==0)
	{
		who->first=newNode;
		who->last=newNode;
	}
	else
	{
		who->last->next=newNode;
		who->last=newNode;
	}
	who->size++;
	free(newNode);
}

void destroyQueue(Queue who)
{
	while(isEmptyQueue(who)!=true)
	{
		PollQueue(who);
	}
	free(who);
}

Type PollQueue(Queue who)
{
	Type temp;
	NodeQ* TempN;
	if(who->size==0)
	{
		return 0;
	}
	else
	{
		TempN=who->first;
		temp=who->first->data;
		who->first=who->first->next;
		free(TempN);
		who->size--;
		if(isEmptyQueue(who)==true)
		{
			who->last=NULL;
		}
		return temp;
	}
	return NULL;
}
