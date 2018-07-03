/*
 * Combinacion.h
 *
 *  Created on: 26/06/2018
 *      Author: Propietario
 */

#ifndef COMBINACION_H_
#define COMBINACION_H_

typedef enum{false, true} bool;

typedef void *Type;

/*
 * STACK *
 */
typedef struct strStack *Stack;

Stack createStack();

void destroyStack(Stack);

bool pushStack(Stack, Type);

Type popStack(Stack);

Type topStack(Stack);

bool isEmptyStack(Stack);

int sizeStack(Stack);

/*
 * Queue
 */
typedef struct strQueue *Queue;

Queue queueCreate();

bool isEmptyQueue(Queue);

Type peekQueue(Queue);

int sizeQueue(Queue);

void OfferQueue(Queue,Type);

void destroyQueue(Queue);

Type PollQueue(Queue);

#endif /* COMBINACION_H_ */
