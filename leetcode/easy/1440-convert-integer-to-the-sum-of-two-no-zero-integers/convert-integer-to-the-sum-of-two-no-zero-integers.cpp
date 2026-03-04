class Solution {
private:
bool hasZero(int n){
    while(n!=0){
        int a=n%10;
        n=n/10;
        if(a==0){
            return true;
        }
        
    }
    return false;
}
public:
    vector<int> getNoZeroIntegers(int n) {
       
        int a,b;
        for(int a=1;a<n;a++){
            b=n-a;
            if(!hasZero(a) && !hasZero(b)){
                
                return{a,b};
            }
        }

        return{};
    }
};