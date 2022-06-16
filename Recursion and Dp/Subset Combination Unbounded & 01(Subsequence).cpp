//Simply remove dp to get total recursion
int f(int ind,int W,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp){
     if(ind==0){
          if(wt[0]<=W)return val[0];  //return (W/wt[0])*val[0]; for maximum value //if unbounde without val return W%wt[0] for total ways 
          return 0;
     }
     if(dp[ind][W]!=-1)return dp[ind][W];
     int notTake=0+f(ind-1,W,wt,val,dp);
     int take=INT_MIN; //Remove for getting total no of combinations //For unbounded : take=0 for max
     if(wt[ind]<=W){
          take=val[ind]+f(ind-1,W-wt[ind],wt,val,dp);//f(ind,W..) for unbounded 
     }
     return dp[ind][W]=max(take,notTake);
}

int solve(vector<int>weight,vector<int>value,int n,int maxWeight){
     vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
     return f(n-1,maxWeight,weight,value,dp);
}


Tabulation:

int knapsack(vector<int>wt,vector<int>val,int n,int maxWeight){
     vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
     for(int W=wt[0]; W<=maxWeight;W++)dp[0][W]=val[0];
     //For unbounded : for(int W=0;W<=w;W++) dp[0][W]=(W/wt[0])*val[0];//for unbou withotu value dp[0][W]=(W%a[0]==0);
     for(int ind=1;ind<n;ind++){
          for(int W=0;W<=maxWeight;W++){
               ind notTake=0+dp[ind-1][W];
               int take = INT_MIN;      //int take =0;
               if(wt[ind]<=W){
                    take=val[ind]+dp[ind-1][W-wt[ind]];//dp[ind][..]
               }
               dp[ind][W]=max(take,notTake);
           }
     }
     return dp[n-1][maxWeight];
}







//No of subsets for given sum     [note: Number of permutations is not equal to number of combinations but permutations with max/min sum = combination with max/min sum = subsequence with max/min sum ]
//For min diff between 2 subset of a set : do the dp & then run a loop (j=sum/2 to 0) to find greatest j whose sum is present
// Combination : Order of elements arranged doesnt matters. So same elements with different arrangement doesnt come again.        Permutation: Order matters
// eg : DP : no of combination of unbouded coins [1,2] suming 4 = 3   (1111 112 22)

// Bounded combination : eg : Comb of bounded {1,2} having sum 3 =[1,2]

     vector<vector<int>>ans;
     void getset(vector<int>& nums,vector<int>& curr,int i,bool pre){
      
        if(i==-1)
        {
            ans.push_back(curr);
            return;
        }
         
        
        getset(nums,curr,i-1,false);
         if(i<(nums.size()-1) && nums[i]==nums[i+1] && (!pre))  //pre to check wheter we took or not previous element
             return;
      
        curr.push_back(nums[i]);
        getset(nums,curr,i-1,true);
        curr.pop_back();
        
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         
        vector<int>curr;
        int i=0;
        getset(nums,curr,nums.size()-1,false);
       // vector<vector<int>>res(ans.begin(),ans.end());
        return ans;
    }


 
void solve(int i , int sum, vector<int>&coins, vector<int>&temp, vector<vector<int>>&ans ){
        if(i == -1 ){
            if(sum==0)ans.push_back(temp);
            return;
        }
        solve(i-1 , sum , coins ,temp,ans);
 
        if(coins[i] <= sum){
            temp.push_back(coins[i]);
            solve(i , sum-coins[i] , coins ,temp,ans);
            temp.pop_back();
        }
}

// Rule : For bounded: If elements of input array may have same elements eg: 112, u cant remove them like , u have to necessarily use if(i>c && cand[i]==cand[i-1])continue; i,e 112 will be formed only 1 time in combination
//         eg:If frequency of element given(how much times elements has occured) it comes under bounded & use if(i>c&&..) to avoid duplicates
// Rule : For unbounded: All elements must be necessarily be unique. No question till now of unbounded asked with similar elements but if asked remove duplicate elements before recursive code.
//         eg: comb of unbounded [1,1,2] remove all same elements before running unbounded comb recursive code i,e it becomes unbounded comb of [1,2]
