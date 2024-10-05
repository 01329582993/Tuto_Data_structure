#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N;
        cin >> N;

        deque<int> pile;
        for (int i = 0; i < N; ++i)
        {
            int stone;
            cin >> stone;
            pile.push_back(stone);
        }

        bool isDaiyanTurn = true;
        string lastMover;
        int lastStone;

        while (pile.size() > 1)
        {
            if (isDaiyanTurn)
            {

                int topStone = pile.front();
                pile.pop_front();
                pile.push_back(topStone);


                pile.pop_front();

                lastMover = "Daiyan";
            }
            else
            {

                int topStone = pile.front();
                pile.pop_front();
                pile.push_back(topStone);

                topStone = pile.front();
                pile.pop_front();
                pile.push_back(topStone);


                pile.pop_front();

                lastMover = "Ishraq";
            }

            isDaiyanTurn = !isDaiyanTurn;
        }


        lastStone = pile.front();

        cout << lastMover << " " << lastStone << endl;
    }

    return 0;
}

