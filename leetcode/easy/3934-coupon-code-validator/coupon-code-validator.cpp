class Solution {
    bool checkBusinessLine(string s){
        string arr[4]={"electronics","grocery", "pharmacy", "restaurant"};
        for(int i=0;i<4;i++){
            if(s==arr[i]){
                return true;
            }

        }
        return false;
    }
    bool checkCode(string s){
        if(s==""){
            return false;
        }
        bool ans= true;
        for(int i=0;i<s.length();i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')||s[i]=='_'){
                continue;
            }
            else{
                ans=false;
            }
        }
        return ans;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> ans;
        vector<pair<int,string>>p;
        map<string,int>pri;
        pri["electronics"]=0;
        pri["grocery"]=1;
        pri["pharmacy"]=2;
        pri["restaurant"]=3;

        int n=code.size();
        for(int i=0;i<n;i++){
            if(isActive[i]){
                if(checkBusinessLine(businessLine[i])&&checkCode(code[i])){
                    p.push_back({pri[businessLine[i]],code[i]});
                }
            }

        }
        sort(p.begin(),p.end());
        for(int i=0;i<p.size();i++){
            ans.push_back(p[i].second);
        }
        return ans;
    }
};