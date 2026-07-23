class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        /*
        variable lenght sliding window 
        l->shrink if unvalid else  r->expand  

        used when contigous subarray, no fixed window 
        */
        int n = s.size();
        int ans=0,left=0;
        unordered_set<int> window;//contains unique elements
        for(int right =0;right<n;right++){//expand one by one
            while(window.count(s[right])){
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            ans = max(right-left+1,ans);
        }
        return ans;
    }
};
