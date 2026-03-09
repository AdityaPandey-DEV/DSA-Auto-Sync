class Solution {
public:
    const int MOD = 1000000007;
    vector<vector<vector<vector<int>>>> dp;

    int rec(int zero, int one, int limit, int last, int cnt){

        if(zero == 0 && one == 0) return 1;

        if(dp[zero][one][last][cnt] != -1)
            return dp[zero][one][last][cnt];

        long long ans = 0;

        if(last == 0){
            if(zero > 0 && cnt < limit)
                ans = (ans + rec(zero-1, one, limit, 0, cnt+1)) % MOD;

            if(one > 0)
                ans = (ans + rec(zero, one-1, limit, 1, 1)) % MOD;
        }
        else{
            if(one > 0 && cnt < limit)
                ans = (ans + rec(zero, one-1, limit, 1, cnt+1)) % MOD;

            if(zero > 0)
                ans = (ans + rec(zero-1, one, limit, 0, 1)) % MOD;
        }

        return dp[zero][one][last][cnt] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        dp = vector<vector<vector<vector<int>>>>(
                zero+1,
                vector<vector<vector<int>>>(
                    one+1,
                    vector<vector<int>>(
                        2,
                        vector<int>(limit+1, -1)
                    )
                )
             );

        long long ans = 0;

        if(zero > 0)
            ans = (ans + rec(zero-1, one, limit, 0, 1)) % MOD;

        if(one > 0)
            ans = (ans + rec(zero, one-1, limit, 1, 1)) % MOD;

        return ans;
    }
};