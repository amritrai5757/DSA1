void bfs(int s){
    queue<int> q; 
	vi indegree(n+3); 
	forr(i,s,n)for(auto j:g[i])indegree[j]++; 

    forr(i,s,n){
        if(indegree[i]==0){
            q.push(i); 
        }
    }
    int cnt = 0;
    while(q.size()){
        int c=q.front(); 
        q.pop();
        cnt++;
        //topo.pb(c); 
        for(auto i:g[c]){
            indegree[i]--;
            if(indegree[i]==0) {
                q.push(i); 
            }
        }
    }
    if(cnt!=n)cout<<"cycle";  
}
