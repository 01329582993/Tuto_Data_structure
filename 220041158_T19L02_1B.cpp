#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
    stack<int> dish;
    queue<int> stud;
    int n;
    int num;
    cin>>n;
    cout<<"students =[";
    for(int i=0;i<n;i++){
        cin>>num;
        cin.ignore();
        stud.push(num);
    }
    cout<<"dishes =[";
    for(int i=0;i<n;i++){
        cin>>num;
        cin.ignore();
        dish.push(num);
    }
    int check=0;
    int s=stud.size();
    while(!stud.empty()){
        if(stud.front()==dish.top()){
            dish.pop();
            stud.pop();
            check=0;
        }
        else{
                check++;
            stud.push(stud.front());
            stud.pop();
        }
        if(check>s){
            break;
        }
    }
    cout<<stud.size();
    return 0;

}
