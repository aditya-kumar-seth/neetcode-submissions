class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //The first integer of every row is greater than the last integer of the previous row. means columns are also sorted
        //find in rows then find in columns
        int row = matrix.size(), col = matrix[0].size();
        for(int i=0;i<row;i++){
            int l=0,r=col-1,mid;
            while(l<=r){
            mid = (r-l)/2 +l;
            if(matrix[i][mid] == target)return true;
            else if(matrix[i][mid] > target)r=mid-1;
            else l=mid+1;
        }
        }
        return false;
        
    }
};
