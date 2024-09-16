#include<iostream>
#include<stack>

using namespace std;
int main()
{
    int n,check =0;
    stack<char> Stack;
    string line;
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++ )
    {
        getline(cin,line);
        check=0;
        for(int j=0; j<line.size(); j++)
        {
            if(line[j]=='(' || line[j]=='[' || line[j]=='{')
            {
                Stack.push(line[j]);
            }
            if((line[j]==')' && Stack.top()=='(') ||(line[j]==']'&&Stack.top()=='[') || (line[j]=='}'&&Stack.top()=='{'))
            {
                Stack.pop();
            }
            else if((line[j]==')'&&Stack.top()!='(')||(line[j]==']'&&Stack.top()!='[')||(line[j]=='}'&&Stack.top()!='{'))
            {
                cout<<"No"<<endl;
                check=1;
                break;
            }
        }
        if(Stack.size()==0)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            if(!check)
                cout<<"No"<<endl;
        }
        while(!Stack.empty())
        {
            Stack.pop();
        }

    }
    return 0;
}
