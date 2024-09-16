#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    vector<int> Array;
    int n;
    while (cin>>n)
    {
        if(n == -1)
            break;
        Array.push_back(n);
    }
    int Size = Array.size();
    vector<int> nge(Size, -1);
    stack<int> Stack;
    for (int i= 0; i<Size; i++)
    {
        while(!Stack.empty() && Array[i] > Array[Stack.top()])
        {
            nge[Stack.top()] = Array[i] ;
            Stack.pop();
        }
        Stack.push(i);
    }
    for(int i= 0; i< Size; i++)
    {
        cout << nge[i] << " ";
    }
    return 0;
}
