#include <iostream>
#include <stack>

using namespace std;

class Queue{
private :
    stack<int> s1,s2;
    int capacity;

public:
    Queue(int n){
    capacity = n;
    }

    void enqueue(int value){
    if (size() == capacity){

        cout<< "Size "<< size()<< " Overflow" << endl;
        return;
    }
    s1.push (value);
    printout();
    }

    void dequeue(){
    if(isempty()){
        cout <<"Size 0 element NULL" << endl;
        return;
    }
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    s2.pop();
    printout();
    }

    int size(){
    return s1.size() + s2.size();
    }

    bool isempty(){
    return s1.empty() && s2.empty();
    }



    void printout(){
     cout << "Size: " << size() << " Elements: ";
        if (isempty()) {
            cout << "Null" << endl;
            return;
        }

        stack<int> temp = s2;
        stack<int> reverseStack;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }


        temp = s1;
        while (!temp.empty()) {
            reverseStack.push(temp.top());
            temp.pop();
        }

        while (!reverseStack.empty()) {
            cout << reverseStack.top() << " ";
            reverseStack.pop();
        }
        cout << endl;
    }
};

int main() {
    int N, q;
    cin >> N >> q;
    Queue queue(N);

    int queryType, value;
    for (int i = 0; i < q; i++) {
        cin >> queryType;
        if (queryType == 1) {
            cin >> value;
            queue.enqueue(value);
        } else if (queryType == 2) {
            queue.dequeue();
        }
    }

    return 0;
}
