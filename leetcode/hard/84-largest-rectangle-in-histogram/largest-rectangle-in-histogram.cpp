class Solution {
    vector<int>nsef(vector<int>& heights){
        int n=heights.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty())ans[i]=st.top();
            else ans[i]=n;
            st.push(i);
        }
        return ans;
    }
    vector<int>lsef(vector<int>& heights){
        int n=heights.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty())ans[i]=st.top();
            else ans[i]=-1;
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>lse=lsef(heights);
        vector<int>nse=nsef(heights);
        int maxarea=0;
        for(int i=0;i<n;i++){
            int width=nse[i]-lse[i]-1;
            int height=heights[i];
            int area=width*height;
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};