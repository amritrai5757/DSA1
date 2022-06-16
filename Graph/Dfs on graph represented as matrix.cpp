//Convert graph represented as matrix into normal graph (adjacency list)
vector<vector<int>> adjList(a.size());
for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < a[i].size(); j++)
            if(a[i][j] == 1)
                adjList[i].push_back(j);  // It will be automatic converted into directed or undirected. No need to do again adjList[j].push_back(i);
        
    
return adjList;
