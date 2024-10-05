#include <iostream>
#include <queue>
#include <vector>


using namespace std;


int findKthLargestSum(vector<int>& arr, int N, int K)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += arr[j];
            if (minHeap.size() < K)
            {
                minHeap.push(sum);
            }
            else if (sum > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(sum);
            }
        }
    }
    return minHeap.top();
}





int main()
{
    int N, K;

    cin >> N;
    vector<int> arr(N);


    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cin >> K;

    int result = findKthLargestSum(arr, N, K);


    cout << result << endl;

    return 0;
}

