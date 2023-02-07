class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> ans; // hash map to store the frequency of the elements in the subarray
        int i, j; // variables i and j are used to keep track of the subarray boundaries
        for (i = 0, j = 0; j < fruits.size(); ++j) {
            ans[fruits[j]]++; // increase the ans of the current fruit
            if (ans.size() > 2) { 
                if (--ans[fruits[i]] == 0)ans.erase(fruits[i]); // reduce the ans of the first fruit and remove it from the map if its ans becomes 0
                i++; // move the start of the subarray to the right
            }
        }
        return j - i; // return the length of the longest subarray with at most two unique elements
    }
};