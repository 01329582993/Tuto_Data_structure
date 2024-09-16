#include<iostream>
#include<stack>
#include<sstream>
#include<string>

using namespace std;
int main()
{
    stack<string> st;
    string temp,line;
    int n,err,read=0,check=0,firstOcc=0;
    cin>>n;
    cin.ignore();
    for(int j=0; j<=n; j++)
    {
        getline(cin,line);
        for(int i=0; i<line.size(); i++)
        {
            if(line[i]=='<')
            {
                read=1;
                temp=line[i+1];
                continue;
            }
            if(line[i+1]=='>')
            {
                read=0;
                check=1;
            }
            if(read)
            {
                temp+=line[i+1];
            }
            if(check)
            {
                if(temp[0]!='/')
                {
                    st.push(temp);
                    check=0;
                }
                else
                {
                    temp.erase(0,1);
                    if(temp==st.top())
                    {
                        st.pop();
                    }
                    else
                    {
                        if(firstOcc==0)
                        {
                            err=j+1;
                            firstOcc=1;
                        }
                    }
                    check=0;
                }
            }
        }

    }
    if(firstOcc)
        cout<<"Error at line "<<err<<endl;
    return 0;
}
