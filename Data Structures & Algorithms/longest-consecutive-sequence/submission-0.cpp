class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int ans=0;

        int n = nums.size();
        //put every element in hash
       unordered_map<int,int> hash;
       for(auto ele:nums){
        hash[ele] = 0;
       } 
        //if nums[i]-1 exist it cant be a start 
        for(int i=0;i<n;i++){
            if(hash[nums[i]] == 0 && hash.find(nums[i]-1) == hash.end()){
                //nums[i] can be a start of the seq
                hash[nums[i]]++;
                int k=1,l=i;
                while(hash.find(nums[l]+1) != hash.end()){
                    k++;
                    hash[nums[l]+1]++;
                    nums[l]++;
                }
                ans=max(ans,k);
            }
        }
        return ans;
    }
};
