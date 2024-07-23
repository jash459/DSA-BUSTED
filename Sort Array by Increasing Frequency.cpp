
//Map
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }
        
        sort(nums.begin(), nums.end(), [&freq_map](int a, int b) {
            if (freq_map[a] != freq_map[b]) {
                return freq_map[a] < freq_map[b];
            }
            return a > b;
        });
        
        return nums;
    }
};
