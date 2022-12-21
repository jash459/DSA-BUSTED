class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_set<int> one, two;
        
        unordered_map<int, unordered_set<int>> counts;
        for (auto dislike : dislikes) {
            if (dislike[0] <= N && dislike[1] <= N) {
                counts[dislike[0]].insert(dislike[1]);
                counts[dislike[1]].insert(dislike[0]);
            }
        }
        
        stack<int> tog;
        set<int> visit;
        if (N >= 1) tog.push(1);
        while (!tog.empty() || !counts.empty()) {
            int x, b;
            unordered_set<int> neighs;
        
            if (tog.empty()) {
                x = (*begin(counts)).first;
            } else {
                while (!tog.empty()) {
                    x = tog.top();
                    tog.pop();
                    if (!visit.count(x)) break;
                }
                if (visit.count(x)) continue;
            }
            neighs = counts[x];
            visit.insert(x);
            counts.erase(x);
            
            for (int b : neighs) {
                if (one.count(x) && one.count(b) || two.count(b) && two.count(x)) return false;
                if (one.count(x)) {
                    two.insert(b);
                }
                else if (two.count(x)) one.insert(b);
                else {
                    one.insert(x);
                    two.insert(b);
                } 
                if (!visit.count(b)) tog.push(b);
            }
        }
            
        return true;
    }
};