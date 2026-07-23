class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int profit=0;

        // brute force - n^2
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         int temp = prices[j]-prices[i];
        //         if(temp >= 0){
        //             profit= max(profit,temp);
        //         }
        //     }
        // }

        // approach-2
        /*To maximize profit,

            buy at the minimum price.

            So instead of remembering every previous price,

            remember only minimum price so far*/
        int mini=prices[0];//buying price
        for(int i=1;i<n;i++){
            mini = min(mini, prices[i-1]);
            int temp_profit = prices[i] - mini;
            profit = max(profit, temp_profit);
        }
        return profit;
    }
};
