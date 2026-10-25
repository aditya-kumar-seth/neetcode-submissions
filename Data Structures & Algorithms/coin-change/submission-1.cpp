class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int int_max = 1e9, n =coins.size();
        vector<int> dp(amount+1, int_max);
        dp[0] = 0;
        for(int j=0;j<n;++j){
            for(int i=1;i<=amount;++i){
                if(i-coins[j]>=0)dp[i] = min(dp[i], 1+dp[i-coins[j]]);
            }
        }
        if(dp[amount]!=int_max)return dp[amount];
        return -1;}
};
