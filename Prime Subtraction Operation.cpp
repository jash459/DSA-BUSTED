class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> p;
        int i,j;
        for(i = 2; i <= 1000; i++){
            for(j = 2; j <= sqrt(i); j++){
                if(i%j==0)break;
            }
            if(j>sqrt(i)){
                p.push_back(i);
            }
        }
        for(i = 0; i < nums.size(); i++){
            if(nums[i]<=2)continue;
            int a = 0, b = p.size()-1,k=-1,mid;
            while(a<=b){
                mid = (b-a)/2+a;
                if(p[mid]<=nums[i]){
                    k = mid;
                    a = mid+1;
                }else{
                    b = mid-1;
                }
            }
            if(p[k]==nums[i])k--;
            if(k==-1)continue;
            cout<<p[k]<<" ";
            if(i==0){
                nums[0] = nums[0]-p[k];
            }
            else{
                for(j = k;j>=0;j--){
                    if(nums[i-1]<nums[i]-p[j]){
                        nums[i] = nums[i]-p[j];
                        break;
                    }
                }
                if(nums[i]<=nums[i-1])return false;
            }
            cout<<nums[i]<<endl;
        }
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1]>=nums[i])return false;
        }
        return true;
    }
};
