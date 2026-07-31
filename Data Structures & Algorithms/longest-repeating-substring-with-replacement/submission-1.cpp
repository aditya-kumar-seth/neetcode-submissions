class Solution {
public:
    int characterReplacement(string s, int k) {
        /*
        a substr is valid when [len-maxfreq] <=k
        approach -1 :
        find all substr and check for validity
        approach -2 :
        use sliding window
        */
        //approach -1:
        int n = s.size();
        int maxFreq=0,ans=0;
        for(int i=0;i<n;i++){
            int hash[26] = {0};
            for(int j=i;j<n;j++){
                hash[s[j] - 'A']++;
                maxFreq = max(maxFreq, hash[s[j] - 'A']);
                if((j-i+1) - maxFreq <=k){
                    ans = max(ans,(j-i+1));
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};
