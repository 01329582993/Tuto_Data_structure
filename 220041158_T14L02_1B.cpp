#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    int scenario = 1, t;

    while (cin >> t && t != 0) {
        // Print scenario number
        cout << "Scenario #" << scenario++ << endl;

        // Map to store the group of each element
        unordered_map<int, int> personToGroup;

        // Reading friend circle information
        for (int i = 0; i < t; ++i) {
            int groupSize, person;
            cin >> groupSize;
            for (int j = 0; j < groupSize; ++j) {
                cin >> person;
                personToGroup[person] = i; // Map person to their group (i)
            }
        }

        // Queue for groups and a map for group-specific queues
        queue<int> groupQueue;
        unordered_map<int, queue<int>> groupMembersQueue;
        unordered_set<int> inQueueGroups;

        string command;
        while (cin >> command && command != "STOP") {
            if (command == "ENQUEUE") {
                int x;
                cin >> x;
                int group = personToGroup[x];

                // If this group is not in the group queue, add it
                if (inQueueGroups.find(group) == inQueueGroups.end()) {
                    groupQueue.push(group);
                    inQueueGroups.insert(group);
                }
                // Add the person to their group's queue
                groupMembersQueue[group].push(x);
            } else if (command == "DEQUEUE") {
                // Process the first person in the queue
                int currentGroup = groupQueue.front();
                int person = groupMembersQueue[currentGroup].front();
                groupMembersQueue[currentGroup].pop();
                cout << person << endl;

                // If the group queue becomes empty, remove the group from the main queue
                if (groupMembersQueue[currentGroup].empty()) {
                    groupQueue.pop();
                    inQueueGroups.erase(currentGroup);
                }
            }
        }

        // Print a blank line after each test case
        cout << endl;
    }

    return 0;
}
