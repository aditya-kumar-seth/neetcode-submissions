class Solution {
public:
void maxi(int &a, int b){
    if(a<b)a=b;
}
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=0;i<=m;++i){
            for(int j=0;j<=n;++j){
                if(i-1>=0)maxi(dp[i][j], dp[i-1][j]);
                if(j-1>=0)maxi(dp[i][j], dp[i][j-1]);
                if(i-1>=0 && j-1>=0){
                    maxi(dp[i][j], dp[i-1][j-1] + (text1[i-1] == text2[j-1]));
                }
            }
        }
        return dp[m][n];
    }
};
