#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int key) : data(key), next(nullptr), prev(nullptr)
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
            head->prev = newNode;
            head = newNode;
        }

    }


    void Remove()
    {
        Node* temp1 = head;

        while(temp1)
        {
            Node* temp2 = temp1->next;
            while(temp2)
            {
                if(temp1->data == temp2->data)
                {
                    Node* duplicate = temp2;
                    if(duplicate->prev){
                        duplicate->prev->next = duplicate->next;
                    }
                    if(duplicate->next){
                        duplicate->next->prev = duplicate->prev;
                    }
                    temp2 = temp2->next;
                    delete duplicate;
                }
                else
                {
                    temp2= temp2->next;
                }

            }
            temp1 = temp1->next;
        }
        display();
    }

    void display()
    {
        Node* temp = head;
        while(temp && temp->next)
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
    Set S;
    int element;

    while(cin>> element  && element != -1)
    {
        S.push(element);
    }
    S.Remove();
    return 0;
}
