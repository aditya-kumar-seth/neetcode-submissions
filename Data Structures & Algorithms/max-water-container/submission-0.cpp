class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n =heights.size();
        int answer=0;
        int l=0,r=n-1;
        while(l<=r){
            answer = max(answer, (r-l)*min(heights[r], heights[l]));
            if(heights[l]>heights[r])//move the smaller one
            r--;
            else l++;
            
        }
        return answer;
    }
};
