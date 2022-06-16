int maxSum(int arr[], int n, int k){
    int res = 0;
    for (int i=0; i<k; i++)res += arr[i];
    int curr_sum = res;    
    for (int i=k; i<n; i++){
       curr_sum += arr[i] - arr[i-k];
       res = max(res, curr_sum);
    } 
    return res;
}


Anagram :
vector<int> findAnagrams(string s, string p) {             
        vector<int> freq_p(26,0);
        vector<int> window(26,0);
        vector<int> ans;
    
        for(int i=0;i<p.size();i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        if(freq_p == window) ans.push_back(0);
        
        for(int i=p.size();i<s.size();i++){
            window[s[i-p.size()] - 'a']--;
            window[s[i] - 'a']++;
            if(freq_p == window) ans.push_back(i-p.size()+1);
        }
        return ans;  //Returns starting position of all anagrams. ans.size()= total no of anagrams.
}
