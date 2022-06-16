int maxSubArraySum(int a[], int size){
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++){
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)max_so_far = max_ending_here;
        if (max_ending_here < 0)max_ending_here = 0;
    }
    return max_so_far;
}


//In max product subarray : You need to maintain both min subarray and max subarray because min can max if any another neg is multiplied with it.
int maxProduct(vector<int>& A) {
    int r = A[0];
    for (int i = 1, imax = r, imin = r; i < A.size(); i++) {
        if (A[i] < 0)
            swap(imax, imin);

        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);
        
        r = max(r, imax);
    }
    return r;
}

