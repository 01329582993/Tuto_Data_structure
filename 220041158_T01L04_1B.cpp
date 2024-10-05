#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int key) : data(key), next(nullptr) {}
};

class Linkedlist
{
private:
    Node* head;
    Node* tail;

public:
    Linkedlist() : head(nullptr), tail(nullptr) {}


    void Insert_front(int key)
    {
        Node* newNode = new Node(key);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        display();
    }


    void Insert_back(int key)
    {
        Node* newNode = new Node(key);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        display();
    }


    void Insert_after_node(int key, int v)
    {
        Node* temp = head;
        while (temp && temp->data != v)
        {
            temp = temp->next;
        }
        if (!temp)
        {
            cout << "Value Not found" << endl;
        }
        else
        {
            Node* newNode = new Node(key);
            newNode->next = temp->next;
            temp->next = newNode;
            if (temp == tail)
            {
                tail = newNode;
            }
        }
        display();
    }


    void Update_node(int key, int v)
    {
        Node* temp = head;
        while (temp && temp->data != v)
        {
            temp = temp->next;
        }
        if (!temp)
        {
            cout << "Value Not found" << endl;
        }
        else
        {
            temp->data = key;
        }
        display();
    }


    void Remove_head()
    {
        if (!head)
        {
            cout << "Underflow" << endl;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            if (!head)
            {
                tail = nullptr;
            }
            delete temp;
        }
        display();
    }


    void Remove_element(int key)
    {
        if (!head)
        {
            cout << "Value Not found" << endl;
            display();
            return;
        }

        if (head->data == key)
        {
            Remove_head();
            return;
        }

        Node* prev = nullptr;
        Node* temp = head;
        while (temp && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (!temp)
        {
            cout << "Value Not found" << endl;
        }
        else
        {
            prev->next = temp->next;
            if (temp == tail)
            {
                tail = prev;
            }
            delete temp;
        }
        display();
    }


    void Remove_end()
    {
        if (!head)
        {
            cout << "Underflow" << endl;
            display();
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node* temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
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
    Linkedlist list;
    int choice, key, v;

    while (true)
    {
        cout << "Press 1 to insert at front\nPress 2 to insert at back \nPress 3 to insert after a node\nPress 4 to update a node\nPress 5 to remove the first node\nPress 6 to remove a node\nPress 7 to remove the last node\nPress 8 to exit." << endl;
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
            cout << "Invalid input" << endl;
        }
    }
}
