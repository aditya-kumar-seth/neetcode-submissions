class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        //use bucket sort ---- freq range- (0,n)
        //freq will store the elements 
        vector<vector<int>> bucket(nums.size()+1);
        for(auto entry : hash){
            int element = entry.first;
            int freq = entry.second;
            bucket[freq].push_back(element);
        }
        for(int j = nums.size();j>=0;j--){
            if(ans.size() == k)break;
            for(auto x: bucket[j])
                ans.push_back(x);
        }
        return ans;

    }
};
