class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> str;
        vector<int> answer(temperatures.size(), 0);
        for(int i = 0; i< temperatures.size(); ++i) {
            while(!str.empty() && temperatures[i] > str.top().second) {
                answer[str.top().first] = i - str.top().first;
                str.pop();
            }
            str.push(make_pair(i, temperatures[i]));
        }
        return answer;
    }
};

