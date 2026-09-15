class Solution {
public:
    int rob(vector<int>& nums) {
      int last1=0, last2=0;
      for(int money:nums){
        int current = max(last1, last2+money);
        last2 = last1;
        last1 = current;
      }
      return last1;
    }
};
