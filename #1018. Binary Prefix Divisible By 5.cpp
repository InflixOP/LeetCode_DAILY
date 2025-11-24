class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int c = 0;
        vector<bool> res;
        for (int i : nums){
            c = (c * 2 + i ) % 5;
            res.push_back(c == 0);
        }
        return res;
    }
};