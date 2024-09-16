#include <iostream>
#include <vector>
#include<stack>

using namespace std;

bool is_found(int number, vector<int>& a){
    for(int i:a){
        if(i == number)
            return true;
    }
    return false;
}
int main()
{
    int n, Size;
    vector<int > a;
    while(cin>> n)
    {
        a.push_back(n);
    }
    Size = a.back();
    for(int i= 1; i<=Size ; i++)
    {

        if(is_found(i, a))
        {
            cout<<"push ";


        }
        else
        {
            cout << "push pop ";
        }
    }
    return 0;
}
