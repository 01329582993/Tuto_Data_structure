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

class Set
{
private:
    Node* head;
    Node* tail;
public:

    set()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push(int key)
    {
        Node* newNode = new Node(key);

        if(!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }

    }



    void displayOdd()
    {
        Node* temp = head;
        while(temp && temp->next)
        {
            cout<<temp->data<<" ";
            temp = temp->next->next;
        }
    }

     void displayEve()
    {
        Node* temp = head->next;
        while(temp && temp->next)
        {
            cout<<temp->data<<" ";
            temp = temp->next->next;
        }
        cout<<"NULL"<< endl;
    }

};

using namespace std;

int main()
{
    Set S;
    int element;

    while(cin>> element  && element != 0)
    {
        S.push(element);
    }

    S.displayOdd();
    S.displayEve();

    return 0;
}
