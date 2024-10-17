#include <iostream>

using namespace std;

struct Node
{
    int value, height;

    Node *left, *right, *parent;

    Node(int data) : value(data), left(nullptr), right(nullptr), parent(nullptr), height(0) {}

};


class BST
{
private:

    Node *root;

    void Height(Node *node)
    {
        while(node != nullptr)
        {
            int leftheight, rightheigt;
            if(node->left)
            {
                leftheight= node->left->height + 1;
            }
            else
            {
                leftheight = 0;
            }
            if(node->right)
            {
                int  rightheigt = node->right->height +1;
            }
            else
            {
                rightheigt =0;
            }
            node->height = max(leftheight, rightheigt);
            node = node->parent;
        }

    }

    Node* Insert(Node *node, int value)
    {
        Node *Now = node, *parent = nullptr;

        while(Now != nullptr)
        {
            parent = Now;
            if(value < Now->value)
            {
                Now = Now->left;
            }
            else
            {
                Now = Now->right;
            }
        }

        Node *newNode = new Node(value);
        newNode->parent = parent;
        if(parent == nullptr)
        {
            root = newNode;
        }
        else if(value <parent->value)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }

        Height(newNode);

        return root;
    }


    Node* SearchNode(Node *node, int value)
    {
        while(node != nullptr && node->value != value )
        {
            if(value<  node->value)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }

        }

        return node;

    }

    void Print_tree(Node *node)
    {
        if(node == nullptr)
        {
            return ;
        }
        Print_tree(node->left);
        cout<< node->value <<" ";
        Print_tree(node->right);
    }

    Node* inorderP(Node* node)
    {
        if (node->left != nullptr)
        {
            node = node->left;
            while (node->right != nullptr)
                node = node->right;
            return node;
        }
        Node* parent = node->parent;
        while (parent != nullptr && node == parent->left)
        {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }

    Node* inorderS(Node* node)
    {
        if (node->right != nullptr)
        {
            node = node->right;
            while (node->left != nullptr) node = node->left;
            return node;
        }
        Node* parent = node->parent;
        while (parent != nullptr && node == parent->right)
        {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }


public:
    BST(int N)
    {
        int Size = N;
        root = nullptr;
    }


    void insert(int value)
    {
        root = Insert(root, value);
    }

    void InorderPrint()
    {
        Print_tree(root);
        cout << endl;
    }

    void Search (int value)
    {
        Node *found;

        found = SearchNode(root, value);

        if(found->value == value)
        {
            cout<< "Present"<< endl;
            cout<< "Parent("<<found->parent->value<<"), Left("<<found->left<<"), Right("<< found->right->value<<")"<<endl;
        }
        else
        {
            cout<<"Not found "<< endl;
        }
    }

    void Before_after(int value)
    {
        Node* node = SearchNode(root, value);
        if (node != nullptr)
        {
            Node* pred = inorderP(node);
            Node* succ = inorderS(node);
            cout << (pred ? to_string(pred->value) : "null")
                 << (succ ? to_string(succ->value) : "null") << endl;
        }

    }

  void height(int value) {
        Node* found = SearchNode(root, value);
        if (found != nullptr)
            cout << found->height << endl;
        else
            cout << "null" << endl;
    }










};


int main()
{

    int N, input, Case;
    cin>>N;

    BST bst(N);
    while(cin>> Case){
        if(Case == 1){
             for(int i =0; i< N; i++)
    {
        cin>>input;
        bst.insert(input);
    }
     bst.InorderPrint();
        }

        else if(Case == 3){
                int srch;
            cin>>srch;
        bst.Search(srch);
        }
        else if(Case == 4){
            int vall;
                cin>>vall;
            bst.height(vall);
        }
        else if(Case  == 5){
                int val;
        cin>> val;
            bst.Before_after(val);
        }
    }





    return 0;
}
