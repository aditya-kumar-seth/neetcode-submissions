class Solution {
public:
    int S;
    int findTargetSumWays(vector<int>& nums, int target) {
        S=0;
        for(int i=0;i<nums.size();i++)S+=nums[i];
        //target will for sure lie between -S to S

        vector<vector<int>> dp(20,vector<int>(2*S+1, -1));
        //we cant use negative index so i shifted every thing by S
        return solve(0, S+target, nums, dp);
    }
    int solve(int i, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target <0 || target >2*S)return 0;
        if(target == S && i == nums.size())return 1;
        else if (i == nums.size())return 0;
        if(dp[i][target] !=-1)return dp[i][target];
        return dp[i][target] = solve(i+1, target-nums[i], nums, dp)+ solve(i+1, target+nums[i], nums, dp);
    }
};
