class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        return accumulate(values.begin(), values.end(), 0, 
        [dp=0, i=0](int score, int x) mutable{
            score=max(score, dp+x-i);
            dp=max(dp, x+i++);
            return score;
        });
    }
};
