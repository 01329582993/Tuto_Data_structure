#include<iostream>
using namespace std;
int isFull(int top,int N){
    if(top==N-1)
        return 1;
    else
        return 0;
}
int isEmpty(int top){
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(int *arr,int val,int *top,int N){
    if(isFull(*top,N)){
        cout<<"Overflow"<<endl;
        return;
    }
    (*top)++;
    arr[*top]=val;
}
int sise(int top){
    return top+1;
}
int Top(int *arr,int top){
    return arr[top];
}
void pop(int *top){
    if(isEmpty(*top)){
        cout<<"Empty stack"<<endl;
        return;
    }
    (*top)--;
}
int main(){
    int N,arr[3],top=-1,val;
    char opr;
    cin>>N;
    cin>>opr;
    while(opr!='/'){
        if(opr=='+'){
            cin>>val;
            push(arr,val,&top,N);
        }
        if(opr=='-'){
            pop(&top);
        }
        cout<<"Size :"<<sise(top)<<endl;
            cout<<"Stack Elements :";
            for(int i=0;i<=top;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            if(sise(top)==0)
                cout<<"Top Element : 0"<<endl;
            else
                cout<<"Top Element :"<<Top(arr,top)<<endl;
            if(isFull(top,N)){
                cout<<"isFull : True"<<endl;
            }
            else{
                cout<<"isFull :false"<<endl;
            }
            if(isEmpty(top)){
                cout<<"isEmpty : True"<<endl;
            }
            else{
                cout<<"isEmpty :false"<<endl;
            }
            cin>>opr;
    }
    return 0;
}
