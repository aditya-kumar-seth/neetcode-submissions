class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // vector<bool> rows(9),columns(9);
        for(int i=0;i<9;i++){
            unordered_map<char,int> hash;
            //check rows
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                if(hash.find(board[i][j]) != hash.end())return false;//met before
                hash[board[i][j]]++;}
            }
            //check cols
            hash.clear();
            for(int j=0;j<9;j++){
                if(board[j][i] != '.')
                {if(hash.find(board[j][i]) != hash.end())return false;//met before
                hash[board[j][i]]++;}
            }
        }
        for(int rows=0;rows<9;rows+=3){
            for(int cols=0;cols<9;cols+=3){
                //now each boxes
                unordered_map<char,int> hash;
                for(int i=rows;i<rows+3;i++){
                    for(int j=cols;j<cols+3;j++){
                        if(board[i][j] != '.'){
                            if(hash.find(board[i][j]) != hash.end())return false;
                            hash[board[i][j]]++;
                        }
                    }
                }
            }
        }

        return true;
    }
};
