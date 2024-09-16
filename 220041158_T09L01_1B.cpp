#include <iostream>
#include <stack>
#include <string>


using namespace std;


int main()
{
    stack<char> Stack;
    string a;
    cin>> a;
    for(int i= 0;i< sizeof(a); i++){
        Stack.push(a[i]);
    }

    char temp;
    for (int i =0; i<sizeof(a); i++){
            temp = Stack.top();
            Stack.pop();
        if(Stack.top() = temp){
            Stack.pop();
        }
    }

    while(!Stack.empty()){
        cout <<Stack.top();
        Stack.pop();
 }

    return 0;
}
