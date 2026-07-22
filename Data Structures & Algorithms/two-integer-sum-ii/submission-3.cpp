class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l=0,r=n-1;
        //array is already sorted -- start from right ,move until numbers[i] <= target
        //then move from left to find target-numbers[i]
    
        while (l<n && r>=0 && l<r){
            int sum = numbers[l]+numbers[r];
            if(sum > target){
                r--;
            }
            if(sum < target){
                l++;
            }
            if(sum == target)break;
        }
        return {l+1,r+1};        
    }
};
