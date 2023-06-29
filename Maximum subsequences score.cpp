class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n = nums1.size();
        vector<pair<int, int>>v;
        for (int i = 0; i < n; i++) v.push_back({nums2[i], nums1[i]});
        sort(v.begin(), v.end()); //sort in ascending order of "nums2" value
        //===============================================================================
        priority_queue<int, vector<int>, greater<int>>pq; //Min PQ for nums1 values
        long long  sum = 0;
        //directly add the largest (considering nums2 value) k values in PQ
        for (int i = n - 1; i >= (n - k); i--) 
        {
            pq.push(v[i].second);
            sum += v[i].second;
        }
        long long score = v[n - k].first * sum;
        long long mxScore = score;
        //=================================================================================
        for (int i = n - k - 1; i >= 0; i--)
        {
            int minNum1 = pq.top(); //minimum nums1 value
            pq.pop(); //first remove smallest nums1 Value, PQ size = k - 1
            
            sum += v[i].second; //compulsory to take
            sum -= minNum1;
            
            pq.push(v[i].second); //now push the num1 Value, PQ size = k
            long long score = v[i].first * sum;
            mxScore = max(mxScore, score);
        }
        //=========================================================================================
        return mxScore;
    }
};