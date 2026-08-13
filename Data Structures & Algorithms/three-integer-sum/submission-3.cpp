class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        int n = nums.size();
        //target would be -(nums[l] + nums[r])
       for(int i=0;i<n-2;i++){
        if(nums[i]>0)break;
        if(i >0 && nums[i] == nums[i-1])continue;
        int target = -nums[i];
        int l=i+1,r=n-1;
        while(l<r){
            int sum = nums[l] + nums[r];
            if(sum == target){
            st.insert({nums[i],nums[l],nums[r]});
            l++;
            r--;
            }
            else if (sum > target)r--;
            else l++;
        }
       }
        vector<vector<int>> answer;
        for(auto element : st){
            answer.push_back(element);
        }
        return answer;
    }
};
