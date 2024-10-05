#include <iostream>

using namespace std;


struct Node
{
    int data;
    Node* next;

    Node(int key) : data(key), next(nullptr)
    {
    }
};

class Stack
{
private:
    Node* head;
    int Count;
    int  Size;

public:
    Stack(int size)
    {
        Size = size;
        Count =0;
        head = nullptr;
    }

    void push(int key)
    {
        if(isFull())
        {
            cout <<"Overflow"<<endl;
            return;
        }
        Node* newNode = new Node(key);
        newNode->next = head;
        head = newNode;
        Count++;
        display();
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<< "Underflow"<<endl;
            return;
        }
        Node* temp = head;
        cout <<head->data<<endl;
        head = head->next;
        delete temp;
        Count--;
        display();
    }

    bool isEmpty()
    {
        return head == nullptr;

    }

    bool isFull()
    {
        return Count == Size;

    }

    int SIZE()
    {
        return Count;
    }

    void top()
    {
        if(isEmpty())
        {
            cout<<"Empty"<< endl;
        }
        else
        {
            cout << head->data<<endl;
        }
    }

    void display()
    {
        Node* temp = head;
        while(temp)
        {
            cout<<temp->data<<" " ;
            temp = temp->next;
        }
        cout<<endl;
    }

};

int main()
{

    int operation, Stack_Size;
    cin>> Stack_Size;
    Stack NodeS(Stack_Size);

    while(cin>>operation && operation != -1)
    {

        switch (operation)
        {
        case 1:
            int key;
            cin>> key;
            NodeS.push(key);
            break;
        case 2:
            NodeS.pop();
            break;
        case 3:
            if(NodeS.isEmpty())
            {
                cout <<"True"<<endl;
            }
            else
            {
                cout << "false"<<endl;
            }
            break;
        case 4:
            if(NodeS.isFull())
            {
                cout<< "True"<< endl;
            }
            else
            {

                cout<<"False"<<endl;
            }
            break;
        case 5:
            cout<<NodeS.SIZE()<<endl;
            break;
        case 6:
            NodeS.top();
            break;


        }
    }



    return 0;

}
