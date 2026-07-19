class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> hash;
        int a,b,residual;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            a = i;
            residual = target - nums[a];
            if(hash.find(residual) != hash.end() && hash[residual] != a){
                b = hash[residual];
                break;
            }
        }
        return {a,b};
    }
};
