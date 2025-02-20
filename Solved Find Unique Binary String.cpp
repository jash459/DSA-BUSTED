class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s(nums.begin(), nums.end());
        string curr;
        return generateBinaryString(nums.size(), s, curr);
    }
    
    string generateBinaryString(int n, unordered_set<string>& set, string& curr) {
        if (curr.size() == n) {
            return set.count(curr) ? "" : curr;
        }
        curr.push_back('0');
        string res = generateBinaryString(n, set, curr);
        if (!res.empty()) return res;
        curr.back() = '1';
        res = generateBinaryString(n, set, curr);
        if (!res.empty()) return res;
        curr.pop_back();
        return "";
    }
};
