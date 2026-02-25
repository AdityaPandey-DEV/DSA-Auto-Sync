class Solution {
    static bool compare(int a,int b){
        int countA=__builtin_popcount(a);
        int countB=__builtin_popcount(b);
        if(countA==countB){
            return a<b;
        }
        return __builtin_popcount(a)<__builtin_popcount(b);
        
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};