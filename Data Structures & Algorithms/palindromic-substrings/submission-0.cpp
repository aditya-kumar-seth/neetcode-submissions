class Solution {
public:
    int countSubstrings(string s) {
     int ans=0;
        int n = s.size();
        if(n<=1)return n;
        for(int i=0;i<n;++i){
            int left{-1}, right{-1}, count{0};
            //odd length case
            left= right = i;
            count=1;
            while(left>=0 && right <n){
                if(s[left] != s[right])break;
                ans++;
                --left;
                ++right;
            }
            //even length case 
            left = i, right = i+1;
            count =0;
            while(left >=0 && right <n){
                if(s[left] != s[right])break;
                ans++;
                --left;
                ++right;
            }
        }
        return ans;   
    }
};
