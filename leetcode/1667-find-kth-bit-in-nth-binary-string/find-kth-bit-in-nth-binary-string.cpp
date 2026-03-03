class Solution {
    string invert(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                s[i]='1';
            }
            else{
                s[i]='0';
            }
        }
        return s;
    }
public:
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=1;i<n;i++){
            string temp=s;
            string in=invert(temp);
            reverse(in.begin(),in.end());
            s=temp+"1"+in;
        }
        return s[k-1];
        
    }
};