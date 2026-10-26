class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target, sum = 0, n =nums.size();
        for(auto x:nums)sum+=x;
        if(sum %2)return false;//odd
        target = sum/2;
        //we have to make target using only elements in nums
        vector<bool> dp(target+1,false);
        dp[0] = true;
        for(int j=0;j<n;++j){
            for(int i=target;i>=0;--i){
                if(i-nums[j] >=0 && !dp[i]){
                    dp[i] = dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};
