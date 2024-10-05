#include<iostream>
#include<vector>
using namespace std;
void EnQueue(int *arr,int c,int *rea,int n,int *Count){
    if(*Count==n){
        cout<<"overflow"<<endl;
    }
    else{
        arr[(*rea)]=c;
        (*rea)=((*rea)+1)%n;
        (*Count)++;
    }
}
bool isEmpty(int Count){
    if(Count==0){
        return true;
    }
    return false;
}
bool isFull(int Count,int n){
    if(Count==n){
        return true;
    }
    return false;
}
void DeQueue(int *arr,int *fro,int *Count,int n){
    if(isEmpty(*Count)){
        cout<<"Underflow"<<endl;
    }
    else{
        (*fro)=(*fro+1)%n;
        (*Count)--;
    }
}
int main(){
     int n,fro=0,rea=0,Count=0,c,reari,froi;
     char opt;
     cin>>n;
     int arr[n];
     cin>>opt;
     while(opt!='-'){
     switch(opt){
     case 'E':
        cin>>c;
        reari=rea;
        EnQueue(arr,c,&rea,n,&Count);
        cout<<"Current Size: "<<Count<<endl;
        if(isFull(Count,n)){
             cout<<"Full?: Yes"<<endl;
         }
         else{
             cout<<"Full?: No"<<endl;
         }
         if(isEmpty(Count)){
             cout<<"Empty?: Yes"<<endl;
             cout<<"Front Element: -"<<endl;
             cout<<"Front Index :"<<fro<<endl;
             cout<<"Rear Element: -"<<endl;
             cout<<"Rear Index :"<<reari<<endl;
              cout<<"Queue Elements: -";
         }
         else{
             cout<<"Empty?: No"<<endl;
             cout<<"Front Element: "<<arr[fro]<<endl;
             cout<<"Front Index : "<<fro<<endl;
             cout<<"Rear Element: "<<arr[reari]<<endl;
             cout<<"Rear Index :"<<reari<<endl;
             cout<<"Queue Elements: ";
         for(int i=fro,j=0;j<Count;j++,i=(i+1)%n){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
         }
        break;
     case 'D':
        froi=fro;
        DeQueue(arr,&fro,&Count,n);
        cout<<"Current Size: "<<Count<<endl;
        if(isFull(Count,n)){
             cout<<"Full?: Yes"<<endl;
         }
         else{
             cout<<"Full?: No"<<endl;
         }
         if(isEmpty(Count)){
             cout<<"Empty?: Yes"<<endl;
             cout<<"Front Element: -"<<endl;
             cout<<"Front Index :"<<froi<<endl;
             cout<<"Rear Element: -"<<endl;
             cout<<"Rear Index :"<<rea<<endl;
              cout<<"Queue Elements: -";
         }
         else{
             cout<<"Empty?: No"<<endl;
             cout<<"Front Element: "<<arr[froi]<<endl;
             cout<<"Front Index : "<<froi<<endl;
             cout<<"Rear Element: "<<arr[rea]<<endl;
             cout<<"Rear Index :"<<rea<<endl;
             cout<<"Queue Elements: ";
         for(int i=fro,j=0;j<Count;j++,i=(i+1)%n){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
         }
        break;
     }

     cin>>opt;
     }


     return 0;
}

