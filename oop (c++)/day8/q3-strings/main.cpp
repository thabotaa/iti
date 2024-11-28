#include <iostream>

using namespace std;

int main()
{
    string s1="ahmed";
    string s2="thabit";

    cout<<s1<<endl;
    cout<<s1.length()<<endl;
    cout<<s1.size()<<endl;


    cout<<s2<<endl;
    cout<<s1+s2<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;


    s1.append(s2);
    cout<<"the s1 after appending\n";
    cout<<s1<<endl;
    cout<<s2<<endl;

    /*
    string fname;
    cout<<"enter your full name\n";
    cin>>fname;
    cout<<fname;
    */

    string fname;
    cout<<"enter your full name\n";
    getline(cin,fname);
    cout<<"your full named is "<<fname<<endl;


    return 0;
}
