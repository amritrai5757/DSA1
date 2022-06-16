int time=0;
int tin[N];//-1
int low[N];//-1
bool bridgepoint[N];
void dfs(int c,int p=-1){
    int child=0;
    vis[c] =1;
    tin[c] = low[c] = time++;
    for(auto i: g[c]) {
        if(i == p) continue;
        if(vis[i]==1) {
            low[c]=min(low[c],tin[i]);
        }
        else{
            dfs(i,c);
            low[c] = min(low[c], low[i]);
            if (low[i] >= tin[c] && p!=-1)
                bridgepoint[c]=1;
            child++;
        }
    }
    if(p==-1 && child>1)
        bridgepoint[c]=1;
}

//[Note: There is only question on undirected graph articulation point]
