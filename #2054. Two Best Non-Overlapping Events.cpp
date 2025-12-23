class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int store=0;
        int ans=0;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<>> pq;
        for(auto& event: events){
            int start= event[0];
            int end= event[1];
            int value= event[2];
            while(!pq.empty() && pq.top().first< start){
                store= max(store,pq.top().second);
                pq.pop();
            }

            ans= max(ans, store+value);
            pq.push({end,value});
        }
        return ans;
    }
};