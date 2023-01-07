class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalgas=0,totalcost=0;
        int currgas=0, startingpoint=0;
        for(int i=0;i<n;i++)
        {
            //these two variable are to check if no case is possible
            totalgas+=gas[i];
            totalcost+=cost[i];
            //for checking the total present gas at index i
            currgas+=gas[i]-cost[i];
            if(currgas<0)
            {
               //there is a breakdown....so we will start from next point or index
                startingpoint=i+1;
                //reset our fuel 
                currgas=0;
            }
        }
        return (totalgas<totalcost)?-1:startingpoint;     
    }
};
