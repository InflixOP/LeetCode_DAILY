class Solution {
    int n,m;
    vector<vector<int>>dp;
public:
    int isValid(vector<string>&strs,int ind1,int ind2){
        for(int i = 0;i<n;i++)
            if(strs[i][ind1]>strs[i][ind2]) return false;
        return true;
    }
    int f(vector<string>& strs,int ind,int prev_col){
        if(ind>=m)return 0;
        if(dp[ind][prev_col]!=-1)return dp[ind][prev_col];

        int skip = 1 + f(strs,ind+1,prev_col),pick = 1e9;
        if(prev_col==m+1 || isValid(strs,prev_col,ind))
            pick = f(strs,ind+1,ind);
        return dp[ind][prev_col] = min(skip,pick);
    }
    int minDeletionSize(vector<string>& strs) {
        n = strs.size(),m = strs[0].size();
        dp.resize(m + 2,vector<int>(m + 2,-1));
        return f(strs,0,m+1);
    }
};