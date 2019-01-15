#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long x_coord;
    long y_coord;
}Point;


void make_points(FILE *, Point *, long);
void make_edges(FILE *, long *, long, long);
void adjacency(long *, long, long , long );


