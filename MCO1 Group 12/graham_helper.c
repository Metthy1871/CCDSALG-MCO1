/*
    Description : provides the implementations of helper functions used in the Graham scan convex hull algorithm
                  including finding the anchor point, calculating the polar angle of each point, determining the orientation,
                  and printing the resulting convex hull points to a file
    Programmer  : Adrian Dee, Althea dela Cruz, Camille Samonte
    Code Tester : Adrian Dee, Althea dela Cruz, Camille Samonte
*/

#include <stdio.h>
#include <math.h>
#include "graham_helper.h"
#include "sort.h"

/*
	Purpose: find the anchor point in the array of points and ensure that is first element in the array 
	Returns: none 
	@param : pointer to an array of the Point struct which represents a list of points with x and y coordinates 
	@param : number of points in the array
	Pre-condition: numPoints must be greater than 0
                   pointList must point to a valid array of at least numPoints Point structs
*/					
void findAnchorPoint(Point *pointList, int numPoints)
{
    int i;
    int minIndex = 0; 

    Point min = pointList[0]; // assume that the first point has the lowest y-coordinate
    
    // select the point with the lowest y-coordinate
    // if the y-coordinates are equal, select the point with the lower x-coordinate value
    for (i = 1; i < numPoints; i++) {
        if (pointList[i].y < min.y || (pointList[i].y == min.y && pointList[i].x < min.x)) { 
            min = pointList[i];
            minIndex = i;
        }
    }
    // first element of the pointList will be the anchor point 
    if (minIndex != 0) {
        swap(&pointList[minIndex], &pointList[0]);
    }

}

/*
	Purpose: calculate the polar angle for each point (starting from the second element of the pointList array) with respect to the anchor pont
	Returns: none 
	@param : pointer to an array of the Point struct which represents a list of points with x and y coordinates 
	@param : number of points in the array
    @param : anchor point to be used as the reference for calculating the polar angle
	Pre-condition: numPoints must be greater than 0
                   anchorPoint is a valid Point
                   pointList must point to a valid array of at least numPoints Point structs
*/
void calculatePolarAngle(Point *pointList, int numPoints, Point anchorPoint) 
{
    int i;

    for (i = 0; i < numPoints; i++) {
        double deltaX = pointList[i].x - anchorPoint.x;
        double deltaY = pointList[i].y - anchorPoint.y;
        
        pointList[i].polarAngle = atan2(deltaY, deltaX); // considers division by zero and quadrant detection 
        /* so even if 2 points are from different quadrants, their arctan relative to the 
        anchor point could end up the same if atan() is used */ 
    }
}

/*
	Purpose: identify the orientation of the angle between three points
	Returns: an integer from -1 to 1 indicating the orientation of the angle (clockwise, collinear, counter-clockwise) 
	@param : Point struct representing the point that is the second topmost element in the stack of points for the convex hull
	@param : Point struct representing the point is the topmost element in the stack
    @param : Point struct representing the current point being evaluated before pushing to the stack
	Pre-condition: a, b, and c should be valid Point structs
*/
int getOrientation(Point a, Point b, Point c)
{
    // gets the orientation of the angle between three points
    double area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); 

    if (area < 0)
        return -1; // clockwise 
    if (area > 0)
        return 1; // counter-clockwise

    return 0; // collinear 
}

/*
	Purpose: print the number and list of points that form the convex hull given a set of points
	Returns: none
	@param : filename of the destination text file where the set of points forming the convex hull will be written
	@param : integer representing the number of points forming the convex hull
    @param : Stack struct representing the stack of points forming the convex hull
	Pre-condition: stack.points must point to a valid array of at least stack.top Point structs
*/
void printConvexHullPoints(strFilename filename, int convexHullPoints, Stack stack)
{
    int i;
    FILE* output; 
    output = fopen(filename, "w");
    fprintf(output, "%d\n", convexHullPoints); 
    for (i = 0; i < stack.top; i++) {
        fprintf(output, "%10.6lf %10.6lf\n", stack.points[i].x, stack.points[i].y);
    }
    fclose(output);
}