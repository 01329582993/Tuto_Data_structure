#include <iostream>
#include <vector>

using namespace std;

class Set
{
    vector<int> Parent;
    int S;
public:
    Set(int Size)
    {
        Parent.resize(Size);
        S = Size;

        for (int i = 0; i < Size; i++)
        {
            Parent[i] = i;
        }
    }


    int Find(int i)
    {

        if (Parent[i] == i)
        {
            return i;
        }

        return Find(Parent[i]);
    }


    void Unite(int i, int j)
    {
        int iRep = Find(i);
        int jRep = Find(j);

        Parent[jRep] = iRep;
    }

    void Display()
    {
        for(int i =0; i<S; i++)
        {
            cout<< Parent[i] <<" ";
        }
        cout<< endl;
    }
};


int main()
{
    int Operation, Element1,Element2;
    int N;
    bool run = true;
    cin>> N;

    Set U_F(N);

    while(run)
    {
        cin>> Operation;

        if(Operation == 1)
        {
            U_F.Display();
        }
        else if(Operation == 2)
        {
            cin>> Element1;
            cout<<U_F.Find(Element1)<<endl;
        }
        else if(Operation == 3)
        {
            cin>> Element1>> Element2;
            U_F.Unite(Element1, Element2);
            U_F.Display();
        }
        else
        {
            cout <<"Invalid Input !"<< endl;
            run = false;
        }
    }

    return 0;
}
