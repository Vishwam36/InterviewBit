// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/kth-smallest-element-in-the-array/
// Decent

// Can be done by modified quick sort also but takes space complexity of O(n) but space complexity avg is O(n). (solution below App 2)

// App 1:

// Time Complexity : O(n logn)
// Space Complexity : O(1)

int Solution::kthsmallest(const vector<int> &a, int k) 
{
    int mini = *min_element(a.begin(), a.end());
    int maxi = *max_element(a.begin(), a.end());
    
    while(mini <= maxi)
    {
        int mid = (mini+maxi)/2;
        int lesser = 0, equal = 0;
        
        for(auto num : a)
        {
            if(num < mid)
                lesser++;
            else if(num == mid)
                equal++;
        }
        
        if(lesser >= k)
            maxi = mid-1;
        else
            if(lesser+equal >= k)
                return mid;
            else
                mini = mid+1;
    }
}

// App 2:

// Time Complexity average : O(n)
// Space Complexity : O(1)

int partition(vector<int> &a, int low, int high)
{
    swap(a[high], a[low + rand() % (high-low+1)]);
    int pivot = a[high];
    int i = low-1;
    
    for(int j = low; j <= high; ++j)
    {
        if(a[j] < pivot)
        {
            ++i;
            swap(a[i], a[j]);
        }
    }
    
    swap(a[high], a[i+1]);
    return i+1;
}
     
int quick_sort(vector<int> &a, int low, int high, int k)
{
    int pivotIndex = partition(a, low, high);
    
    if(pivotIndex == k-1)
        return a[k-1];
        
    if(pivotIndex > k-1)
        return quick_sort(a, low, pivotIndex-1, k);

    else
        return quick_sort(a, pivotIndex+1, high, k);
}
     
int Solution::kthsmallest(const vector<int> &a, int k) 
{
    vector<int> copy = a;
    return quick_sort(copy, 0, a.size()-1, k);
}
