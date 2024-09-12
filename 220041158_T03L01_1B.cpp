#include <iostream>

int top=-1;
int table[100];
void push(int element)
{
    top++;
    table[top] = element;
    std::cout<<"push"<<std::endl;
}

void pop()
{
    if(top==-1)
    {
        std::cout<<"Stack is empty"<<std::endl;
    }
    std::cout<<"pop"<<std::endl;
    top--;
}


int main()
{
    int element;
    int array[5];
    int index =1, check;

    for(int i= 0; i<5; i++){
         std::cin>>array[i];
    }


    while(index < 5)
    {


        push(index);


        for(int i=0; i<5; i++)
        {
            if(index = array[i])
            {
               check =1;
            }

        }
        index++;
        if(!check)
        pop();

    }




return 0;
}
