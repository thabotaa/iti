#include <iostream>
using namespace std;


int binarySearch(int *arr,int Size,int target)
{
    int start=0,End=Size-1;
    while(start<=End){
    int mid=(start+End)/2;
    if(arr[mid]==target)
        return mid;
    else if(arr[mid]>target)
        End=mid-1;
    else
        start=mid+1;
    }
    return -1;
}



int main()
{

    int arr[6]={3,5,6,7,8,9};
    int result= binarySearch(arr,6,4);
    result==-1? cout<<"not found":cout<<"found in index "<<result;
    return 0;
}
