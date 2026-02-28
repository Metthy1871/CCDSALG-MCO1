/*
    Description : provides the implementation of the Graham scan algorithm using a fast sorting algorithm (quicksort)
    Programmer  : Adrian Dee, Althea dela Cruz, Camille Samonte
    Code Tester : Adrian Dee, Althea dela Cruz, Camille Samonte
*/
#include "sort.h"
#include "stack.h"
#include "graham_helper.h"

void grahamScanFast(Stack *stack, Point *pointList, int numPoints, int *convexHullPoints)
{
    // create stack with capacity equal to number of points
    create(stack, numPoints);

    int i;
    
    // find the anchor point
    findAnchorPoint(pointList, numPoints); 
    // calculate the polar angle of all points relative to the anchor point
    calculatePolarAngle(pointList + 1, numPoints - 1, pointList[0]); 
    // sort the points (excluding the anchor point) by angle in increasing order
    quickSort(pointList, 1, numPoints - 1);

    push(stack, pointList[0]); // anchor point is pushed to the stack (point 0)
    push(stack, pointList[1]); // point 1 is pushed to the stack 
    
    /*
        three points are needed to check for the orientation so we start at index 2 (point 3)
    */
    i = 2; 
    int orientation;
    // i represents the current point being evaluated
    while (i < numPoints) {
        if (stack->top < 3) { // if stack contains less than 3 points, push current point to stack
            push(stack, pointList[i]); 
            i++; 
            (*convexHullPoints)++;
        } else { // checks the orientation of the angle formed between three consecutive points
            orientation = getOrientation(nextToTop(*stack), top(*stack), pointList[i]); 
               
            if (orientation != 1) { // orientation is not counter clockwise
                // if (stack.top >= 3) { // if the number of points in the stack is at least 3
                    pop(stack); // the point before the current point being evaluated will be popped off
                    (*convexHullPoints)--;
                /*} else { // if there is not enough points in the stack to form an angle, push current point to the stack
                    push(stack, pointList[i]); 
                    i++;
                    convexHullPoints++;
                }*/
            } else { // if orientation is counterclockwise, push point to the stack
                push(stack, pointList[i]); 
                i++; 
                (*convexHullPoints)++;
            }
        }
    }
}