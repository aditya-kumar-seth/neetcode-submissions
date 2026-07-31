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
        int n = s.size();
// ================================================================
        //approach -1:-------------------o(n^2)
        //int maxFreq=0,ans=0;
        /*for(int i=0;i<n;i++){
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
        }*/
// =================================================================

        //approach -2:
        vector<int> count(26, 0);
        int left = 0, maxFreq = 0, ans = 0;

        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
