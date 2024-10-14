#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int maxKelements(vector<int>& nums, int k) {
    priority_queue<int> pq;

    // Add all elements to the priority queue
    for (int num : nums) {
        pq.push(num);
    }

    int score = 0;

    while (k > 0) {
        int ele = pq.top();
        pq.pop();
        score += ele;
        pq.push(ceil(ele / 3.0));
        k--;
    }

    return score;
}

int main() {
    vector<int> nums = {10, 20, 15};
    int k = 3;

    cout << maxKelements(nums, k) << endl;
    
    return 0;
}
