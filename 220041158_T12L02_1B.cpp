#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    string line;

    while (getline(cin, line))
    {
        deque<char> Queue;
        deque<char>::iterator it = Queue.begin();

        for (char ch : line)
        {
            if (ch == '[')
            {

                it = Queue.begin();
            }
            else if (ch == ']')
            {

                it = Queue.end();
            }
            else
            {

                it = Queue.insert(it, ch);
                ++it;
            }
        }
        for (char ch : Queue)
        {
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}
