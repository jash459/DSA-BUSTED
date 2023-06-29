class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        if(p.size() == 0) return 0;
        sort(p.begin(), p.end());
        int last_point = p[0][1];
        int result = 1;
        for(auto point : p) {
            if(point[0] > last_point) {
                result++;
                last_point = point[1];
            }
            last_point = min(point[1],last_point);
        }
        return result;
    }
};