#include <iostream>

class Stack
{
public:
    int top = -1;
    int table[100];

    bool isEmpty()
    {
        if(top == -1)
        {
            std::cout<<"true" <<std::endl;
            return true;
        }
    }

    bool isFull(){
    if(top ==100){
    std::cout<<"true"<<std::endl;
        return top-1;
    }
    else{
    std::cout<<"False"<<std::endl;
    }


    }

    void push(int element){
        top++;
        table[top] = element;
        std::cout<<element<<std::endl;
    }


    void pop(){
        if(top==-1){
        std::cout<<"Underflow"<<std::endl;
        }
        std::cout<<table[top]<<std::endl;
        top--;
    }


    int Size(){
    std::cout<<top<<std::endl;
    return top;
    }

    int Top(){
    std::cout<<table[top]<<std::endl;
    return table[top];
    }

};

int main()
{
    class Stack s;

    while(1)
    {
        int dim;
        std::cin>>dim;
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
