class Solution {
    void rec(string &s,vector<string> &r,int n){
        if(s.size()==n){
            r.push_back(s);
            return;
        }
        for(char ch='a';ch<='c';ch++){
            if(!s.empty()&&s.back()==ch){
                continue;

            }
            s.push_back(ch);
            rec(s,r,n);
            s.pop_back();
            
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string> r;
        string s;
        rec(s,r,n);
        if(r.size()<k){
            return "";
        }
        return r[k-1];
        
    }
};