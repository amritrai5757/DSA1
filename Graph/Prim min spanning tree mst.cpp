// tc = o((e+v)logv) because it is dijkstra algo with backtracking
vi par;
vi wgt;

void prim(int s){
    par.resize(n+3,-1);
    wgt.resize(n+3,inf);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vi inMST(n+3,0);
    pq.push({0,s});
    wgt[s]=0;

    while(pq.size()){
        int u = pq.top().second;
        pq.pop();
        if(inMST[u] == 1)continue;
        inMST[u] = 1;
        for(auto i:g[u]){
            int v = i.first;
            int tmp = i.second;
            if (inMST[v] == 0 && wgt[v] > tmp){
                wgt[v] = tmp;
                pq.push({wgt[v], v});
                par[v]=u;
            }
        }
    }
    int totalweight=0;
    forr(i,1,n-1){
        if(wgt[i]==inf){cout<<"No MST because Graph is disconnected";return;}
        totalweight+=wgt[i];
        cout<<i<<"connectedTo"<<par[i];
    }
}
