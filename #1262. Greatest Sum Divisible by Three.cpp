class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1, vector<int>(3, INT_MIN));
        dp[0][0]=0;

        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                dp[i][(j+nums[i-1])%3]=max(dp[i-1][j]+nums[i-1], dp[i-1][(j+nums[i-1])%3]);
                // cout<<i<<" "<<(j+nums[i-1])%3<<" "<<dp[i][(j+nums[i-1])%3]<<"\n";
            }
        }
        return max(dp[n][0], 0);
    }
};

// dp 0 1 2 3  4  5
// 0  0 3 9 9  15 18
// 1  - - - -  10 22
// 2  - - - 14 14 23