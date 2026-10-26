class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st;
        for(auto words : wordDict)st.insert(words);
        vector<bool> dp(n+1, false);
        //base case
        dp[0] = 0;//dp[i] --first i characters can be broken in  valid words
        for(int i=1;i<=n;i++){
            //i represent the number of chars from start 
            if(st.find(s.substr(0, i))!= st.end()) {
                dp[i] = true;
                continue;
            }
            int j=i-1;//1 less char than i
            while(j>=1){
                if(dp[j]==true && st.find(s.substr(j,i-j)) != st.end())
                {
                    dp[i] = true;
                    break;
                }
                j--;
            }
        }
        return dp[n];
    }
};
