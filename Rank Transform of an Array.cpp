class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> ranks;
        for (auto el : arr) ranks[el];
        int cur = 1;
        for (auto &[el, rank] : ranks) rank = cur++;
        for (auto &el : arr) el = ranks[el];
        return arr; 
    }
};
