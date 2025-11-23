class disjointset{
 public:
    vector<int> rank; int size; vector<int> par; vector<int> Size;
     disjointset(int n){
          rank.resize(n,0);
          size=n;
          Size.resize(n,1);
          par.resize(n);
          for(int i=0;i<n;i++){
            par[i]=i;
            
        }
      }
  //finding ultimate parent ---> baap nikalna
     int find(int x) {
        if(par[x] == x) return x;
       return par[x]=find(par[x]);
 }
 //union by rank
//    void UR(int u,int v){
//        int ultimate_parent_of_u=find(u);
//        int ultimate_parent_of_v=find(v);
//        if(ultimate_parent_of_u==ultimate_parent_of_v)return;
//        if(rank[ultimate_parent_of_u]>rank[ultimate_parent_of_v]){//u ka rank v se jyada hai to u v ka baap hai
//            par[ultimate_parent_of_v]=ultimate_parent_of_u;
//        }
//       else if(rank[ultimate_parent_of_u]<rank[ultimate_parent_of_v]){
//            par[ultimate_parent_of_u]=ultimate_parent_of_v;
//        }
//        else {
//            par[ultimate_parent_of_v]=ultimate_parent_of_u;
//            rank[ultimate_parent_of_u]++;
//        }
//    }
   //union by size
   void US(int u,int v){
    int ultimate_parent_of_u=find(u);
    int ultimate_parent_of_v=find(v);
    if(ultimate_parent_of_u==ultimate_parent_of_v)return;
    if(Size[ultimate_parent_of_u]>Size[ultimate_parent_of_v]){
        par[ultimate_parent_of_v]=ultimate_parent_of_u;
        Size[ultimate_parent_of_u]+= Size[ultimate_parent_of_v];
    }
   else {
        par[ultimate_parent_of_u]=ultimate_parent_of_v;
        Size[ultimate_parent_of_v]+= Size[ultimate_parent_of_u];
    }
   
}

};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        disjointset ds(n*m);
        int row[]={0,1,-1,0};
        int col[]={1,0,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int node=i*m+j;
                  for(int k=0;k<4;k++){
                    int nx=i+row[k];
                    int ny=j+col[k];
                    if(nx<n && nx>=0 && ny<m &&ny>=0 && grid[nx][ny]==1){
                        int node2=nx*m+ny;
                         ds.US(node,node2);
                    }
                  }
                }
            }
        }
      int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(grid[i][j]==0){
                    set<int>comp;
                    for(int k=0;k<4;k++){
                    int nx=i+row[k];
                    int ny=j+col[k];
                    if(nx>=n||nx<0 ||ny>=m||ny<0)continue;
                    if(grid[nx][ny]==1){
                        comp.insert(ds.find(nx*m+ny));
                    }
                    }
                    int sum=1;
                    for(int x:comp){
                        sum+=ds.Size[x];
                    }
                    maxi=max(maxi,sum);
                 }
            }
        }
        for(int i=0;i<n*m;i++){
            int ul_node=ds.find(i);
            maxi=max(maxi,ds.Size[ul_node]);
        }
        return maxi;
    }
};