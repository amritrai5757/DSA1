vi dis;
vi par;
vector<vi>path;

void bfs(int s){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dis.resize(n+3,inf);
    par.resize(n+3,-1);
    path.resize(n+3);
    dis[s] = 0;
    pq.push({0,s});
    while (pq.size()) {
        int u=pq.top().second;
        pq.pop();
        for(auto i:g[u]){
            int v = i.first;
            int weight = i.second;
            if (dis[v] > dis[u] + weight){
                dis[v] = dis[u] + weight;
                pq.push({dis[v], v});
                par[v]=u;
            }
        }
    } 

    forr(i,0,n-1){
        int j=i;
        while(j!=-1){
            path[i].pb(j);
            j=par[j];       
        }
        reverse(path[i].begin(),path[i].end());
    }
}
