class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       if(n==1)return 0;
       vector<int> dp(n,0);
//dp[i] = maximum total profit till day i
       dp[0]=0;//on day 0 we can only buy not sell 
       dp[1] = max(prices[1]-prices[0], 0);

       /*
        suppose we buy on day j
            then we can't buy on day j-1
            also we cant sell on day j-1, since we need to wait 1 day after selling
        so day j-1 is cooldown

        for every i (selling day) find the best j (buying day) this will give best profit for that day, lets say its p_day
        total max profit = dp[j-2]+p_day

       */

        for(int i=2;i<n;++i){
            dp[i] = dp[i-1];//suppose later we dont buy then previous total profit will be answer
            for(int j=i-1;j>=0;--j){
                int p_day = prices[i] - prices[j];//assume j is buying day
                int p_previous = (j-2>=0) ? dp[j-2] : 0;
                dp[i] = max(dp[i], p_day+p_previous);
            }
        }
        return dp[n-1];
    }
};
