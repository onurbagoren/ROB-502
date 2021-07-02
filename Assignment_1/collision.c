#include <stdio.h>
#include <math.h>

#define M_PI 3.14150265358979323846

/*
 * x   y   rot n_points x0  x1  x2  x3  y0  y1  y2  y3
 * 0.0 0.0 0.0 4        0.0 0.0 1.0 1.0 0.0 1.0 1.0 0.0
 * 1.0 0.0 0.0 4        0.0 0.0 1.0 1.0 0.0 1.0 1.0 0.0
 *|global |
 *|  pos  |
 *|cc rotation|
 *
 * First line can be ignored
 *
 * rotation happens, then translation
 * n_points: the number of x and y values to read in
 *
 * Instructions:
 *  - if the read file is invalid, return with an error code of 1
 *  - Output the points of the two polygons, one on each line, after
 *    they have been rotated and translated
 *  - Then, your program will print a statement for each pair of lines, specifying those lines and
 *    whether there was an intersection or not.
 *  - You will also print a statement about whether either polygon contains the other. (No statement
 *    if they are not contained)
 *  - Finally, your program will either output collision! or no collision
 */

int main( int argc, char **argv)
{



    return 0;
}
