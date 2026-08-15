class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        long long l=1, r=INT_MIN,speed,valid_speed;
        for(auto bananas : piles){
            r = max(r, (long long)bananas);//maximum 1 largest pile an hour
        }
        while(l <=r){
            speed = (r-l)/2 +l;
            //check if this speed exceeds h or not
            long long hours=0;
            for(int i=0;i<n;i++){
                hours += (piles[i] + speed-1)/speed;
            }
                if(hours > h)l=speed+1;//taking more time so eat fast
                else {//taking less time so can eat a bit slower
                    valid_speed = speed;
                    r = speed-1;
                }
            
        }
        return valid_speed;
    }
};
