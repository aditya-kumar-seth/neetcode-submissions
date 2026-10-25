class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        //base case 
        dp[0] = 1;//empty case
        if(s[0] == '0')return 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            //when we add two digits ---- no. b/w 10-26
            int dnum = 10*(s[i-2]-'0') + (s[i-1]-'0');
            cout<<dnum<<endl;
            if(dnum >=10 && dnum <=26){
                dp[i] += dp[i-2];
            }
            //when we add single digit --- no. b/w 1-9
            int snum = (s[i-1]-'0');
            cout<<snum;
            if(snum != 0){
                dp[i] += dp[i-1];
            }
        }
        return dp[n];

    }
};
