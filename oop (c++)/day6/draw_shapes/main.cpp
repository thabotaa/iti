#include <iostream>
#include <graphics.h>

using namespace std;

class Point
{
private:
    int x, y;

public:
    Point()
    {
        x = y = 0;
        cout << "This is the CTOR of Point class 0 param" << endl;
    }

    Point(int n)
    {
        x = y = n;
        cout << "This is the Para CTOR of Point class 1 input" << endl;
    }

    Point(int n1, int n2)
    {
        x = n1;
        y = n2;
        cout << "This is the Para CTOR of Point class 2 input" << endl;
    }

    void setX(int d1) { x = d1; }
    void setY(int d2) { y = d2; }

    int getX() { return x; }
    int getY() { return y; }
};

class Circle
{
private:
    Point center;
    int radius;

public:
    Circle(Point c, int r) : center(c), radius(r)
    {
        cout << "This is the Para CTOR of Circle class" << endl;
    }
    Circle(int c1, int c2, int r) : center(c1, c2), radius(r)
    {
        cout << "This is the Para CTOR of Circle class" << endl;
    }

    ~Circle()
    {
        cout << "This is the DTOR of Circle class" << endl;
    }

    void draw()
    {
        circle(center.getX(), center.getY(), radius);
    }
};

class Rect
{
private:
    Point topLeft;
    Point bottomRight;

public:
    Rect(Point tl, Point br) : topLeft(tl), bottomRight(br)
    {
        cout << "This is the Para CTOR of Rect class" << endl;
    }
    Rect(int nl, int n2, int n3, int n4) : topLeft(nl, n2), bottomRight(n3, n4)
    {
        cout << "This is the Para CTOR of Rect class" << endl;
    }

    ~Rect()
    {
        cout << "This is the DTOR of Rect class" << endl;
    }

    void draw()
    {
        rectangle(topLeft.getX(), topLeft.getY(), bottomRight.getX(), bottomRight.getY());
    }
};

class Square
{
private:
    Point topLeft;
    Point bottomRight;

public:
    Square(Point tl, Point br) : topLeft(tl), bottomRight(br)
    {
        cout << "This is the Para CTOR of Square class" << endl;
    }
    Square(int n1, int n2, int n3, int n4) : topLeft(n1, n2), bottomRight(n3, n4)
    {
        cout << "This is the Para CTOR of Square class" << endl;
    }

    ~Square()
    {
        cout << "This is the DTOR of Square class" << endl;
    }

    void draw()
    {
        rectangle(topLeft.getX(), topLeft.getY(), bottomRight.getX(), bottomRight.getY());
    }
};

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    setcolor(RED);
    Rect r(100, 100, 200, 150);
    r.draw();

    setcolor(GREEN);
    Square sq(300, 300, 360, 360);
    sq.draw();

    setcolor(BLUE);
    Circle circ(400, 400, 40);
    circ.draw();

    getch();

    closegraph();
    return 0;
}
