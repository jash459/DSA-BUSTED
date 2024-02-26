class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> degree(N+1, 0);
        
        for(auto t : trust){
            degree[t[0]]--; //outdegree of a node
            degree[t[1]]++; //indegree of a node
        }
        for(int i=1; i<=N; i++){  
            if(degree[i]==N-1) return i;
        }
        return -1;
    }
};
//The town judge trusts nobody. -> 0
//Everybody (except for the town judge) trusts the town judge. -> n -1