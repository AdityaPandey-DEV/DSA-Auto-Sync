class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int size=arr.size();
        int minDiff=INT_MAX;
        for(int i=0;i<size-1;i=i+1){
            if(arr[i+1]>arr[i]){
                if(minDiff>(arr[i+1]-arr[i])){
                    minDiff=arr[i+1]-arr[i];
                    while(ans.size()!=0){
                        ans.pop_back();
                    }
                    ans.push_back({arr[i],arr[i+1]});
                }
                else if(minDiff==(arr[i+1]-arr[i])){
                    ans.push_back({arr[i],arr[i+1]});
                }
            }
        }
        return ans;
        
    }
};