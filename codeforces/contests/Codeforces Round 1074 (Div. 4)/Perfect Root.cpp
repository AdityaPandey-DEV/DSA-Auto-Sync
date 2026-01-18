#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int>vc;
    while(t--){
        int n;
        cin>>n;
        vc.push_back(n);
    }
    for(int i:vc){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
