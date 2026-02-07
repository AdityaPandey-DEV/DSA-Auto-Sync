class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int ans=0;

        for(auto c :s){
            
            if (!st.empty() &&st.top()=='b' &&c =='a'){
                
                    st.pop();
                    ans++;
                }
                else{
                    st.push(c);
                }
            
        }
        return ans;
        
    }
};