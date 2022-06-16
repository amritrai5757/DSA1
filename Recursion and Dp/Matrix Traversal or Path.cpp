// In recursion of matrix validity is checked first unlike graph & all directions are written separetly to easilly convert them into tabulation.
// IN reursion intialisze dp with -1 & in tabulation with 0
// If asked about min or max path sum to reach from a cell to another cell, then grid values is considered as cost like in knapsack 
int f(int i,int j,vector<vector<int>>&dp){
  if(i<0 || j<0 || (i>=0 && j>=0 && mat[i][j]==-1)/*obstacle*/)return 0; //For : min path sum : return INT_MAX for max sum INT_MIN
  if(i==0 && j==0)return 1; //For min/max path sum : return mat[i][j]// Fpr any row to anu colum : either if(i==0) or if(j==0) as per que
  if(dp[i][j]!=-1) return dp[i][j];
  int up=f(i-1,j,dp) ;  // For : min/max path sum : f(i-1,j..) + mat[i][j] 
  int left=f(i,j-1,dp); // For : min/max path sum : f(..) +mat[i][j]
  return dp[i][j]=up+left;
}

int solve(int m,int n){
  vector<vector<int>>dp(m,vector<int>(n,-1));
  //if Asked max/min path from any node of 1st row/colum to any node of last row / colum
  // just run this loop till row acordin to que for(i -0 ton n-1) (max(ans,f(m-1,n-1,dp)) no reinst of dp same dp & same time compl o(nm) magic
  return f(m-1,n-1,dp);  
}


//READ BINARY SEARCH FOR THIS AFTER RECURSION AND DP DONE
Tabulation : Write two for loops 0 to m-1 & 0 to n-1 & copy whole recursion inside it & ignore boundry conditions like if(i<0) because loop will run till inside for loop only,no need to check it.
int solve(int m,int n){
  vector<vector<int>>dp(m,vector<int>(n,0));
  for(int i=0;i<m;i++){
    for(int j=0;i<n;j++){
      if(mat[i][j]==-1)dp[i][j]=0;
      else if(i==0 && j==0) dp[i][j]=1; //=grid[i][j]
      else{
        int up=0,left=0; //For min/max : up=grid[i][j],left=grid[i][j]
        if(i>0)up+=dp[i-1][j];
        //For min/max : else up+= /= INT_MAX;
        if(j>0)left+=dp[i][j-1];
        //For min/max : else left+= /= INT_MAX;
        dp[i][j]=up+left;//For min/max : min(left,up)
      }
    }
  }
  return dp[m-1][n-1];
}






// Dfs is used for 1)For printing all paths emerging from 1 cell whether movement is cyclical or non-cyclical.
//                 2)For finding min/max path emerging from a cell,if movement is cyclical i,e once visisted cell can be visted again by mover. [note: This can be done by dp using map in same tc as dfs but too hectic]
// For any dp which whose has other than right & down use simple memoziation


// Maximum Gold :
vector<int> directions={0,1,0,-1,0};

int dfs(vector<vector<int>> &grid,int i,int j){
        int temp=grid[i][j],result=0;
        grid[i][j]=0;
        for(int d=0;d<4;d++){                   //Try all 4 possible directions
            int x=i+directions[d],y=j+directions[d+1];
            if(x>=0&&y>=0&&x<grid.size()&&y<grid[x].size()&&grid[x][y]!=0)
                result=max(result,grid[x][y]+dfs(grid,x,y));  //Set grid[i][j] to 0 to mark as visited before next dfs and reset the values after the dfs ends
        }
        grid[i][j]=temp; // 1  2  3  If dfs is running from 1. If we dont use it : if its visited path 1->2->5->8 ,it will not visit any path in which any of this nodes come like 1->2->3
                         // 4  5  6     Basically it will become code for checking whether graph is connected or not i,e once a node visited,we dont visit it again.
                         // 7  8  9  To check all paths coming from node 1, we maintain all nodes in its original state after using it. So now u can check 1->2->3 even after visting 1->2->5->8.
                         // Note: U cant use this code with every dfs to maintain matrix because every dfs dont check each paths eg: code for checing connected graph or not.
        return result;
}
    
int getMaximumGold(vector<vector<int>>& grid) {
        int result=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]>0)
                    result=max(grid[i][j]+dfs(grid,i,j),result);   //Set grid[i][j] to 0 to mark this cell as visited and reset after the dfs ends.
        return result;
}




//Knight Tour : Knight start from cell (0,0). U need to print any answer in which all cells of matrix are visited with the moves no of knight.

int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 

void solve(int x, int y, int movei, int sol[N][N],int xMove[8], int yMove[8]){
    int k, next_x, next_y;
    sol[x][y] = movei;  // mark visited like graph
    if (movei == N * N) return;
        
    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k],next_y = y + yMove[k];
        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && sol[x][y] == -1) {// valed or not like graph
            solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove)
            if(possible==1){
                    print(matrix); //Print before making sol[x][y]=-1 again. 
                    return ;} // Return after getting any 1 answer. If u want to know all answer dont return after just getting 1 answer.
        }
    }
    sol[x][y] = -1;
}











TABULATION :::

//For any non cyclical traversal whose traversal is other or more than right & down : use simple recursion & memozise it
//Non cyclical directions means once a cell is visited is impossible to visit it again
//     eg:1)mover can move only in 2 direction right and down.
//        2)mover can move only in any 4 direction right,down,diagonal between right & downward and diagonal between upward and right.
//This algorithm is used for : 1) Printing the max/min emerging from 1 cell to a target where movement is non cylical
//                             2) Total ways to reach target from 1 cell where movement is non cylical
//PATH QUE CAN NEVER ASK PERMUTATION. ex; 1->2->3 you cant permute it like first go 3 then 1 then 2 (3->1->1)wrong                              
                               
int solve(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 
        vector<vector<int> > dp(m, vector<int>(n, grid[0][0]));
        for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j]  = min(dp[i - 1][j],dp[i][j - 1]) + grid[i][j];   // For no of ways to reach : dp[i-1][j]+dp[i][j-1]
        return dp[m - 1][n - 1];
}
