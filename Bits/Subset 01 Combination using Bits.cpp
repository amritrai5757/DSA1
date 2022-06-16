Tc=n*(2^n)
vector<vector<int> > AllSubsets(vector<int> nums, int n){
    int bits = nums.size();     // size of array to set bit
    int pow_set_size = pow(2, bits);     // total number of subsets = pow(2, sizeof(arr))
    sort(nums.begin(), nums.end());     // sort to avoid adding permutation of the substring
    vector<vector<int>> ans;
    vector<string> list;     // to store subset as a list to avoid adding exact duplicates
 
    for (int counter = 0; counter < pow_set_size; counter++) {
        vector<int> subset;
        string temp = "";
        for (int j = 0; j < bits; j++) {
            if (counter & (1 << j)) {
                subset.push_back(nums[j]);
                // add special character to separate integers
                temp += to_string(nums[j]) + '$';
            }
        } 
        if (find(list.begin(), list.end(), temp) == list.end()){  For duplicates 121 allowed but again 211 not allowed
            ans.push_back(subset);
            list.push_back(temp);
        }
    } 
    return ans;
}
