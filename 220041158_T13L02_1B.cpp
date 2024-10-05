#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n;

    while (cin >> n && n != 0)
    {
        queue<int> deck;


        for (int i = 1; i <= n; i++)
        {
            deck.push(i);
        }

        vector<int> discarded;


        while (deck.size() > 1)
        {

            discarded.push_back(deck.front());
            deck.pop();

            deck.push(deck.front());
            deck.pop();
        }

        cout << "Discarded cards:";
        if (!discarded.empty())
        {
            cout << " " << discarded[0];
            for (size_t i = 1; i < discarded.size(); ++i)
            {
                cout << ", " << discarded[i];
            }
        }
        cout << endl;

        cout << "Remaining card: " << deck.front() << endl;
    }

    return 0;
}
