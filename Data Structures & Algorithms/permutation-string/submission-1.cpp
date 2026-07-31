class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int m = s1.size();
        unordered_map<char , int> hash;
        for(char c : s1){
            hash[c]++;
        }
        int left=0;
        unordered_map <char, int> hash2;
        for(int right =0;right<n;right++){
                hash2[s2[right]]++;
            if(right-left+1 < m){//add if window is smaller
                continue;
            }
            if(hash == hash2)return true;
            hash2[s2[left]]--;
            if(hash2[s2[left]] == 0)hash2.erase(s2[left]);
            left++;
        }
        return false;
    }
};
