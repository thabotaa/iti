#include <iostream>

using namespace std;


void linear_search(int *arr,int Size,int & target)
{
    int index=-1;
     for(int i=0;i<Size;i++)
     {
         if(arr[i]==target)
         {
            index=i;
            cout<<"found target in index "<<index<<endl;
         }

     }
     if(index==-1)
     cout<<" target not found\n";

}


int main()
{

     int target=1;
    int arr[6]={3,4,5,6,6,8};
    linear_search(arr,6,target);
    return 0;
}
