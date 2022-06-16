vi dis;
//IF(dis[i]==MAX) NO PATH
//vector<vector<pii>>g;
void topomain(int cnode ,vi vis, stack<int> &st){
    vis[cnode] = 1; 
    aa(it,g[cnode]){
        if(!vis[it->first]) {
            topomain(it->first, vis, st); 
        }
    }
    st.push(cnode);
}


void dagpath(int s){

    dis.resize(n);
	vi vis(n);
	stack<int> st; 
	forr(i,0,n) 
		if (!vis[i]) 
			topomain(i, vis, st); 
			
	forr(i,0,n)
		dis[i] = MAX; 

	dis[s]=0;
	while(!st.empty()){  
		int node = st.top(); 
		st.pop(); 
 
		if(dis[node] != MAX) {
		    aa(it,adj[node]){
		        if(dis[node] + it->second < dis[it->first]) {
		            dis[it->first] = dis[node] + it->second; 
		        }
		    }
		}
	} 
} 
