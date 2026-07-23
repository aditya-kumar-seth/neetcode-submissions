class Solution {
public:
    int trap(vector<int>& height) {
        /*
            formula ---- water on bar i= min(lmax,rmax)-height[i] ,0 if -ve 

        approach-1
        har element ke liye lmax aur right max find karo time-n^2
        approach-2
        precalculate lmax and right max vectors space-n,time-n
        approach-3
        use lmax and rmax pointers and move the smaller one only
        */
        int n =height.size();


        // approach-2
        /*vector<int> lmax(n,0), rmax(n,0);
        for(int i=1;i<n;i++){
            lmax[i] = max(lmax[i-1],height[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rmax[i] = max(rmax[i+1],height[i+1]);
        }
        //area calculate
        int area=0;
        for(int i=1;i<n-1;i++){
            int temp = min(lmax[i],rmax[i])-height[i];
            if(temp>0){
                area += temp;
            }
        }
        return area;*/

        // approach-3
        int area=0;
        int l=0,r=n-1,lmax=0,rmax=0;
        while(l<=r){
            if(height[l] <= height[r]){
                // update leftmax
                lmax = max(lmax,height[l]);
                area += lmax-height[l];
                l++;
            }
            else {
                // update rightmax
                rmax = max(rmax, height[r]);
                area += rmax-height[r];
                r--;
            }
        }
        
        return area;
        
    }
};
