#include <iostream>
#include <stack>
#include <string>



using namespace std;
int main(){
    int run;
    cin>> run;
    while(run--){
            stack<char> Stack;
            string  temp;
            cin>> temp;

        for(int i= 0;i< temp.size(); i++){
            Stack.push(temp[i]);
        }
        string Out;

        while(!Stack.empty()){
             Out += Stack.top();
            Stack.pop();
        }
        cout << Out<< endl;
    }

    return 0;
}
