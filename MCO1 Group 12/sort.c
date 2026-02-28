/*
    Description : provides the implementations of the functions required for the sorting algorithms
    Programmer  : Adrian Dee, Althea dela Cruz, Camille Samonte
    Code Tester : Adrian Dee, Althea dela Cruz, Camille Samonte
*/
#include <stdio.h>
#include <math.h>
#include "sort.h"

/*
	Purpose: swaps the position of two points
	Returns: none
	@param : pointer to a Point struct representing the first point
	@param : pointer to a Point struct representing the second point
    Precondition: point1 and point2 must be valid pointers to Point structs
*/
void swap(Point *point1, Point *point2)
{
    Point temp;
    temp = *point1;
    *point1 = *point2; 
    *point2 = temp; 
}

/*
	Purpose: calculate the distance from an anchor point when a point's polar angle is equal to another point's
	Returns: the Euclidean distance between point1 (anchor) and point2
	@param : Point struct representing the first point (anchor point)
	@param : Point struct representing the second point
    Precondition: point1 and point2 must be valid Point structs
*/
double getDistanceFromAnchorPoint(Point point1, Point point2)
{
    double deltaX = point2.x - point1.x;
    double deltaY = point2.y - point1.y; 
    double distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2)); 
    return distance; 
}

/*
    Purpose: partitions the array of points for quicksort based on polar angle and distance from the anchor point
    Returns: the partition index
    @param : array of Point structs to be partitioned
    @param : low index for the partition
    @param : high index for the partition
    Pre-condition: pointList must point to a valid array of at least (high + 1) Point structs; low and high must be valid indices within the array
*/
int partition(Point pointList[], int low, int high)
{
    int i, j; 
    double pivotDistance; 
    Point pivot = pointList[high]; 
    Point anchorPoint = pointList[0]; 

    i = low - 1;
    pivotDistance = getDistanceFromAnchorPoint(anchorPoint, pivot); 
    for (j = low; j < high; j++) {
        if (pointList[j].polarAngle < pivot.polarAngle) {
            i++; 
            swap(&pointList[i], &pointList[j]); 
        } else if (pointList[j].polarAngle == pivot.polarAngle) { // points are collinear
            // prioritize the point that is farther from the anchor point
            if (getDistanceFromAnchorPoint(anchorPoint, pointList[j]) > pivotDistance) {
                i++; 
                swap(&pointList[i], &pointList[j]); 
            }   
        }
    }
    // move the pivot after smaller elements
    swap(&pointList[i + 1], &pointList[high]);
    return i + 1; 
}

/*
    Purpose: sorts an array of points by polar angle (and distance from anchor if angles are equal) using quicksort
    Returns: none
    @param : array of Point structs to be sorted
    @param : low index for the sort
    @param : high index for the sort
    Pre-condition: pointList must point to a valid array of at least (high + 1) Point structs; low and high must be valid indices within the array
*/
void quickSort(Point pointList[], int low, int high)
{
    if (low < high) {
        int pi = partition(pointList, low, high); 
        
        quickSort(pointList, low, pi - 1);
        quickSort(pointList, pi + 1, high); 
    } 
}

/*
    Purpose: sorts an array of points by polar angle (and distance from anchor if angles are equal) using bubble sort
    Returns: none
    @param : array of Point structs to be sorted
    @param : number of points in the array
    @param : anchor point to use for distance comparison
    Pre-condition: pointList must point to a valid array of at least numPoints Point structs; numPoints > 0
*/
void bubbleSort(Point pointList[], int numPoints, Point anchorPoint)
{
    int i, j;
    for (i = 0; i < numPoints; i++) {
        for (j = numPoints - 1; j > i; j--) {
            if (pointList[j].polarAngle < pointList[j - 1].polarAngle) {
                swap(&pointList[j], &pointList[j - 1]);
            } else if (pointList[j].polarAngle == pointList[j - 1].polarAngle) { // two points have equal polar angles
                // prioritize the point that is farther from the anchor point
                if (getDistanceFromAnchorPoint(pointList[j], anchorPoint) > getDistanceFromAnchorPoint(pointList[j - 1], anchorPoint)) {
                    swap(&pointList[j], &pointList[j - 1]);
                }
            }
        }
    }
}
