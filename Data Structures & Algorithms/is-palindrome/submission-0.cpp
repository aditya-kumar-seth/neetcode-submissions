class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        for(char c : s){
            if(isalnum(c) ){
                ans+=c;
            }
        }
        int n = ans.size();
        for(int i=0;i<=n/2;i++){
            if(tolower(ans[i]) !=tolower( ans[n-1-i]))return false;
        }
        return true;
    }
};
