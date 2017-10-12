//Ivan Reinaldo Liyanto
// open genus - cosmos
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
struct vec2{
    float x, y;
    vec2(float x, float y):x(x), y(y){}
    friend vec2 operator+(vec2 lhs, const vec2& vec){
        return vec2(lhs.x + vec.x, lhs.y + vec.y);
    }
    friend vec2 operator-(vec2 lhs, const vec2& vec){
        return vec2(lhs.x - vec.x, lhs.y - vec.y);
    }
    
};

float dot(vec2 a, vec2 b){
    return a.x * b.x + a.y * b.y;
}

vector<vec2> inputPolygon1;
vector<vec2> inputPolygon2;

bool sat(){
    //project every points onto every axis
    for (int i = 1; i < inputPolygon1.size(); i++) {
        vec2 axis = inputPolygon1[i] - inputPolygon1[i-1];
        
        float leftMostPolygonA = __FLT_MAX__;
        float rightMostPolygonA = __FLT_MIN__;
        for (int j = 0; j < inputPolygon1.size(); j++) {
            float d = dot(inputPolygon1[j], axis);
            if(d > rightMostPolygonA)
                rightMostPolygonA = d;
            if(d < leftMostPolygonA)
                leftMostPolygonA = d;
        }
        
        float leftMostPolygonB = __FLT_MAX__;
        float rightMostPolygonB = __FLT_MIN__;
        for (int j = 0; j < inputPolygon2.size(); j++) {
            float d = dot(inputPolygon2[j], axis);
            if(d > rightMostPolygonB)
                rightMostPolygonB = d;
            if(d < leftMostPolygonB)
                leftMostPolygonB = d;
        }
        
        if((leftMostPolygonB < rightMostPolygonA && rightMostPolygonB > rightMostPolygonA) ||
           (leftMostPolygonA < rightMostPolygonB && rightMostPolygonA > rightMostPolygonB) )
            return true;
    }
    
    
    //false = no intersection
    return false;
}

int main(){
    //given 2 convex polygons defined by set of points, determine if the two polygon intersects using Separating Axis Test
    //example set 1
    inputPolygon1.push_back(vec2(5, 5));
    inputPolygon1.push_back(vec2(7, 10));
    inputPolygon1.push_back(vec2(15, 10));
    inputPolygon1.push_back(vec2(4, 4));

    inputPolygon2.push_back(vec2(6, 6));
    inputPolygon2.push_back(vec2(0, 0));
    inputPolygon2.push_back(vec2(7, 0));
    
    //example set 2
//        inputPolygon2.push_back(vec2(5, 5));
//        inputPolygon2.push_back(vec2(5, 10));
//        inputPolygon2.push_back(vec2(15, 10));
//        inputPolygon2.push_back(vec2(15, 5));
//
//        inputPolygon1.push_back(vec2(20, 5));
//        inputPolygon1.push_back(vec2(20, 10));
//        inputPolygon1.push_back(vec2(25, 10));
//        inputPolygon1.push_back(vec2(25, 5));
    
    cout << (sat() ? "intersects" : "not intersecting") << endl;
    
    return 0;
}
