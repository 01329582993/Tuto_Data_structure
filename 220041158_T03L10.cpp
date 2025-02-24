#include <iostream>
#include <vector>

using namespace std;

class Set
{
    vector<int> Parent, Count;
    int Com, largest, Size;

public:
    Set(int n)
    {
        Parent.resize(n + 1);
        Count.resize(n + 1, 1);
        Com = n;
        largest = 1;
        Size = n;

        for (int i = 1; i <= Size; i++)
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
        return Parent[i] = Find(Parent[i]);
    }

    void Unite(int i, int j)
    {
        int iRep = Find(i);
        int jRep = Find(j);

        if (iRep == jRep) return;

        Com--;

        if (Count[iRep] < Count[jRep])
        {
            swap(iRep, jRep);
        }

        Parent[jRep] = iRep;
        Count[iRep] += Count[jRep];
        Count[jRep] = 0;
        largest = max(largest, Count[iRep]);
    }

    void Display()
    {
        cout << Com << " " << largest << endl;
    }
};

int main()
{
    int n, m, a, b;
    cin >> n >> m;

    Set U_F(n);

    while (m--)
    {
        cin >> a >> b;
        U_F.Unite(a, b);
        U_F.Display();
    }

    return 0;
}
