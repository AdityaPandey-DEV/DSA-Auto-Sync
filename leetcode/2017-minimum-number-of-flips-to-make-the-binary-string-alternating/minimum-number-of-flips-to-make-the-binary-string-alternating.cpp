class Solution {
public:
    int minFlips(string s) {
        int n=s.length();
        s=s+s;
        int m=s.length();
        vector<int>s1(m,0);
        vector<int>s2(m,0);
        int cnt1=0;
        for(int i=0;i<m;i++){
            if(i%2==0){
                if(s[i]!='0'){
                    s1[i]=1;
                }
                
            }
            else {
                if(s[i]!='1'){
                    s1[i]=1;
                }
            }

        }
        int cnt2=0;
        for(int i=0;i<m;i++){
            if(i%2==0){
                if(s[i]!='1'){
                    s2[i]=1;
                }
            }
            else{
                if(s[i]!='0'){
                    s2[i]=1;
                }
            }

        }
        for(int i=0;i<n;i++){
            cnt1+=s1[i];
            cnt2+=s2[i];
        }
        int min12 = min(cnt1, cnt2);
        for(int i=n;i<m;i++){
            cnt1+=s1[i];
            cnt1-=s1[i-n];
            cnt2+=s2[i];
            cnt2-=s2[i-n];
            min12=min(min12,min(cnt1,cnt2));
        }
        return min12;
    }
};