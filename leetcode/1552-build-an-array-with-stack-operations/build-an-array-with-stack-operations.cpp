class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int ind=0;
        for(int i=1;i<=n;i++){
            if(ind==target.size()){
                break;
            }
            if(i==target[ind]){
                ans.push_back("Push");
                ind++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;

        
    }
};