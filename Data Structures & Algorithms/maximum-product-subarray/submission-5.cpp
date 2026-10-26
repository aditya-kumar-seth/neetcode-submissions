class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pmin=1, pmax = 1;
        int res=INT_MIN;
        for(int i=0;i<n;++i){
            int t = max(nums[i],max( pmax*nums[i], pmin*nums[i]));
            int u = min(nums[i], min(pmax*nums[i], pmin*nums[i]));
            pmax = t;
            pmin =u;
            res = max(res, pmax);
        }   
        return res;
    }
};
