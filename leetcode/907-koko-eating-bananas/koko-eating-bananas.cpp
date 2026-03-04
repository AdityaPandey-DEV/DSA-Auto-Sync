class Solution {
    bool canEat(vector<int>& piles,int mx,int h){
        int hour=0;
        int sum=0;
        for(int i=0;i<piles.size();i++){
            hour += (piles[i] + mx - 1) / mx;
            if(hour>h) return false;

        }
        return true;

    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right =*max_element(piles.begin(),piles.end());
        int res=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            
            if(canEat(piles,mid,h)){
                res=mid;
                right=mid-1;

            }
            else{
                left=mid+1;
            }
        }
        return res;
        
    }
};