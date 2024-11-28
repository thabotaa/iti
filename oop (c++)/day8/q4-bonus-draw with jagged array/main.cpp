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

class Shape
{
protected:
    int shapecolor;

public:
    Shape()
    {
        shapecolor = 15; // white
        cout << "I'm shape ctor param-less" << endl;
    }
    Shape(int c)
    {
        shapecolor = c;
        cout << "I'm shape ctor 1 param" << endl;
    }
    void setcol(int c)
    {
        shapecolor = c;
    }

    virtual void draw() = 0;
};

class Line : public Shape
{
    Point Start;
    Point End;

public:
    Line(int n1, int n2, int n3, int n4, int c) : Start(n1, n2), End(n3, n4)
    {
        shapecolor = c;

        cout << "This is the CTOR of Line class 4 param" << endl;
    }
    void setclolor(int c)
    {
        shapecolor = c;
    }

    void draw()
    {
        setcolor(shapecolor);
        line(Start.getX(), Start.getY(), End.getX(), End.getY());
    }
};

class Circle : public Shape
{
private:
    Point center;
    int radius;

public:
    Circle(Point C, int r, int c) : center(C), radius(r)
    {
        shapecolor = c;
        cout << "This is the Para CTOR of Circle class" << endl;
    }
    Circle(int c1, int c2, int r, int c) : center(c1, c2), radius(r)
    {
        shapecolor = c;
        cout << "This is the Para CTOR of Circle class" << endl;
    }

    ~Circle()
    {
        cout << "This is the DTOR of Circle class" << endl;
    }

    void draw()
    {
        setcolor(shapecolor);
        circle(center.getX(), center.getY(), radius);
    }
};

class Rect : public Shape
{
private:
    Point topLeft;
    Point bottomRight;

public:
    Rect(Point tl, Point br, int c) : topLeft(tl), bottomRight(br)
    {
        shapecolor = c;
        cout << "This is the Para CTOR of Rect class" << endl;
    }
    Rect(int n1, int n2, int n3, int n4, int c) : topLeft(n1, n2), bottomRight(n3, n4)
    {
        shapecolor = c;
        cout << "This is the Para CTOR of Rect class" << endl;
    }

    ~Rect()
    {
        cout << "This is the DTOR of Rect class" << endl;
    }

    void draw()
    {
        setcolor(shapecolor);
        rectangle(topLeft.getX(), topLeft.getY(), bottomRight.getX(), bottomRight.getY());
    }
};

class picture
{
    Shape** pshapes;
    int shnum;

public:
    picture()
    {
        shnum = 0;
        pshapes = NULL;
    }
    picture(int n, Shape** shptr)
    {
        shnum = n;
        pshapes = shptr;
    }
    void setshapes(int n, Shape** shptr)
    {
        shnum = n;
        pshapes = shptr;
    }

    void paint()
    {
        for (int i = 0; i < shnum; i++)
        {
            pshapes[i]->draw();
        }
    }
};
/*
float sumofareas(shape* arr[], int Size)
{
    float sum = 0;
    for (int i = 0; i < Size; i++)
        sum += arr[i]->calcare;
}
*/
int main()
{
    cout << "heyyyyyyy" << endl;
    initwindow(700, 700);

     Rect R(340, 370, 360, 420,1);
      Line L[2]={Line(300, 450, 400, 450,2),Line(50,70,95,100,3)};
     Circle carr[3]={Circle(350, 350, 200,3),Circle(300, 300, 30,4),Circle(400, 300, 30,5)};
     Shape* shapearr[6];
     shapearr[0]=&R;
     shapearr[1]=L;
     shapearr[2]=(L+1);
     shapearr[3]=carr;
     shapearr[4]=(carr+1);
     shapearr[5]=(carr+2);

    picture p1;
    p1.setshapes(6, shapearr);
    p1.paint();

    getch();
    closegraph();

    return 0;
}
