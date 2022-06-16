Stock Span :No of consecutive days for which stocks were smaller or equal to current days price = Index of current day-NGL INDEX
vector<int> NextGreaterLeft(vector<int> nums,int n){
        stack<pair<int,int>> s;        
        vector<int> res(n); 
        for(int i=0; i<n; i++){              
            while(s.size() && s.top().first() <= arr[i])  s.pop();          
            if(!s.size())  res[i]=-1;
            else res[i]=s.top().second(); //Storing index instead of value 
            s.push({arr[i],i});
        }                                                      
        for(int i=0;i<n;i++) res[i]=i-res[i];   //Index of current day-NGL INDEX
        return res;
}



