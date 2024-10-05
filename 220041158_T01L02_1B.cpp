#include <iostream>

using namespace std;

class  Queue{
private:
    int *queue;
    int front , rear , capacity , count ;


public:
    Queue(int size){
    capacity =  size;
    queue = new int[capacity];
    front = -1;
    rear = -1;
    count = 0;
    }

    void enqueue(int value){

    if(isfull()){
        cout<< "Enqueue overflow"<< endl;
        return;
    }

    if(isempty()){
        front = 0;
    }

    rear = (rear +1) % capacity;
    queue[rear] = value;
    count++;

    printout();
    }

    void  dequeue(){

    if(isempty()){
        cout << "Dequeue Underflow"<< endl;
        return;
    }

    cout << "Dequeue ";
    front = (front +1) % capacity;

    count --;

    printout();

    }

    bool isfull(){
        return count == capacity;
    }

    int size(){

    return count;
    }

    int Front(){
    if(isempty()){
        cout << "Front  Queue is  empty"<< endl;
        return 1;
    }

    cout << "Front "<< queue[front]<< endl;
    return queue[front];
    }

    void  printout(){
    if(isempty()){
        cout << "Queue is empty"<< endl;
        return;
    }
    cout << " Queue  ";
    for (int i = 0 ; i< count ; i++){
        cout<< queue[(front + i)% capacity]<< " ";
    }

    cout  << "\n";
    }

    bool isempty(){
    return count == 0;
    }


};



int main(){

    int operation , n;
    cin>> n;
    Queue Q(n);


    while(1){
        cin >> operation;
        if (operation == -1)
            break;
    int value;
        switch(operation ){

    case  1:
        cin>> value;
        Q.enqueue(value);
        break;
    case 2:
        Q.dequeue();
        break;
    case 3:
        cout<< "IsEmpty: "<< (Q.isempty() ? "True" : "False") << endl;
        break;
    case 4:
        cout<<"Isfull "<< ( Q.isfull() ? "True"  : "False") << endl;
        break;
    case 5:
        cout<< "Size: "<< Q.size()<< endl;
        break;
    case 6:
        Q.Front();
        break;
    default :
        cout << "Enter a valid input"<< endl;

        }
    }

    return 0;
}
