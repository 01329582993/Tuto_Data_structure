#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int n;
    cin>> n;
    cin.ignore();
    n++;
    string line, Code;
    while(n--){
     getline(cin, line);
     Code += line;
    }
    stack<char> Stack;
    for(char ch:Code){
        if(ch == '(' || ch == '[' || ch == '{'){
            Stack.push(ch);
           }
           else if((ch == ')' || ch == ']' || ch == '}') && (Stack.top() == '(' || Stack.top() == '[' || Stack.top() == '{')){
            Stack.pop();
           }
    }
    cout << Code;

    if(Stack.empty())
        cout << "No errors";

    else
        cout << "Error";



    return 0;
}
