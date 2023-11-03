class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j = 0;
        int size = target.size();
        vector<string>ans;
        int curr =1;
        while(j<size && curr<=n){
            int limit = target[j];
            if(limit == curr) {
                ans.push_back("Push");
                curr++;
                }
            else if(limit>curr){
                int diff = limit-curr;
                for(int i=0;i<diff;i++)ans.push_back("Push");
                for(int i=0;i<diff;i++)ans.push_back("Pop");
                ans.push_back("Push");
                curr = limit+1;
            }
            j++;
        }
        return ans;  
    }
};
