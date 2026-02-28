/*
    Description : provide the function prototypes for the functions required for the sorting algorithms
    Programmer  : Althea dela Cruz
    Code Tester : Adrian Dee, Althea dela Cruz, Camille Samonte
*/

#ifndef SORT_H
#define SORT_H

#include "main_helper.h"

void swap(Point *point1, Point *point2);
double getDistanceFromAnchorPoint(Point point1, Point point2);
int partition(Point pointList[], int low, int high);
void quickSort(Point pointList[], int low, int high);
void bubbleSort(Point pointList[], int numPoints, Point anchorPoint);

#endif