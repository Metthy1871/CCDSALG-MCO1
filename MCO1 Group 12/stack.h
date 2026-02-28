/*
    Description : provide the type definition for the Stack struct and the function declarations for stack operations 
    Programmer  : Althea dela Cruz
    Code Tester : Adrian Dee, Althea dela Cruz, Camille Samonte
*/

#ifndef STACK_H
#define STACK_H

#include <stdbool.h> 
#include "main_helper.h"

struct StackData {
    int top; // indicates the current number of elements in the stack
    int capacity; // the maximum number of elements the stack can currently hold
    Point *points; // array of points pushed in the stack to represent the points of the convex hull
}; 
typedef struct StackData Stack; 

void create(Stack *stack, int capacity);
bool isFull(Stack stack);
void push(Stack *stack, Point elem);
bool isEmpty(Stack stack);
void pop(Stack *stack);
Point top(Stack stack);
Point nextToTop(Stack stack);

#endif