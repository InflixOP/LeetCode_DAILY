class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long ans=0;
        int n=basket1.size();
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto ele:basket1){
            mp1[ele]++;
        }
        for(auto ele:basket2){
            mp2[ele]++;
        }
        for(auto ele:basket1){
            if(mp2.find(ele)!=mp1.end()){
            mp2[ele]--;
            if(mp2[ele]==0)
            mp2.erase(ele);
            }
        }
        for(auto ele:basket2){
             if(mp1.find(ele)!=mp1.end()){
            mp1[ele]--;
            if(mp1[ele]==0)
            mp1.erase(ele);
             }
        }
        for(auto& ele:mp1){
            if(ele.second%2!=0)
            return -1;
            else{
            ele.second/=2;
            }
        }
        for(auto& ele:mp2){
            if(ele.second%2!=0)
            return -1;
            else{
            ele.second=ele.second/2;;
            }
        }
        vector<int> v1;
        vector<int> v2;
        for(auto ele:mp1){
            for(int i=0;i<ele.second;i++)
            v1.push_back(ele.first);
        }
        for(auto ele:mp2){
            for(int i=0;i<ele.second;i++)
            v2.push_back(ele.first);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),greater<int>());
        int min1=*min_element(basket1.begin(),basket1.end());
        int min2=*min_element(basket2.begin(),basket2.end());
        int mini=min(min1,min2);
        int i=0;
        while(i<v1.size()){
            ans+=min(2*mini,min(v1[i],v2[i]));
            i++;
        }
        return ans;
    }
};