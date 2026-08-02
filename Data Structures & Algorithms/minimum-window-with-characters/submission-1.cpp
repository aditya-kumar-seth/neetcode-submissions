class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<char , int> needed, window;
        int itemRequired = 0;
        //created the needs
        for(char item : t){
            if(needed.find(item) == needed.end())//new item
                itemRequired++;
            needed[item]++;
        }
        string answer= "";
        int right = 0, left = 0, satisfied = 0;
        for(right = 0; right < n; right ++){
            char item = s[right];
            //add items to window and if its in needed map it
            if(needed.find(item) != needed.end()){
                window[item]++;//first add the item
                if(window[item] == needed[item])satisfied++;
            }
            //check if all items are satisfied then shrink window
            while(satisfied == itemRequired){
                string valid = s.substr(left,right-left+1);
                if(answer.size() == 0)answer = valid;
                answer = ( answer.size() > valid.size() ) ? valid : answer;
                char excess = s[left];
                // if this item is in excess discard this 
                if(window.find(excess) != window.end()){
                    window[excess]--;
                    //after discarding item check if we go below required
                    if(window[excess] < needed[excess]){
                    satisfied --;}
                }
                left++;
            }
        }

        return answer;
    }
};
