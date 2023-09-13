class Solution {
public:
    void print(vector<int>& c){
        for(int i=0; i<c.size(); i++)
            cout<<c[i]<<",";
        cout<<endl;
    }
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int ans = 1;
        int up = 0, down = 0, peak = 0;
         for (int i = 1; i <n; i++) {
             //ascending
            if (ratings[i-1] < ratings[i]) {
                peak = ++up;
                down = 0;
                ans+= 1+up;
            } 
            //slope=0
            else if (ratings[i-1] == ratings[i])  {
                peak =up = down = 0;
                ans++;
            } 
            else {//decreasing
                up = 0;
                down++;
                ans += down + (peak < down);
            }
        }
        return ans;
    }
};