//
//  main.c
//  forfun
//
//  Created by Daniel Farley on 10/10/17.
//  Copyright © 2017 Daniel Farley. All rights reserved.
//  Path of Cosmos by OpenGenus Foundation

#include <stdio.h>
#include <stdlib.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

typedef struct{
    float x;
    float y;
} vec2;

/* return point of intersection, in parent's coordinate space of its parameters */
vec2 fintersection(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4){
    float x12 = x1 - x2;
    float x34 = x3 - x4;
    float y12 = y1 - y2;
    float y34 = y3 - y4;
    
    float c = x12 * y34 - y12 * x34;
    
    float a = x1 * y2 - y1 * x2;
    float b = x3 * y4 - y3 * x4;
    
    float x = (a * x34 - b * x12) / c;
    float y = (a * y34 - b * y12) / c;
    
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
    
    //example set 2
    // vec2 a; a.x=10; a.y=3;
    // vec2 b; b.x=20; b.y=3;
    // vec2 c; c.x=10; c.y=5;
    // vec2 d; d.x=20; d.y=5;
    
    vec2 intersectionpoint = intersection(a,b,c,d);
    if(intersectionpoint.x >= min(a.x, b.x) && intersectionpoint.x <= max(a.x, b.x) &&
       intersectionpoint.y >= min(a.y, b.y) && intersectionpoint.y <= max(a.y, b.y)){
        printf("intersection: %f %f", intersectionpoint.x, intersectionpoint.y);
    }else
        printf("no intersection");
    
    return 0;
}

