class Solution {
public:
    int trap(vector<int>& height) {
        /*
            formula ---- water on bar i= min(leftmax,rightmax)-height[i] ,0 if -ve 

        approach-1
        har element ke liye leftmax aur right max find karo time-n^2
        approach-2
        precalculate leftmax and right max vectors space-n,time-n
        approach-3
        use leftmax and rightmax pointers and move the smaller one only
        */
        int n =height.size();


        // approach-2
        vector<int> leftmax(n,0), rightmax(n,0);
        for(int i=1;i<n;i++){
            leftmax[i] = max(leftmax[i-1],height[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rightmax[i] = max(rightmax[i+1],height[i+1]);
        }
        //area calculate
        int area=0;
        for(int i=1;i<n-1;i++){
            int temp = min(leftmax[i],rightmax[i])-height[i];
            if(temp>0){
                area += temp;
            }
        }
        return area;
        
    }
};
