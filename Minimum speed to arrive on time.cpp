class Solution {
public:

    bool check(vector<int> &dist,int mid,double hour)
    {
        double time = 0;
        int i = 0;
        for(;i<dist.size()-1;i++)
        {
            time+= dist[i]/mid;
            if(dist[i]%mid)
            {
                time++;
            }
        }
        time += 1.0*dist[i]/mid;
        if(time <= hour)
        {
            return true;
        }
        return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(ceil(hour) < dist.size())
        {
            return -1;
        }
        int left = 1;
        int right = 10000000;
        int mid;
        while(left<right)
        {
            mid = (left+right)/2;
            if(check(dist,mid,hour))
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
};