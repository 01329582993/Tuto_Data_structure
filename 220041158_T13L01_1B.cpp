#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{

    string s;
        cin>> s;

        stack<char> Stack;
        int iteration = 0;
        for(char ch:s)
        {
            if (ch == '(' )
            {
                Stack.push(ch);
            }
            else  if(!Stack.empty() && ch == ')' )
            {
                Stack.pop();
                iteration++;
            }
        }
        cout<< 2*iteration;
    return 0;
}
