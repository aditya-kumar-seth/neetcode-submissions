class Solution {
public:

    string encode(vector<string>& strs) {
        //LIST TO STRING 
        // aditya, aman ------ 6#aditya4#aman
        string encoded_string;
        for( int i=0; i<strs.size();i++){
            int len = strs[i].size();
            encoded_string += to_string(len);
            encoded_string += '#';
            encoded_string += strs[i];
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        //STRING TO LIST
        vector<string> decoded_strs;
        int i=0;
        while(i<s.size()){
            //fetch the string length 
            string len;
            while(isdigit(s[i])){
                len += s[i];
                i++;
            }
            int leni = stoi(len);
            //ignore the # after leni
            i++;
            string str;
            int j=0;
            while(j<leni){
                str += s[i];
                j++;
                i++;
            }
            decoded_strs.push_back(str);
        }
        return decoded_strs;
    }
};
