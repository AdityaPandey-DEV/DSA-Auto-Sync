class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        map<char,int> vis;
        int left=0;
        int maxlen=0;
        for(int right=0;right<n;right++){
            char c=s[right];
            if(vis.count(c)){
                left=max(left,vis[c]+1);
            }
            vis[c]=right;
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};