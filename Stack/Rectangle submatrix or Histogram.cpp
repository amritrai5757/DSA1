//  Max AreaorReactangle in Binary Matrix & Histogram.cpp


//You dont need to store nsr rather store nsr index in stack and vector
vector<int> nsr(vector<int> heights, int n){
        vector<int> res(n);
        stack<int> st;      
        for(int i=n-1; i>=0; i--){
            while(st.size() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())res[i] = -1;
            else res[i] = st.top();
            st.push(i);
        }
        return res;        
}

vector<int> nsl(vector<int> heights, int n){
        vector<int> res(n);
        stack<int> st;       
        for(int i=0; i<n; i++){
            while(st.size() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())res[i] = -1;
            else res[i] = st.top();
            st.push(i);
        }
        return res;        
}

int MaxAreaInHistogram(vector<int>& heights) {
        int n = heights.size();        
        vector<int> left(n), right(n);
        right = nsr(heights,n);
        left = nsl(heights,n);

        int res = INT_MIN;        
        for(int i=0; i<n; i++){
            if(left[i]==-1) left[i]= -1;
            if(right[i]==-1) right[i]= n;
            
            int w = right[i]-left[i]-1;
            res = max(res,heights[i]*w);
        }        
        return res;
}

int MaxAreaInBinaryMatrix(vector<vector<int>>&matrix){
        int n=matrix.size(),m=matrix[0].size();
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++)
                if(matrix[i][j])     
                  matrix[i][j] += matrix[i-1][j];

        int ans = 0;
        for(int i=0;i<n;i++) ans = max(ans, MaxAreaInHistogram(matrix[i]));   //Calculating ans for all n Histograms
        return ans;
}
