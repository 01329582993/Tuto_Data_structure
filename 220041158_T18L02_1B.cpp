#include<iostream>
#include<string>
using namespace std;

void Push_front(int *arr, int c, int *fro, int *rea, int n, int *Count) {
    if (*Count == n) {
        cout << "overflow" << endl;
    } else {
        *fro = (*fro - 1 + n) % n;
        arr[*fro] = c;
        (*Count)++;
    }
}

void Push_back(int *arr, int c, int *fro, int *rea, int n, int *Count) {
    if (*Count == n) {
        cout << "overflow" << endl;
    } else {
        arr[*rea] = c;
        *rea = (*rea + 1) % n;
        (*Count)++;
    }
}

bool Is_empty(int Count) {
    return Count == 0;
}

bool Is_full(int Count, int n) {
    return Count == n;
}

void Pop_back(int *arr, int *fro, int *rea, int *Count, int n) {
    if (Is_empty(*Count)) {
        cout << "Underflow" << endl;
    } else {
        *rea = (*rea - 1 + n) % n;
        (*Count)--;
    }
}

void Pop_front(int *arr, int *fro, int *rea, int *Count, int n) {
    if (Is_empty(*Count)) {
        cout << "Underflow" << endl;
    } else {
        *fro = (*fro + 1) % n;
        (*Count)--;
    }
}

void display(int *arr, int fro, int Count, int n) {

    for (int i = 0, idx = fro; i < Count; i++, idx = (idx + 1) % n) {
        cout << arr[idx] << " ";
    }
    cout << endl;
}

int main() {
    int n, fro = 0, rea = 0, Count = 0, c;
    string opt;

    cin >> n;
    int arr[n];

    while (true) {
        cin >> opt;
        if (opt == "E") {
            break;
        }

        if (opt == "PF") {
            cin >> c;
            Push_front(arr, c, &fro, &rea, n, &Count);
            display(arr, fro, Count, n);
        }
        else if (opt == "PB") {
            cin >> c;
            Push_back(arr, c, &fro, &rea, n, &Count);
            display(arr, fro, Count, n);
        }
        else if (opt == "DF") {
            Pop_front(arr, &fro, &rea, &Count, n);
            if (Count > 0) display(arr, fro, Count, n);
        }
        else if (opt == "DB") {
            Pop_back(arr, &fro, &rea, &Count, n);
            if (Count > 0) display(arr, fro, Count, n);
        }
        else if (opt == "S") {
            cout << Count << endl;
        }
        else if (opt == "F") {
            cout << fro+1 << endl;
        }
        else if (opt == "R") {
            cout << (rea - 1 + n) % n << endl;
        }
        else if (opt == "STAT") {
            if (Is_full(Count, n)) {
                cout << "FULL" << endl;
            } else if (Is_empty(Count)) {
                cout << "EMPTY" << endl;
            } else {
                cout << "NONE" << endl;
            }
        }
    }

    return 0;
}
