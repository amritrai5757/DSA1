// No questions till now asked on dp of permutations
void solve(vector<int>& coins, int i,int amt, int target, vi &vis, vi &temp, vector<vi>&ans){
        if(i >coins.size())return;                                      
        if(i==coins.size()){                                            //All permutations: if(i==coins.size()) ans.pb(temp);
            ans.push_back(temp);
            return;
        }
        for(int j = 0; j < coins.size(); j++){
            if(vis[j] == 0){                                             //Remove for unbounded
                if (j > 0 && num[j] == num[j-1] && vis[j-1]) return;     //Remove for unbounded
                vis[j] = 1;                                              //Remove for unbounded
                temp.push_back(coins[j]);                                
                solvee(coins, i+1,amt+coins[j], target, vis,temp,ans);
                temp.pop_back();                   
                vis[j] = 0;                                              //Remove for unbounded
            }
        }
}


// Rule : For bounded: If elements of input array may have same elements eg: 112, u cant remove them like , u have to necessarily use if(i>c && cand[i]==cand[i-1])continue; i,e 112 will be formed only 1 time in combination
//         eg:If frequency of element given(how much times elements has occured) it comes under bounded & use if(i>c&&..) to avoid duplicates
// Rule : For unbounded: All elements must be necessarily be unique. No question till now of unbounded asked with similar elements but if asked remove duplicate elements before recursive code.
//         eg: Generate Parenethesis of size n. eg: ()))(( IF we use bounded then we need to sort like (((()))). 
//           Now we can either use unounded comb/perm code for ((())) for(2times ()) or write without for loop since there are only 2 elements  
//           Note: comb of ((())) : Since elements are not unique we necessarily have to use if(i>c&& ..) & hence only 1 combinatio will be formed ((()))
