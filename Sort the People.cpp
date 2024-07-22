class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int, string>> pq;
        for (int i = 0; i < names.size(); i++)
            pq.push({heights[i], names[i]});
        int i = 0;
        while (!pq.empty()){
            names[i++] = pq.top().second;
            pq.pop();
        }
        return names;
    }
};
