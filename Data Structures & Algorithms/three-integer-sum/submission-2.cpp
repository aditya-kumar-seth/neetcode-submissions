class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
//        Correct approach
// Instead of fixing two numbers,
// fix one number.
// Then solve a Two Sum problem on the remaining suffix.
    int n =nums.size(); 
    vector<vector<int>> ans;
    int l,r;
    sort(nums.begin(),nums.end());
    for (int i=0;i<n-2;i++){
        if(i>0 && nums[i] == nums[i-1])continue;
        if(nums[i] > 0)break;//since sorted so others cant be -ve
        int target = -nums[i];
        //use two pointers 
        l=i+1,r=n-1;
        while(l<r){
            int sum = nums[l]+nums[r];
            if(sum > target){
                r--;
            }
            else if(sum < target){
                l++;
            }
            else{
                ans.push_back({nums[i],nums[l],nums[r]});
                l++;
                r--;

                //now handle duplicate values
                while(l<r && nums[l] == nums[l-1])l++;
                while(l<r && nums[r] == nums[r+1])r--;
            }
        }
    }
    return ans;
    }

};
