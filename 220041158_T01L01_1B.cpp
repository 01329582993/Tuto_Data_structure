#include <iostream>

class Stack
{
private:
    int top;
    int* table;
    int Dim;

public:
    Stack(int dim)
    {
        top = -1;
        Dim = dim;
        table = new int[Dim];
        for(int i =0; i<Dim; i++)
        {
            table[i] = 0;
        }
    }


    ~Stack()
    {
        delete[] table;
    }

    bool isEmpty()
    {
        if(top == -1)
        {
            std::cout<<"true" <<std::endl;
            return true;
        }
    }

    bool isFull()
    {
        if(top ==Dim)
        {
            std::cout<<"true"<<std::endl;
            return top-1;
        }
        else
        {
            std::cout<<"False"<<std::endl;
        }


    }


    void push(int element)
    {
        if(top == Dim){
            std::cout << "Overflow"<< std::endl;
        }
        else{
        top++;
        table[top] = element;
        for(int i= 0;i<= top;i++){
        std::cout<<table[i]<<" ";
        }
        }
    }


    void pop()
    {
        if(top==-1)
        {
            std::cout<<"Underflow"<<std::endl;
        }
        else{
        std::cout<<table[top]<<std::endl;
        top--;
        }
    }


    int Size()
    {
        std::cout<<top+1<<std::endl;
        return top;
    }

    int Top()
    {
        std::cout<<table[top]<<std::endl;
        return table[top];
    }

};

int main()
{
    int dim;
    std::cin>>dim;
 Stack s(dim);

    while(1)
    {


        int option,x;
        std::cin>>option;
        switch(option)
        {
        case 1:
            std::cin>>x;
            s.push(x);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.isEmpty();
            break;
        case 4:
            s.isFull();
            break;
        case 5:
            s.Size();
            break;
        case 6:
            s.Top();
            break;
        default:
            exit(1);
            break;
        }
    }
}
