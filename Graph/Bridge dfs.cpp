int time=0;
int tin[N];
int low[N];
vector<pii>bridge;
void dfs(int c,int p=-1){
    vis[c]=1; 
    tin[c]=low[c] = time++; 
    for(auto i: g[c]) {
        if(i == p) continue;
        if(vis[i]==1){
            low[c] = min(low[c], tin[i]); 
        }
        else{
            dfs(i,c); 
            low[c] = min(low[c], low[i]); 
            if(low[i] > tin[c]){
                bridge.pb({c,i});
            }
        }       
    }
}

//[Note : There is only question on bridges of undirected graph]
