class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>>  temp;

    for (int i = 0; i < tasks.size(); i++)
    {
        temp.push_back({tasks[i][0], tasks[i][1], i});
    }

    sort(temp.begin(), temp.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    long long curr = temp[0][0];
    vector<int> result;
    int i = 0, n = tasks.size();

    while (i < n || !pq.empty())
    {

        while (i < n && curr >= temp[i][0])
        {
            pq.push({temp[i][1], temp[i][2]});
            i++;
        }

        auto p = pq.top();
        curr += p.first;
        result.push_back(p.second);
        pq.pop();

        if (i < n && pq.empty() && curr < temp[i][0])
        {
            curr = temp[i][0];
        }
    }
    return result;
    }
};