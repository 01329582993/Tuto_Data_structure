#include <iostream>

using namespace std;

class Deque{
private:
    int *deque;
    int front, rear , capacity, count;

public:

    Deque(int size){
    capacity = size;
    deque = new  int[capacity];
    front = -1;
    rear = -1;
    count = 0;
    }
    void push_front(int value){

    if(isfull()){
        cout << "Deque overflow"<< endl;
        return;
    }

    if(isempty()){
        front = rear = 0;
    }
    else {
        front = (front -1 + capacity) % capacity;
    }
    deque[front] = value;
    count ++;
    printout();
    }

    void push_back(int value){
    if(isfull()){
        cout << "Deque overflow"<< endl;
        return;
    }
    if (isempty()){
        front =  rear = 0;
    }
    else {
        rear = (rear + 1) % capacity;
    }
    deque[rear] = value;
    count ++;
    printout();
    }


    int pop_front(){

    if(isempty()){
        cout << "Deque underflow"<< endl;
        return -1;
    }
    int out = deque[front ];
    if(front ==  rear){
        front = rear = -1;
    }
    else {
        front = (front +1)% capacity;
    }
    count --;
    printout();
    return out;
    }

    int pop_back(){
    if(isempty()){
       cout << "Deque Underflow"<< endl;
       return -1;
       }
       int out = deque[rear];
       if(front == rear){
        front = rear = -1;
       }
       else {
        rear = (rear -1 +capacity)%  capacity;
       }
       count --;
       printout();
       return out;
    }

    int size(){
    cout << "size"<< count << endl;
    return count;
    }

    bool isempty(){
    return count == 0;
    }

    bool isfull(){
    return count == capacity;
    }

    void printout(){
    if(isempty()){
        cout<< "Deque is empty"<< endl;
        return ;
    }
    cout << "Deque ";
    for(int i=0; i< count ; i++){
        cout << deque[(front+i) %capacity]<< " ";
    }
    cout<< endl;

    }


};


int main(){
    int n, operation;
    cin>> n;
    Deque D(n);

    while(1){
    cin>> operation;
    int value;
    switch(operation){
case 1:
    cin >> value;
    D.push_front(value);
    break;
case 2:
    cin>> value;
    D.push_back(value);
    break;
case 3:
    D.pop_front();
    break;
case 4:
    D.pop_back();
    break;
case 5:
    D.size();
    break;
case 6:
    return 0;
default :
    cout<< "Invalid input";
    break;
    }

        }
    return 0;
}
