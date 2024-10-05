#include <iostream>
#include<vector>
using namespace std;

int H[50];
int size = -1;
int parent(int i)
{

    return (i - 1) / 2;
}
int leftChild(int i)
{

    return ((2 * i) + 1);
}
int rightChild(int i)
{
    return ((2 * i) + 2);
}
void shiftUp(int i)
{
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}
void shiftDown(int i)
{
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= size && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= size && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}
void insert(int p)
{
    size = size + 1;
    H[size] = p;
    shiftUp(size);
}
int extractMax()
{
    int result = H[0];
    H[0] = H[size];
    size = size - 1;
    shiftDown(0);
    return result;
}
void changePriority(int i, int p)
{
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    }
    else {
        shiftDown(i);
    }
}
int getMax()
{

    return H[0];
}
void remove(int i)
{
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}
bool isEmpty()
{
    if(size==-1)
        return true;
    else
        return false;
}
int lastStoneWeight(int stones) {
        while (size > 1) {
            int  stone1,stone2;
             remove(stone1);
             remove(stone2);

            if (stone1 - stone2 != 0) {
                insert(stone1 - stone2);
            }
        }
        if(isEmpty()==true)
            return 0;
        else
            remove(stones);
    }
int lastStoneWeightII(vector<int>& stones) {
      int n = stones.size();
      int total = 0;
      for(int i = 0; i < n; i++){
         total += stones[i];
      }
      int req = total / 2;
      vector <bool> dp(req + 1, false);
      dp[0] = true;
      int reach = 0;
      for(int i = 0; i < n; i++){
         for(int j = req; j - stones[i] >= 0; j--){
            dp[j] = dp[j] || dp[j - stones[i]];
            if(dp[j]) reach = max(reach, j);
         }
      }
      return total - (2 * reach);
   }
int main()
{
    vector<int> v = {10 ,50, 30, 10, 40, 60, 20};
    cout << (lastStoneWeightII(v));
}

/*
Suppose we have a collection of rocks, now each rock has a positive integer weight. In each turn, we choose any two rocks and smash them together.
If the stones have weights x and y with x <= y. The result of this smash will be −

If x = y, both stones are totally destroyed;

If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.

Finally, there is at most 1 stone left. We have to find the smallest possible weight of this stone (the weight is 0 if there are no stones left.)

So for example, if the input is like [2,7,4,1,8,1], then the output will be 1. This is because if we smash (2,4), then the new array will be [2,7,1,8,1],
them smash (7,8), the new array will be [2,1,1,1], then smash (2,1), the array will be [1,1,1], after that smash (1,1), so only 1 will be there.
*/

