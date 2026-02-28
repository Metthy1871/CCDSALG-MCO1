/*
    Description : header file for graham_helper.c providing function declarations for the
                  functions used in this source file
    Programmer  : Althea dela Cruz
    Code Tester : Adrian Dee, Althea dela Cruz, Camille Samonte
*/

#ifndef GRAHAM_HELPER_H
#define GRAHAM_HELPER_H

#include "main_helper.h"
#include "stack.h"

void findAnchorPoint(Point *pointList, int numPoints);
void calculatePolarAngle(Point *pointList, int numPoints, Point anchorPoint);
int getOrientation(Point a, Point b, Point c);
void printConvexHullPoints(strFilename filename, int convexHullPoints, Stack stack);
void grahamScanSlow(Stack *stack, Point *pointList, int numPoints, int *convexHullPoints);
void grahamScanFast(Stack *stack, Point *pointList, int numPoints, int *convexHullPoints);

#endif