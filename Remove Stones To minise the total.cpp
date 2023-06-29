class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans = accumulate(begin(piles), end(piles), 0);
        priority_queue<int> pq(begin(piles), end(piles)); //O(nlog(n))
		//But note that there is a way to construct Heap from array in O(n)
        while(!pq.empty() && k--) { //O(klog(n))
            int curr = pq.top();
            pq.pop();
            
            ans     -= floor(curr/2);
            curr    -= floor(curr/2);
            
            pq.push(curr);
        }
        
        return ans;
    }
};