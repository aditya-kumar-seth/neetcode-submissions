class Solution {
public:
    int findMin(vector<int> &nums) {
        int n= nums.size();
        int l=0, r= n-1,mid,ans=INT_MAX;
        while(l <= r){
            mid = l+ (r-l)/2;
            if(nums[mid] >= nums[l]) //left side sorted
            {
                ans = min(ans,nums[l]);//left most will be smallest so compare 
                //move right
                l = mid+1;
            }
            else{//right sorted
                ans = min(ans, nums[mid]);
                r=mid-1;
            }
        }
        return ans;
    }
};
