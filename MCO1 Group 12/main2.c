/*
    Description : serves as the main file for reading a set of points from a text file, computing
                  their convex hull using the Graham scan algorithm with quicksort, and writing
                  the results to a destination file
    Programmer  : Adrian Dee, Althea dela Cruz, Camille Samonte
    Code Tester : Adrian Dee, Althea dela Cruz, Camille Samonte
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main_helper.h"
#include "graham_helper.h"
#include "stack.h"
#include "sort.h"

/*
	Purpose: extract the number and list of points from the source file for finding the convex hull 
	Returns: pointer to an array of the Point struct which represents a list of points with x and y coordinates 
	@param : filename of the source text file where the number and list of points will be extracted
	@param : pointer to an integer for holding the number of points in the file
	Pre-condition: filename must refer to a valid and existing text file
                   file must start with an integer (number of points), followed by that many lines, each containing two floating-point numbers (the x and y coordinates).
*/					
Point* getPoints(strFilename filename, int *numPoints)
{
    FILE* input;
    Point* pointList; 

    if ((input = fopen(filename, "r")) != NULL) {
        fscanf(input, "%d", numPoints); 
        
        // allocate memory for points
        pointList = (Point*)malloc(*numPoints * sizeof(Point));
        
        int i;
        for(i = 0; i < *numPoints; i++) {
            fscanf(input, "%lf %lf", &pointList[i].x, &pointList[i].y); 
        }
        fclose(input); 
    } else {
        printf("Error: %s not found", filename);
        exit(1); 
    }

    return pointList;
}

int main() {
    clock_t the_start; // start time 
    clock_t the_end;   // end time

    Point *pointList = NULL; 
    int numPoints, convexHullPoints = 2;
    strFilename source_filename, dest_filename;
    Stack stack; 

    printf("Enter source filename: ");
    scanf("%s", source_filename);

    printf("Enter destination filename: ");
    scanf("%s", dest_filename);

    the_start = clock();  // record the start time 

    pointList = getPoints(source_filename, &numPoints); 
    grahamScanFast(&stack, pointList, numPoints, &convexHullPoints);

    the_end = clock();

    printConvexHullPoints(dest_filename, convexHullPoints, stack);

    printf("%6d %15lf\n", numPoints, (double)(the_end - the_start));  

    free(pointList);

    return 0;
}