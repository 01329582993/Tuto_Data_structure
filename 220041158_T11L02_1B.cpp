#include <iostream>
#include <string>


using namespace std;

void checkRotation(string S, string T) {
    int n = S.length();

    if (n != T.length()) {
        cout << "No" << endl;
        return;
    }


    string concatenated = S + S;

    size_t pos = concatenated.find(T);

    if (pos != string::npos && pos < n) {
        if (pos == 0) {
            cout << "Yes.Rotation not needed." << endl;
        } else {
            cout << "Yes. After" << pos << " clockwise rotations" << endl;
        }
    } else {

        cout << "No" << endl;
    }
}

int main() {
    string S, T;

    cin >> S >> T;

    checkRotation(S, T);

    return 0;
}

