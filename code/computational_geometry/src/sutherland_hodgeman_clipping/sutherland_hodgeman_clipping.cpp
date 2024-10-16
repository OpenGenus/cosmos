//
//  main.cpp
//  forfun
//
//  Created by Ivan Reinaldo Liyanto on 10/5/17.
//  Copyright © 2017 Ivan Reinaldo Liyanto. All rights reserved.
//  Path of Cosmos by OpenGenus Foundation

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


struct coor2d
{
    float x, y;
    coor2d(float a, float b) : x(a), y(b)
    {
    }
    coor2d()
    {
    }
};

struct edge
{
    float x1, y1, x2, y2;
    float xnormal, ynormal;
    edge(float x1, float y1, float x2, float y2) : x1(x1), y1(y1), x2(x2), y2(y2)
    {
        float dx = x2 - x1;
        float dy = y2 - y1;
        xnormal = -dy;
        ynormal = dx;
    }
};

struct polygon
{
    vector<coor2d> points;

    polygon(const vector<coor2d> &p)
    {
        for (size_t i = 0; i < p.size(); i++)
            points.push_back(p[i]);
    }

};

bool inside(coor2d input, edge clipedge);
coor2d ComputeIntersection(coor2d a, coor2d b, edge c);



/*
 * 100
 *
 * y
 *
 * 0     x     100
 */
int main()
{
    //since there's normal computing involved, polygon points must be defined in clockwise manner
    vector<coor2d> clipperCoords;
    //example set 1
    clipperCoords.push_back(coor2d(2, 5));
    clipperCoords.push_back(coor2d(5, 5));
    clipperCoords.push_back(coor2d(5, 1));
    clipperCoords.push_back(coor2d(2, 1));

//    example set 2
//    clipperCoords.push_back(coor2d(5,10));
//    clipperCoords.push_back(coor2d(10,1));
//    clipperCoords.push_back(coor2d(0,1));

    vector<coor2d> clippedCoords;
    // example set 1
    clippedCoords.push_back(coor2d(2, 7));
    clippedCoords.push_back(coor2d(3, 7));
    clippedCoords.push_back(coor2d(3, 3));
    clippedCoords.push_back(coor2d(2, 3));

//    example set 2
//    clippedCoords.push_back(coor2d(5,5));
//    clippedCoords.push_back(coor2d(15,7));
//    clippedCoords.push_back(coor2d(13,1));


    polygon clipper = polygon(clipperCoords);
    polygon clipped = polygon(clippedCoords);

    vector<coor2d> outputCoords;
    vector<coor2d> inputList;
    outputCoords = clipped.points;
    for (size_t i = 0; i < clipper.points.size() - 1; i++)
    {
        inputList = outputCoords;
        outputCoords.clear();
        coor2d a = clipper.points[i];
        coor2d b = clipper.points[i + 1];
        edge clipedge = edge(a.x, a.y, b.x, b.y);
        coor2d s = inputList[inputList.size() - 1];
        for (size_t j = 0; j < inputList.size(); j++)
        {
            if (inside(inputList[j], clipedge))
            {
                if (!inside(s, clipedge))
                    outputCoords.push_back(ComputeIntersection(inputList[j], s, clipedge));
                outputCoords.push_back(inputList[j]);
            }
            else if (inside(s, clipedge))
                outputCoords.push_back(ComputeIntersection(inputList[j], s, clipedge));
            s = inputList[j];
        }
    }

    cout << "Clipped area: " << endl;
    for (size_t i = 0; i < outputCoords.size(); i++)
        cout << "X: " << outputCoords[i].x << " Y: " << outputCoords[i].y << endl;
    return 0;
}

bool inside(coor2d input, edge clipedge)
{
    coor2d a = coor2d(input.x - clipedge.x1, input.y - clipedge.y1);
    float dot = a.x * clipedge.xnormal + a.y * clipedge.ynormal;
    if (dot <= 0)
        return true;
    return false;
}


coor2d ComputeIntersection(coor2d ca, coor2d cb, edge edg)
{
    float x1 = ca.x;
    float x2 = cb.x;
    float x3 = edg.x1;
    float x4 = edg.x2;
    float y1 = ca.y;
    float y2 = cb.y;
    float y3 = edg.y1;
    float y4 = edg.y2;

    float x12 = x1 - x2;
    float x34 = x3 - x4;
    float y12 = y1 - y2;
    float y34 = y3 - y4;

    float c = x12 * y34 - y12 * x34;


    float a = x1 * y2 - y1 * x2;
    float b = x3 * y4 - y3 * x4;

    float x = (a * x34 - b * x12) / c;
    float y = (a * y34 - b * y12) / c;
    return coor2d(x, y);

}
