#include <iostream>

class DDALineDrawingAlgorithm
{
public:
    void ddaLineDrawing();

    void getCoordinates();

private:
    int x1_, x2_, y1_, y2_;

};

void DDALineDrawingAlgorithm::ddaLineDrawing()
{
    //calculating range for line between start and end point
    int dx = x2_ - x1_;
    int dy = y2_ - y1_;
    // calculate steps required for creating pixels
    int step = abs(abs(dx) > abs(dy) ? dx : dy);
    // calculate increment in x & y for each steps
    float xIncrement = (dx) / (float)step;
    float yIncrement = (dy) / (float)step;
    // drawing  pixel for each step
    float x = x1_;
    float y = y1_;
    putpixel((x), (y),GREEN);   //this putpixel is for very first pixel of the line
    for(int i = 1; i <= step; ++i)
    {
        x = x + xIncrement;  // increment in x at each step
        y = y + yIncrement;  // increment in y at each step
        putpixel(round(x), round(y),GREEN);  // display pixel at coordinate (x, y)
        delay(200); //delay introduced for visualization at each step
    }
    delay(500);
}

void DDALineDrawingAlgorithm::getCoordinates()
{
    std::cout << "\nEnter the First Coordinate ";
    std::cout << "\nEnter X1 : ";
    std::cin >> x1_;
    std::cout << "\nEnter Y1 : ";
    std::cin >> y1_;
    std::cout << "\nEnter the Second Coordinate ";
    std::cout << "\nEnter X2 : ";
    std::cin >> x2_;
    std::cout << "\nEnter Y2 : ";
    std::cin >> y2_;
}

int main()
{
    DDALineDrawingAlgorithm d;
    d.getCoordinates();
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    d.ddaLineDrawing();
}
