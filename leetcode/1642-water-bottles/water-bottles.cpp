class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        long long ans=numBottles;
        while( numBottles>=numExchange)
        {
            int newBottles=numBottles/numExchange;
            
            int r=numBottles%numExchange;
            ans+=newBottles;
            numBottles=newBottles+r;
            

        }
        
        return ans;
        
    }
};