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
 Point Start;
 Point End;

public:
    Line(int n1 ,int n2 ,int n3 ,int n4) :Start(n1,n2) ,End(n3,n4)
    {

        cout << "This is the CTOR of Line class 4 param" << endl;
    }


    void draw()
    {
        line(Start.getX(), Start.getY(), End.getX(),End.getY());
        setcolor(BLUE);
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
        setcolor(YELLOW);
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
         setcolor(RED);
    }
};
/*
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
*/
class picture
{
    int cnum,rnum,lnum;
    Circle* pcircle;
    Rect* prect;
    Line* pline;
public:

    picture()
    {
       cnum=rnum=lnum=0 ;
       pcircle=NULL;
       prect=NULL;
       pline=NULL;

    }
    picture(int n1,int n2,int n3,Circle* C,Rect* R,Line* L)
    {
        cnum=n1;
        rnum=n2;
        lnum=n3;
        pcircle=C;
        prect=R;
        pline=L;
    }
     void   setcircle(int n1,Circle* C)
     {
         cnum=n1;
         pcircle=C;
     }
       void   setrect(int n2,Rect* R)
     {
         rnum=n2;
         prect=R;
     }
      void   setline(int n3,Line* L)
     {
         lnum=n3;
         pline=L;
     }
    void  paint()
    {
      for (int i = 0; i < cnum; i++)
      {
          pcircle[i].draw();
      }
       for (int j = 0; j < rnum; j++)
      {
          prect[j].draw();
      }
       for (int m = 0; m < lnum; m++)
      {
          pline[m].draw();
      }

    }

};

int main()
{
    cout<<"heyyyyyyy";
    initwindow(700, 700);

    picture p1;
   // p1.paint();



    Circle carr[3]={Circle(350, 350, 200),Circle(300, 300, 30),Circle(400, 300, 30)};
    p1.setcircle(3,carr);
    p1.paint();



    Rect R(340, 370, 360, 420);
    p1.setrect(1,&R);
    p1.paint();



    Line L[2]={Line(300, 450, 400, 450),Line(50,70,95,100)};
    p1.setline(2,L);
    p1.paint();


    getch();
    closegraph();

    return 0;
}
