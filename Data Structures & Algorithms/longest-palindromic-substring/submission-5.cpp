class Solution {
public:
    string longestPalindrome(string s) {
        int reslen{INT_MIN}, res=0;
        int n = s.size();
        if(n<=1)return s;
        for(int i=0;i<n;++i){
            int left{-1}, right{-1}, count{0};
            //odd length case
            left= right = i;
            count=1;
            while(left>=0 && right <n){
                if(s[left] != s[right])break;
                count = right - left + 1;
                if(reslen < count){
                    res = left;
                    reslen = count;
                }
                --left;
                ++right;
            }
            //even length case 
            left = i, right = i+1;
            count =0;
            while(left >=0 && right <n){
                if(s[left] != s[right])break;
                count = right - left +1;
                if(reslen< count){
                    res = left;
                    reslen = count;
                }
                --left;
                ++right;
            }
        }
        if(reslen == INT_MIN)reslen = 1;
        return s.substr(res, reslen);
    }
};
