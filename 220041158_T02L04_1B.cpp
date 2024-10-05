#include <iostream>


using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int key) : data(key), next(nullptr), prev(nullptr) {}
};


class dlinkedList
{
private:

    Node* head;
    Node* tail;

public:
    dlinkedList() : head(nullptr), tail(nullptr) {}



    void Insert_front(int key)
    {
        Node* newNode = new Node(key);
        if(!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = nullptr;
            newNode->next = head;
            head = newNode;
        }
        display();
    }


    void Insert_back(int key)
    {
        Node* newNode = new Node(key);

        if(!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail->next;
            newNode->next = nullptr;
            tail = newNode;
        }
        display();
    }

    void Insert_after_node(int key,int v)
    {
        Node* temp = head;

        while(temp && temp->data != v)
        {
            temp = temp->next;
        }
        if(!temp)
        {
            cout << "Value not found"<< endl;
        }
        else
        {
            Node* newNode = new Node(key);
            newNode->next = temp->next;
            temp->next  = newNode;
            newNode->prev = temp;
            if(temp == tail)
            {
                tail = newNode;
            }
        }
        display();
    }

    void Update_node(int key, int v)
    {
        Node* temp = head;
        while(temp && temp->data != v)
        {
            temp = temp->next;
        }
        if(!temp)
        {
            cout <<"Value not found"<< endl;
        }
        else
        {
            temp->data = key;
        }
        display();
    }

    void Remove_head()
    {
        if(!head)
        {
            cout<<"Underflow"<< endl;
        }
        else
        {
            head = head->next;
            if(!head)
            {
                tail = nullptr;
            }
        }
        display();
    }

    void Remove_element(int key)
    {
        Node* temp = head;
        while( temp && temp->data != key)
        {
            temp = temp->next;
        }

        if(!temp)
        {
            cout<<"Value not exist"<< endl;
        }
        else if(temp == head)
        {
            Remove_head();
        }
        else if(temp == tail)
        {
            tail = temp->prev;
        }
        else
        {
            temp-> prev = temp-> next;
        }
        delete temp;
        display();
    }


    void Remove_end()
    {
        if(head == tail)
        {
            delete head;
            head = tail = nullptr;
        }

        if(!head)
        {
            cout << "Underrflow"<< endl;
        }
        else
        {
            Node* temp;
            while(temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail =  temp;
            tail->next = nullptr;
        }
        display();

    }

    void display()
    {
        if (!head)
        {
            cout << "Head= Null, Tail =Null, Empty" << endl;
            return;
        }
        cout << "Head =" << head->data << ", Tail =" << tail->data << ", ";
        Node* temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};























int main()
{
    dlinkedList list;
    int choice, key, v;

    while (1)
    {
        cout << "Press 1 to insert at front \nPress 2 to insert at back \nPress 3 to insert after a node \nPress 4 to update a node \nPress 5 to remove the first node\nPress 6 to remove a node\nPress 7 to remove the last node\nPress 8 to exit." << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cin >> key;
            list.Insert_front(key);
            break;
        case 2:
            cin >> key;
            list.Insert_back(key);
            break;
        case 3:
            cin >> key >> v;
            list.Insert_after_node(key, v);
            break;
        case 4:
            cin >> key >> v;
            list.Update_node(key, v);
            break;
        case 5:
            list.Remove_head();
            break;
        case 6:
            cin >> key;
            list.Remove_element(key);
            break;
        case 7:
            list.Remove_end();
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid choice " << endl;
        }
    }
}
