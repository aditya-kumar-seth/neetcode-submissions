class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        // unordered_map <vector<int>, vector<string>> hash;
        //vector cant be hashed to integer 
        // map doesn't use hashing. it uses binary search tree 
        map <vector<int>, vector<string>> hash;
        for(int i=0;i<strs.size();i++){
            vector<int> a(26,0);
            for(int j=0;j<strs[i].size();j++){
                a[strs[i][j] - 'a']++;
            }
            hash[a].push_back(strs[i]);
        }
        for(auto x : hash){
            answer.push_back(x.second);
        }
        return answer;
    }
};
