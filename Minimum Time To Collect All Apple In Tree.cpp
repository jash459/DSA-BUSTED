class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        //Keep track of parents.
        vector<int> parent(n,-1);
        int i;
        for(i=0;i<edges.size();i++)
        {
            if(parent[edges[i][1]]==-1)
            {
                parent[edges[i][1]] = edges[i][0];
            }
            else
            {
                parent[edges[i][0]] = edges[i][1];
            }
        }
        int ans=0;
        bool flag = true;
        while(flag)
        {
            flag = false;            
            for(i=(n-1);i>0;i--)
            {
                //Here it will giving apple to it's parent if it has any
                if(hasApple[i])
                {
                    flag = true; 
                    hasApple[i] = false;
                    hasApple[parent[i]]=true;
                    ans+=2;
                }
            }
        }
        return ans;
    }
};Number of Nodes in the Sub-Tree With the Same Label
Medium
777
529
