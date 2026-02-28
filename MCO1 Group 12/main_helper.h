/*
    Description : header file providing type definitions and function declarations needed by the main program
                  and other source files
    Programmer  : Althea dela Cruz
    Code Tester : Adrian Dee, Althea dela Cruz, Camille Samonte
*/

#ifndef MAIN_HELPER_H
#define MAIN_HELPER_H

typedef char strFilename[41]; // alias for a string that represents the filename

struct PointData {
    double x; // x-coordinate
    double y; // y-coordinate
    double polarAngle; // polar angle with respect to the anchor point
};
typedef struct PointData Point; // Point is to be used as an alias for struct PointData

Point* getPoints(strFilename filename, int *numPoints);

#endif