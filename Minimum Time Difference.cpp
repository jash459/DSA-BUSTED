class Solution {
private:
    int helper(string time){
        int hour = ((time[0] - '0')*10 + (time[1] - '0'));
        int minu = ((time[3] - '0')*10 + (time[4] - '0'));
        return hour * 60 + minu;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Note
        // We need to find the minumum minutes difference between any two timePoints that are provided within the vector
        vector<int> processed;
        for(auto &ele : timePoints) processed.push_back(helper(ele));
        sort(processed.begin(), processed.end());
        int n = processed.size();
        int ans = INT_MAX;
        for(int i = 1 ; i < n ; i++) ans = min(ans, processed[i] - processed[i - 1]);
        ans = min(ans, (1440 - processed[n - 1]) + processed[0]);
        return ans;
    }
};
