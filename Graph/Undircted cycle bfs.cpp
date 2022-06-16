bool cycle;

void bfs(int s){
    queue<pair<int,int>>q;
    vis[s]=1;
    q.push({s, -1});
     
    while(q.size()) {
        int c = q.front().first;
        int p = q.front().second;
        q.pop();
     
        for(auto i:g[c]){
            if (vis[i]==0) {
                vis[i]=1;
                q.push({i,c});
            }
            else if(p!=i){
                cycle=true;
                return;
            }
        }
    }
}
