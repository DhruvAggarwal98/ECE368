#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "adjacent.h"

void make_points(FILE * fp, Point * points, long count) {
    long x;
    long i;
    for(i = 0; i < count; i++) {
        fscanf(fp, "%ld %ld %ld", &x, &(points[i].x_coord), &(points[i].y_coord));
    }
}

void make_edges(FILE *fp, long * matrix, long count, long nodes) {
    long point1;
    long point2;
    long i;
    for(i = 0; i < count; i++) {
        fscanf(fp, "%ld %ld", &point1, &point2);
        adjacency(matrix, point1, point2, nodes);
        adjacency(matrix, point2, point1, nodes);
    }
}

void adjacency(long* matrix, long begin, long end, long nodes) {
    long long int index = begin * nodes + end;
    matrix[index] = 1;
}
