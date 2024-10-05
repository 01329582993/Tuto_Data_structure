#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;

    Node(int key) : data(key), prev(nullptr), next (nullptr)
    {
    }
};

class Deque
{
private:
    Node* head;
    Node* tail;
    int Size;
    int Count;
public:
    Deque(int size)
    {
        head = tail = nullptr;
        Size = size;
        Count = 0;
    }

    void Push_front(int key)
    {
        Node* newNode = new Node(key);

        if(!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        Count++;
        display();
    }

    void Push_back(int key)
    {
        if(Count>= Size)
        {
            cout<< "Overflow"<< endl;
            return;
        }
        Node* newNode = new Node(key);
        if(!head)
        {
            head =tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        display();
        Count++;

    }

    void Pop_front()
    {
        if(!head)
        {
            cout<<"Underrflow"<< endl;
            return;
        }
        head = head->next;
        head->prev = nullptr;

        display();
        Count--;

    }
    void Pop_back()
    {
        if(!tail)
        {
            cout<<"Underflow"<< endl;
            return;
        }
        Node* temp = tail;

        tail = temp->prev;
        tail->next = nullptr;

        delete temp;
        Count--;
        display();



    }

    void SIZE()
    {
        cout<< Count <<endl;
    }

    void display()
    {
        Node* temp = head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<< endl;
    }


};
using namespace std;

int main()
{
    int size;
    cin>> size;
    Deque Q(size);
    cout<< "Press 1 to push_front \nPress 2 to push_back \nPress 3 to pop_front \nPress 4 to pop_back \nPress 5 for size \nPress 6 to exit"<< endl;

    int operation;

    while(cin>> operation && operation != -1)
    {
        switch (operation)
        {
            int key;
        case 1:
            cin>> key;
            Q.Push_front(key);
            break;
        case 2:
            cin>> key;
            Q.Push_back(key);
            break;
        case 3:
            Q.Pop_front();
            break;
        case 4:
            Q.Pop_back();
            break;
        case 5:
            Q.SIZE();
            break;
        case 6:
            exit(1);
            break;
        default :
            cout << "Invalid Input"<< endl;
        }

    }

    return 0;
}
