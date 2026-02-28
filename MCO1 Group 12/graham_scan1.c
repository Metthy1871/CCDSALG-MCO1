/*
    Description : provides the implementation of the Graham scan algorithm using a slow sorting algorithm (bubble sort)
    Programmer  : Adrian Dee, Althea dela Cruz, Camille Samonte
    Code Tester : Adrian Dee, Althea dela Cruz, Camille Samonte
*/

#include "sort.h"
#include "stack.h"
#include "graham_helper.h"

/*
	Purpose: executes the graham scan algorithm to find the convex hull given a set of points using a slow sorting algorithm, specifically bubble sort
	Returns: none
	@param : pointer to a Stack struct representing the stack of points that form the convex hull
	@param : pointer to an array of the Point struct which represents a list of points with x and y coordinates 
	@param : number of points in the array
    @param : pointer to an integer representing the number of points that form the convex hull
	Pre-condition: stack must be a valid pointer to a Stack struct
                   pointList must point to a valid array of at least numPoints Point structs
                   numPoints must be greater than or equal to 3 (since a convex hull requires at least 3 points)
                   convexHullPoints must be a valid pointer to an integer.
*/
void grahamScanSlow(Stack *stack, Point *pointList, int numPoints, int *convexHullPoints)
{
    // create stack with capacity equal to number of points
    create(stack, numPoints);

    int i; 
    
    // find the anchor point
    findAnchorPoint(pointList, numPoints); 
    // calculate the polar angle of all points relative to the anchor point
    calculatePolarAngle(pointList + 1, numPoints - 1, pointList[0]); 
    // sort the points (excluding the anchor point) by angle in increasing order
    bubbleSort(pointList + 1, numPoints - 1, pointList[0]);

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
                    pop(stack); // the point before the current point being evaluated will be popped off
                    (*convexHullPoints)--;
            } else { // if orientation is counterclockwise, push point to the stack
                push(stack, pointList[i]); 
                i++; 
                (*convexHullPoints)++;
            }
        }
    }
}