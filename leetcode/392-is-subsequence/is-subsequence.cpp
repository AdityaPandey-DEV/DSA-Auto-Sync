class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        int nm=max(n,m);
        bool ans =false;
        int j=0;
        for(int i=0;i<nm;i++){
            if(s[j]==t[i]){
                j++;
            }

        }
        if(j==n){
            ans=true;
        }
        return ans;
        
    }
};