#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string s;
    int run;
    cin>> run;
    while(run--)
    {
        int num;
        cin>> num;
        cin>> s;
        stack<char> Stack;
        for(char ch:s)
        {
            if (ch == '(' )
            {
                Stack.push(ch);
            }
            else  if(!Stack.empty() && ch == ')' )
            {
                Stack.pop();
            }

        }
        cout<< Stack.size();
    }

    return 0;
}
