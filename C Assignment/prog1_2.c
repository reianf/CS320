#include<stdio.h>
#include<stdlib.h>
#include"prog1_2.h"

STACK* MakeStack(int initialCapacity) {
  STACK *stack;
	stack = (STACK *) malloc(sizeof(STACK));
	stack->size = 0; 
	stack->capacity = initialCapacity;
	stack->data = (int*) malloc(sizeof(int) * stack->capacity);
	return stack;
}

void Push(STACK *stackPtr, int data) {
	if(stackPtr->size >= stackPtr->capacity) {
		Grow(stackPtr);
	}
	stackPtr->data[stackPtr->size] = data;
	stackPtr->size++;
}

int Pop(STACK *stackPtr) {
	if(stackPtr->size == 0) {
		return -1;
	}
	int data = stackPtr->data[stackPtr->size-1];
	stackPtr->size--;
	return data;
}

void Grow(STACK *stackPtr) {
	stackPtr->data = realloc(stackPtr->data, sizeof(int) * stackPtr->capacity);
	stackPtr->capacity += stackPtr->capacity;
}
