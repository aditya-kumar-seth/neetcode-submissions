class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1] = 1;//ways to reach step 1
        for(int i = 2;i<=n;i++){
            if(i-2>=0)dp[i] = dp[i-1]+dp[i-2];
        } 
        return dp[n];
    }
};
