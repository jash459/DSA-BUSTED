class Solution {
public:
    int equalSubstring(string str, string tar, int maxCost) {
        int n = str.size();
        int left = 0;
        int curr_cost = 0;
        int ans = 0;
        for(int right = 0; right < n; right++)
        {
            curr_cost += abs(str[right] - tar[right]);
            while(left <= right && curr_cost > maxCost)
            {
                curr_cost -= abs(str[left] - tar[left]);
                left++;
            }
            ans = max({ans, right - left + 1});
        }
        return ans;
    }
};
