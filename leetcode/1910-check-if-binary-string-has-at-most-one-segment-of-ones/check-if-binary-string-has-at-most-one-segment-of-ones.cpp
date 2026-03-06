class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s[0]=='0') return false;
        int n=s.size();
        if(n==1) return true;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                if(s[i-1]!=s[i]){
                    cnt++;
                }
            }
        }
        if(cnt==1) return true;
        return false;
        
    }
};