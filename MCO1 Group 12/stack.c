/*
    Description : provides the implementations of the stack operations for the Graham scan algorithm
    Programmer  : Adrian Dee, Althea dela Cruz, Camille Samonte
    Code Tester : Adrian Dee, Althea dela Cruz, Camille Samonte
*/
#include <stdlib.h>
#include <stdio.h> 
#include "main_helper.h"
#include "stack.h"

/*
	Purpose: create the stack to store the set of points forming a convex hull
	Returns: none
	@param : pointer to a Stack struct representing stack
	@param : integer representing the initial capacity of the stack
    Precondition: stack must be a valid pointer
                  capacity must be greater than 0
*/
void create(Stack *stack, int capacity) 
{ 
    stack->top = 0; 
    stack->capacity = capacity;
    stack->points = (Point*)malloc(capacity * sizeof(Point));
    if (stack->points == NULL) {
        printf("Memory allocation failed for stack\n");
        exit(1);
    }
}

/*
	Purpose: checks if the stack is full based on its capacity
	Returns: boolean value to indicate whether the stack is full or not
	@param : Stack struct representing the stack
    Precondition: stack must be a valid Stack struct that has been properly initialized
*/
bool isFull(Stack stack) {
    bool isFull = false;
    if (stack.top == stack.capacity)
        isFull = true;
    return isFull; 
}

/*
	Purpose: pushes a point to the stack representing the points of a convex hull as long as the stack is not full
	Returns: none
	@param : pointer to a Stack struct representing stack
    @param : elem is a Point struct representing the point to be pushed to the stack
    Precondition: stack must be a valid pointer to a Stack struct
*/
void push(Stack *stack, Point elem) 
{
    if (!isFull(*stack)) {
        int i = stack->top; 
        stack->points[i] = elem; 
        stack->top = stack->top + 1;  
    }
}

/*
	Purpose: checks if the stack is full based on its capacity
	Returns: boolean value to indicate whether the stack is full or not
	@param : Stack struct representing the stack
    Precondition: stack must be a valid Stack struct that has been properly initialized
*/
bool isEmpty(Stack stack) 
{
    bool isEmpty = false;
    if (stack.top == 0)
        isEmpty = true;
    return isEmpty; 
}

/*
    Purpose: pops off a point from the top of the stack when it doesn't meet the criteria for the convex hull
	Returns: none
	@param : pointer to the Stack struct representing the stack
    Precondition: stack must be a valid pointer to a Stack struct
 */
void pop(Stack *stack) 
{   
    if (!isEmpty(*stack)) { 
        stack->top = stack->top - 1;
    }
}

/*
    Purpose: returns the point at the top of the stack without removing it
	Returns: Point struct representing the top point; returns (0,0,0) if stack is empty
	@param : Stack struct representing the stack
    Precondition: stack must be a valid Stack struct that has been properly initialized
 */
Point top(Stack stack) {
    Point point;
    if (isEmpty(stack))
        point = (Point){0, 0, 0}; // error
    else 
        point = stack.points[stack.top-1]; // returns the point 
    
    return point;
}

/*
    Purpose: returns the point next to the top of the stack without removing it
    Returns: Point struct representing the next-to-top point; returns (0,0,0) if stack has fewer than 2 elements
    @param : Stack struct representing the stack
    Precondition: stack must be a valid Stack struct that has been properly initialized
 */
Point nextToTop(Stack stack)
{
    Point point;
    if (stack.top > 1)
        point = stack.points[stack.top-2]; // returns the index
    else
        point = (Point){0, 0, 0}; // error
    return point; 
}

