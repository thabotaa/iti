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

class Line
{
private:
    Point Start;
    Point End;

public:
    Line(int n1, int n2, int n3, int n4) : Start(n1, n2), End(n3, n4)
    {
        cout << "This is the CTOR of Line class 4 param" << endl;
    }

    void draw()
    {
        line(Start.getX(), Start.getY(), End.getX(), End.getY());
    }
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
    Rect(int n1, int n2, int n3, int n4) : topLeft(n1, n2), bottomRight(n3, n4)
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

class Picture
{
private:
    int cnum, rnum, lnum;
    Circle* pcircle;
    Rect* prect;
    Line* pline;

public:
    Picture()
    {
        cnum = rnum = lnum = 0;
        pcircle = NULL;
        prect = NULL;
        pline = NULL;
    }

    Picture(int n1, int n2, int n3, Circle* C, Rect* R, Line* L)
    {
        cnum = n1;
        rnum = n2;
        lnum = n3;
        pcircle = C;
        prect = R;
        pline = L;
    }

    void setCircle(int n1, Circle* C)
    {
        cnum = n1;
        pcircle = C;
    }

    void setRect(int n2, Rect* R)
    {
        rnum = n2;
        prect = R;
    }

    void setLine(int n3, Line* L)
    {
        lnum = n3;
        pline = L;
    }

    void paint()
    {
        for (int i = 0; i < cnum; i++)
        {
            pcircle[i].draw();
        }

        for (int i = 0; i < rnum; i++)
        {
            prect[i].draw();
        }

        for (int i = 0; i < lnum; i++)
        {
            pline[i].draw();
        }
    }
};

int main()
{
    initwindow(700, 700);

    Picture p1;

    // Head
    Circle head(350, 200, 30);

    // Body
    Rect body(340, 230, 360, 330);

    // Arms
    Line leftArm(340, 240, 280, 290);
    Line rightArm(360, 240, 420, 290);

    // Legs
    Line leftLeg(350, 330, 320, 380);
    Line rightLeg(350, 330, 380, 380);

    // Lights
    Circle light1(280, 290, 10);
    Circle light2(420, 290, 10);
    Circle light3(320, 380, 10);
    Circle light4(380, 380, 10);

    Circle carr[] = {head, light1, light2, light3, light4};
    Rect rarr[] = {body};
    Line larr[] = {leftArm, rightArm, leftLeg, rightLeg};

    p1.setCircle(5, carr);
    p1.setRect(1, rarr);
    p1.setLine(4, larr);

    p1.paint();

    getch();
    closegraph();
    return 0;
}
