class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int bitCount[31] = {0}; 
        for (int num : candidates) {
            for (int i = 0; i < 31; ++i) {
                if (num & (1 << i)) {
                    bitCount[i]++;
                }
            }
        }

        int maxCombinationSize = 0;
        for (int i = 0; i < 31; ++i) {
            maxCombinationSize = max(maxCombinationSize, bitCount[i]);
        }
        
        return maxCombinationSize;
    }
};
