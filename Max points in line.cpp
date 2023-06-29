class Solution {
public:
    int maxPoints(vector<vector<int>>& pt) {
        int result=1; 
        int n=pt.size();
       // slope of every point with selected point
        for(int i=0;i<n-1;i++){
            map<double,int> mpp;
            for(int j=i+1;j<n;j++){
                if(pt[j][1]==pt[i][1]) 
                mpp[-90]++;//i assume slope to avoid slope of 90 degree(we can say that is Perpendicular line) 
                else{ 
                    double x = (double)(pt[j][0]-pt[i][0])/(double)(pt[j][1]-pt[i][1]);
                    //storing the slop into map
                    mpp[x]++;
                }
            }
            // same slope w.r.t.that selected point
            int tempp = 0;
            for(auto it:mpp)
                tempp = max(tempp, it.second+1);    // +1 for the current point(point itself)
            result = max(tempp, result);
        }
        return result;
    }
};