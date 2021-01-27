// By Vishwam Shriram Mundada
// https://www.interviewbit.com/problems/median-of-array/
// Good Question

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) 
{
    if(A.size() > B.size())
        return findMedianSortedArrays(B, A);
    
    int x = A.size();
    int y = B.size();
    
    int left = 0;
    int right = x;
    while(left <= right)
    {
        int partitionX = (left + right) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;
        
        int maxLeftX = (partitionX == 0 ? INT_MIN : A[partitionX - 1]);
        int minRightX = (partitionX == x ? INT_MAX : A[partitionX]);
        
        int maxLeftY = (partitionY == 0 ? INT_MIN : B[partitionY - 1]);
        int minRightY = (partitionY == y ? INT_MAX : B[partitionY]);
        
        if(maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            if((x + y) % 2 == 0)
            {
                return (double)((double)max(maxLeftX, maxLeftY) + (double)min(minRightX, minRightY)) / 2;
            }
            else
            {
                return ((double)max(maxLeftX, maxLeftY));
            }
        }
        else if(maxLeftX > minRightY)
        {
            right = partitionX - 1;
        }
        else
        {
            left = partitionX + 1;
        }
    }
}
