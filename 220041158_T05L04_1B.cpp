#include <iostream>
#include<set>

using namespace std;


int main()
{
    int element;
    std::set <int> List1, List2;
    while(cin>> element && element != -1)
    {
        List1.insert(element);
    }

    while(cin>> element && element != -1)
    {
        List2.insert(element);
    }
    bool check;
    if(List1.empty() && List2.empty())
    {
        cout << "Empty"<< endl;
    }
    else
    {
        for(auto i:List1)
        {
            for(auto j:List2)
            {
                if(i == j)
                {
                    cout << i<<" "<< endl;
                    check = true;
                }
            }
        }

    }

    if(!check)
    {
        cout<< "Empty"<< endl;
    }



    return 0;
}
