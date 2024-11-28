#include <iostream>

using namespace std;

class geoshape
{
    protected:
    int dim1,dim2;

    public:
        geoshape()            ///costruct
        {
            dim1=dim2=0;
            cout<<"i'm geoshape cotr 0 param\n";
        }
         geoshape(int x)         ///costruct
        {
            dim1=dim2=x;
            cout<<"i'm geoshape cotr 1 param\n";
        }
         geoshape(int x,int y)    ///costruct
        {
            dim1=x;
            dim2=y;
            cout<<"i'm geoshape cotr 2 param\n";
        }
        ~ geoshape()         ///decostruct
        {

            cout<<"i'm geoshape decotr \n";
        }
        void setdim1(int n)
        {
            dim1=n;
        }
        void setdim2(int n)
        {
            dim2=n;
        }
        int getdim1()
        {
            return dim1;
        }
         int getdim2()
        {
            return dim2;
        }
        float area()
        {
            cout<<"error this geo area\n";
            return -1;
        }

};

class square :protected geoshape
{
public:
      square()            ///costruct
        {
            dim1=dim2=0;
            cout<<"i'm square cotr 0 param\n";
        }
         square(int x)         ///costruct
        {
            dim1=dim2=x;
            cout<<"i'm square cotr 1 param\n";
        }
         ~ square()         ///decostruct
        {

            cout<<"i'm square decotr \n";
        }
        void setdims(int n)
        {
            dim1=dim2=n;
        }
        float Area()
        {
            return dim1*dim2;
        }
};
class rect :public geoshape
{
public:
      rect()            ///costruct
        {
            dim1=dim2=0;
            cout<<"i'm rect cotr 0 param\n";
        }
         rect(int x)         ///costruct
        {
            dim1=dim2=x;
            cout<<"i'm rect cotr 1 param\n";
        }
          rect(int x,int y)    ///costruct
        {
            dim1=x;
            dim2=y;
            cout<<"i'm rect cotr 2 param\n";
        }
         ~ rect()         ///decostruct
        {

            cout<<"i'm rect decotr \n";
        }
        float area()
        {
            return dim1*dim2;
        }
};
class tri :public geoshape
{
public:
      tri()            ///costruct
        {
            dim1=dim2=0;
            cout<<"i'm tri cotr 0 param\n";
        }
         tri(int x)         ///costruct
        {
            dim1=dim2=x;
            cout<<"i'm tri cotr 1 param\n";
        }
          tri(int x,int y)    ///costruct
        {
            dim1=x;
            dim2=y;
            cout<<"i'm tri cotr 2 param\n";
        }
         ~ tri()         ///decostruct
        {

            cout<<"i'm tri decotr \n";
        }
        float area()
        {
            return 0.5*dim1*dim2;
        }
};
class circ :protected geoshape
{
public:
      circ()            ///costruct
        {
            dim1=dim2=0;
            cout<<"i'm circ cotr 0 param\n";
        }
         circ(int x)         ///costruct
        {
            dim1=dim2=x;
            cout<<"i'm circ cotr 1 param\n";
        }
          circ(int x,int y)    ///costruct
        {
            dim1=x;
            dim2=y;
            cout<<"i'm circ cotr 2 param\n";
        }
         ~ circ()         ///decostruct
        {

            cout<<"i'm circ decotr \n";
        }
         void setdims(int n)
        {
            dim1=dim2=n;
        }
        float area()
        {
            return 3.14*dim1*dim2;
        }
};




int main()
{
  /*  geoshape g;
    g.setdim1(2);
    g.setdim2(3);
    cout <<"the area is =="<<g.area()<<"\n";
    square sq;
     sq.setdims(4);
     cout <<"the area square is ="<<sq.Area()<<"\n";
     */
     rect r(5);
     r.setdim2(6);
    cout <<"the area of rect is ="<<r.area()<<"\n";
    tri t(6,8);
  //   t.setdim1(6);
  //   t.setdim2(8);
/*     cout <<"the area of tri is ="<<t.area()<<"\n";
     circ c(4);
      cout <<"the area of circ is ="<<c.area()<<"\n";


*/
    return 0;
}
