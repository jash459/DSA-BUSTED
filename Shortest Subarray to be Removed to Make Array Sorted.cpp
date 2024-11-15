class Solution{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size();
        int r = n - 1;
        while (r > 0 && arr[r - 1] <= arr[r])
            r--;
        int l = 0, res = r;
        while (l < r && (l == 0 || arr[l - 1] <= arr[l]))
        {
            while (r < n && arr[r] < arr[l])
                r++;
            res = min(res, r - l - 1);
            l++;
        }
        return res;
    }
};
