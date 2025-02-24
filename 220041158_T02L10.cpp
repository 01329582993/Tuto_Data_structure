#include <iostream>
#include <vector>

using namespace std;

class Set
{
    vector<int> Rank, Parent ;
    int S;

public:

    Set(int Size)
    {
        Rank.resize(Size, 0);
        Parent.resize(Size);
        S = Size;

        for (int i = 0; i < Size; i++)
        {
            Parent[i] = i;
        }
    }


    int Find(int i)
    {
        int Root = Parent[i];

        if (Parent [Root] != Root)
        {
            return Parent[i] = Find(Root);
        }
        return Root;
    }


    void Unite(int y, int x)
    {
        int xRoot = Find(x);
        int yRoot = Find(y);

        if (xRoot == yRoot)
        {
            return;
        }

        if (Rank[xRoot] < Rank[yRoot])
        {
            Parent[xRoot] = yRoot;
        }
        else if (Rank[yRoot] < Rank[xRoot])
        {
            Parent[yRoot] = xRoot;
        }
        else
        {
            Parent [yRoot] = xRoot;
            Rank[xRoot]++;
        }
    }

    void Display()
    {
        for(int i =0; i<S; i++)
        {
            cout<< Parent[i] <<"("<<Rank[i]<< ")"<< " ";
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
        else if(Operation == 4)
        {
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
