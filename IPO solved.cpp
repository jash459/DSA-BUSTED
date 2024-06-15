class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> project(n);
        for (int i = 0; i < n; i++) {
            project[i] = {capital[i], profits[i]};
        }
        sort(project.begin(), project.end());
        int i = 0;
        priority_queue<int> maximizeCapital;
        while (k--) {
            while (i < n && project[i].first <= w) {
                maximizeCapital.push(project[i].second);
                i++;
            }
            if (maximizeCapital.empty())
                break;
            w += maximizeCapital.top();
            maximizeCapital.pop();
        }
        return w;
    }
};
