#include<iostream>
#include<queue>
#include<string>
using namespace std;
queue<int> qu1,qu2;
void print(queue<int> qu){
    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    cout<<endl;
}
void push(int c,int n){
    if(qu1.size()==n){
        cout<<"Overflow"<<endl;
        return;
    }
    qu1.push(c);
    print(qu1);
}
void pop(){
    if(qu1.empty()){
        cout<<"Underflow"<<endl;
        return;
    }
    while(qu1.size()>1){
        qu2.push(qu1.front());
        qu1.pop();
    }
    qu1.pop();
    while(!qu2.empty()){
        qu1.push(qu2.front());
        qu2.pop();
    }
    print(qu1);
}

int main(){
    int n,c;

    string opt;
    cin>>n;
     while(1){


    cin>>opt;
    if(opt=="push"){
        cin>>c;
        push(c,n);
    }
    else if(opt=="pop"){
        pop();
    }
     }
    return 0;
}
