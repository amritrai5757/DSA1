bool bipartite;
void bfs(int s){
queue<int> q; 
q.push(s);
vis[s] = 1; 
while(q.size()){
    int c = q.front();
    q.pop(); 
    for(int i:g[c]){
        if(vis[i]==0){
           q.push(i); 
           vis[i] = vis[c]%2+1; 
        }
        else if(vis[i]==vis[c]){
           bipartite=false;return;
        }
    }
}     
}
