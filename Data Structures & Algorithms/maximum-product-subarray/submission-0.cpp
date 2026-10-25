class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,1), suffix(n,1);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1]; 
        for(int i=1;i<n;++i){
            if(prefix[i-1] == 0)prefix[i] = nums[i];
            else prefix[i] = prefix[i-1]*nums[i];
            if(suffix[n-i] == 0)suffix[n-i-1] = nums[n-i-1];
            else suffix[n-i-1] = suffix[n-i]*nums[n-i-1];
        }
        int ans=-10;
        for(int i=0;i<n;i++){
            ans = max(ans,prefix[i]);
            ans = max(ans,suffix[i]);
        }
        return ans;
    }
};
