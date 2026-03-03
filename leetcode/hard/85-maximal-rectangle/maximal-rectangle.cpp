class Solution {
    
    vector<int>NSL(vector<int>vc){
        stack<pair<int,int>> s;
        int size=vc.size();
        vector<int>v;
        for(int i=0;i<size;i++){
            
            while(!s.empty() && s.top().first>=vc[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }
            else if(s.size()>0 && s.top().first<vc[i]){
                v.push_back(s.top().second);
            }
            s.push({vc[i], i});
        }
        return v;

    }
    vector<int>NSR(vector<int>vc){
        
        stack<pair<int,int>> s;
        int size=vc.size();
        vector<int>v;
        int side=size;
        for(int i=size-1;i>=0;i--){
            
            while(!s.empty() && s.top().first>=vc[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(side);
            }
            else if(s.size()>0 && s.top().first<vc[i]){
                v.push_back(s.top().second);
            }
            s.push({vc[i], i});
        }
        reverse(v.begin(),v.end());
        return v;

    }
    int MAH(vector<int>vc){
        int size=vc.size();
        vector<int>left=NSL(vc);
        vector<int>right=NSR(vc);
        vector<int>v(vc.size(),0);
        int maxArea=0;
        for(int i=0;i<size;i++){
            int area=vc[i]*(right[i]-left[i]-1);
            maxArea=max(area,maxArea);


        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty()) return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> v(cols, 0);

    // Build histogram for first row
    for(int j = 0; j < cols; j++){
        v[j] = (matrix[0][j] == '1') ? 1 : 0;
    }

    int mx = MAH(v);

    // Remaining rows
    for(int i = 1; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == '0'){
                v[j] = 0;
            } else {
                v[j] += 1;
            }
        }
        mx = max(mx, MAH(v));
    }
    return mx;
}
};