class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        //initializing helping variables
        int n = grid.size();
        int res = -1;

        //initializing queue for 
        queue<pair<pair<int,int>,int>> q;
        //initializing utility matrix for BFS
        vector<vector<int>> util(n , vector<int> (n,-1));

        //these two vectors for traversing nodes as (left,up,right,down)
        vector<int> drow {0,-1,0,1};
        vector<int> dcol {-1,0,1,0};

        //pushing all land nodes in queue with initial distance as 0
        for(int i=0; i<n; i++)  {
            for(int j=0; j<n; j++)  {
                if(grid[i][j]==1)   {
                    q.push({{i,j},0});
                    util[i][j] = 0;
                }
            }
        }
      
        //  BFS
        while(!q.empty())   {
            auto t = q.front();
            q.pop();
            int r = t.first.first;
            int c = t.first.second;
            int d = t.second;

            for(int i=0; i<4; i++)  {
                int dr = r + drow[i];
                int dc = c + dcol[i];

                //checking is its an unvisited water node or not.
                if(dr>=0&&dr<n&&dc>=0&&dc<n&&grid[dr][dc]==0&&util[dr][dc]==-1) {
                    q.push({{dr,dc},d+1});
                    util[dr][dc] = d+1;

                   //updating our res(maximum distnace) if possible
                    if(d+1!=0)  {
                        res = max(res,d+1);
                    }
                }
            }
        }

        return res;
    }
};