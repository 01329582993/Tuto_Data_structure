#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> st;
    int Count = 0;
    int now = 1;

    for (int i = 0; i < 2 * n; ++i)
    {
        string operation;
        cin >> operation;

        if (operation == "add")
        {
            int x;
            cin >> x;
            st.push(x);
        }
        else
        {
            if (!st.empty() && st.top() == now)
            {
                st.pop();
            }
            else
            {
                Count++;
                while (!st.empty())
                    st.pop();
            }
            now++;

        }
    }

    cout << Count/2 << endl;

    return 0;
}
