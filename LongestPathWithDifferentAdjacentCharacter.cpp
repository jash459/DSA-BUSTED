class Solution {
public:
    vector<int> child[100001];
    int result;
    int LongestPath(string &s, int curr_node)
    {
        if(child[curr_node].empty())return 1;
        int max1 = 0, max2=0;
    // traversing over all the child nodes of the curr_node
        for(auto &child_node : child[curr_node])
        {
        // recursively trying for child nodes
            int len = LongestPath(s, child_node);
            result = max(result , len);
     // rejecting the current node if it's of same character
            if(s[curr_node] == s[child_node])continue;
 // updating the max1 and max2paths that we can take from all the children of the given node
            if(len > max1)
            {
                max2= max1;
                max1 = len;
            }
//seecond max will be updated
            else max2= max(max2, len);
        }
// Update the result.
//Again, max1+max2+1 meresult the length of the longest valid path 
//going through this node in the sub-tree rooted at this node
        result = max(result, 1 + max1 + max2);
//Adding 1 for the current node
        return 1 + max1;
    }
    int longestPath(vector<int>& parent, string s){
        int n = parent.size();
        for(int i=1;i<n;i++)child[parent[i]].push_back(i);
        result = 1;
        LongestPath(s,0);
        return result;
    }
};