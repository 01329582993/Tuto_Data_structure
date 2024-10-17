#include <iostream>
#include <stack>
#include <string>

using namespace std;

void TestBrowser(int Case) {
    stack<string> Back, Forward;
    string currentPage = "http://www.lightoj.com/";
    string command, url;

    cout << "Case " << Case << ":\n";

    while (cin >> command) {
        if (command == "QUIT") {
            break;
        } else if (command == "VISIT") {
            cin >> url;
            Back.push(currentPage);
            currentPage = url;
            while (!Forward.empty()) {
                Forward.pop();
            }
            cout << currentPage << endl;
        } else if (command == "BACK") {
            if (Back.empty()) {
                cout << "Ignored" << endl;
            } else {
                Forward.push(currentPage);
                currentPage = Back.top();
                Back.pop();
                cout << currentPage << endl;
            }
        } else if (command == "FORWARD") {
            if (Forward.empty()) {
                cout << "Ignored" << endl;
            } else {
                Back.push(currentPage);
                currentPage = Forward.top();
                Forward.pop();
                cout << currentPage << endl;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        TestBrowser(i);
    }
}
