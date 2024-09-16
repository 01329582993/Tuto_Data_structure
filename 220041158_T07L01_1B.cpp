#include <iostream>
#include <stack>
#include <vector>


using namespace std;

int main()
{
    int run;
    cin>>run;
    while(run--){
    stack<int> Stack;
    string st;
    cin>> st;

    for(int i=0; i<st.size(); i++)
    {
        if(isdigit(st[i]))
        {
            Stack.push(st[i] - '0');
        }
        else
        {
            int x,y;
            x = Stack.top();
            Stack.pop();
            y = Stack.top();
            Stack.pop();

            if(st[i] == '+')
            {
                Stack.push(x+y);
            }
            else if(st[i] == '-')
            {
                Stack.push(y-x);
            }
            else if(st[i] == '*')
            {
                Stack.push(x*y);
            }
            else if(st[i] == '/')
            {
                Stack.push(x/y);
            }

        }

    }
    cout<< Stack.top()<<endl;
    }
    return 0;
}
