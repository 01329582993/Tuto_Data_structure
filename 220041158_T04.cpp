#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int calculateheight(int employee, const vector<int>& manager) {
    int height = 0;
    while (employee != -1) {
        employee = manager[employee];
        height++;
    }
    return height;
}

int main() {
    int n;
    cin >> n;


    vector<int> manager(n);
    for (int i = 1; i <=n; ++i) {
        cin >> manager[i];
    }

    int maxheight = 0;


    for (int i = 1; i <= n; ++i) {
        maxheight = max(maxheight, calculateheight(i, manager));
    }


    cout << maxheight << endl;

    return 0;
}
