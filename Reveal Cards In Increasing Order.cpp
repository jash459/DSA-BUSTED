class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        
        vector<int> res(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++)
            q.push(i);

        for (int i = 0; i < n; i++) {
            int u = q.front();
            q.pop();

            res[u] = deck[i];

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return res;
    }
};
