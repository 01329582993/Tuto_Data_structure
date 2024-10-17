#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i)
    {
        int n, m;
        cin >> n >> m;

        deque<int> dq;
        cout << "Case " <<  i<< endl;

        for (int i = 0; i < m; ++i)
        {
            string command;
            cin >> command;

            if (command == "pushLeft")
            {
                int x;
                cin >> x;
                if (dq.size() < n)
                {
                    dq.push_front(x);
                    cout << "Pushed in left: " << x << endl;
                }
                else
                {
                    cout << "The queue is full"<<endl;
                }
            }
            else if (command == "pushRight")
            {
                int x;
                cin >> x;
                if (dq.size() < n)
                {
                    dq.push_back(x);
                    cout << "Pushed in right: " << x << endl;
                }
                else
                {
                    cout << "The queue is full"<<endl;
                }
            }
            else if (command == "popLeft")
            {
                if (!dq.empty())
                {
                    cout << "Popped from left: " << dq.front() << endl;
                    dq.pop_front();
                }
                else
                {
                    cout << "The queue is empty"<<endl;
                }
            }
            else if (command == "popRight")
            {
                if (!dq.empty())
                {
                    cout << "Popped from right: " << dq.back() << endl;
                    dq.pop_back();
                }
                else
                {
                    cout << "The queue is empty"<<endl;
                }
            }
        }
    }
}
