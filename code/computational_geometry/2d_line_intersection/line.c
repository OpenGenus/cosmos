//  computational geometry | 2D line intersecton | C
//  Part of Cosmos by OpenGenus Foundation

//  main.c
//  forfun
//
//  Created by Daniel Farley on 10/10/17.
//  Copyright © 2017 Daniel Farley. All rights reserved.

#include <stdio.h>
#include <stdlib.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

typedef struct{
    double x;
    double y;
} vec2;

/* return point of intersection, in parent's coordinate space of its parameters */
vec2 fintersection(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
    double x12 = x1 - x2;
    double x34 = x3 - x4;
    double y12 = y1 - y2;
    double y34 = y3 - y4;
    
    double c = x12 * y34 - y12 * x34;
    
    double a = x1 * y2 - y1 * x2;
    double b = x3 * y4 - y3 * x4;
    
    double x = (a * x34 - b * x12) / c;
    double y = (a * y34 - b * y12) / c;
    
    vec2 ret;
    ret.x = x;
    ret.y = y;
    return ret;
}

/* line segments defined by 2 points a-b, and c-d */
vec2 intersection(vec2 a, vec2 b, vec2 c, vec2 d){
    return fintersection(a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y);
}

int main() {
    //example set 1
    vec2 a; a.x=10; a.y=3;
    vec2 b; b.x=20; b.y=10;
    vec2 c; c.x=10; c.y=10;
    vec2 d; d.x=20; d.y=3;
    
    vec2 intersectionpoint = intersection(a,b,c,d);
    if(intersectionpoint.x >= min(a.x, b.x) && intersectionpoint.x <= max(a.x, b.x) &&
       intersectionpoint.y >= min(a.y, b.y) && intersectionpoint.y <= max(a.y, b.y)){
        printf("intersection: %f %f", intersectionpoint.x, intersectionpoint.y);
    } else {
        printf("no intersection");
    }
    return 0;
}

