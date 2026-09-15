class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 1)return nums[0];
        int last1 =0, last2 =0;
        for(int i=0;i<n-1;i++){
             int current = max(last1, last2+nums[i]);
             last2 = last1;
             last1 = current;
        }
        int ans= last1;
        last1=last2=0;
        for(int i=1;i<n;i++){
            int current = max(last1, last2+nums[i]);
            last2 = last1;
            last1 =current;
        }
        ans = max(ans, last1);
        return ans;
    }
};
