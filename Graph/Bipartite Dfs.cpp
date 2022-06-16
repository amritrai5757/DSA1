bool bipartite;
void dfs(int c,int p){
    vis[c]=vis[p]%2+1;
    for(auto i:g[c]){
        if(vis[i]==0){
            dfs(i,c);
            if(bipartite==false)return; 
        }
        else if(vis[i] == vis[c]){
            bipartite=false;
            return;
        }
    }
    return; 
}
