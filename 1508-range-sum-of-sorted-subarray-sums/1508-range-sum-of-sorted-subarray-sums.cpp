class Solution {
public:
    int rangeSum(vector<int>& nums, int count, int left, int right) {
        n = count;
        minSum = *std::min_element(nums.begin(), nums.end());
        maxSum = std::accumulate(nums.begin(), nums.end(), 0);
        
        // For example:
        // nums = 1 2 3 4, left = 4, right = 6
        // sortedSums = 1 2 3 3 4 5 6 7 9 10
        //                  ^ left-2
        //                        ^ right-1
        // leftSortedSums  = 3
        // rightSortedSums = 5
        const int leftSortedSums = findKthSortedSum(nums, left - 2);
        const int rightSortedSums = findKthSortedSum(nums, right - 1);
        // leftPrefix  = 1+...+leftSortedSums  = 1+2+3+3     =  9
        // rightPrefix = 1+...+rightSortedSums = 1+2+3+3+4+5 = 18
        int leftPrefix = sumSortedSumsUnder(nums, leftSortedSums);
        int rightPrefix = sumSortedSumsUnder(nums, rightSortedSums);
        
        // Correct the prefix sums since there may be duplicate sorted sums
        // leftExtraSortedNums  = 4-(4-1) = 1
        // rightExtraSortedNums = 6-6     = 0
        const int leftExtraSortedNums = countSortedSumsUnder(nums, leftSortedSums) - (left - 1);
        const int rightExtraSortedNums = countSortedSumsUnder(nums, rightSortedSums) - right;
        leftPrefix -= leftExtraSortedNums * leftSortedSums;
        rightPrefix -= rightExtraSortedNums * rightSortedSums;
        return rightPrefix - leftPrefix;
    }
    
    // Finds sortedSums[k]
    // sortedSums = 1 2 3 3 4 5 6 7 9 10
    //              ^ k=0
    //                ^ k=1
    //                  ^ ^ k=2,3
    //                      ^ k=4
    int findKthSortedSum(const vector<int>& nums, const int k) {
        if (k < 0) return 0;
        int low = minSum;
        int high = maxSum + 1;
        while (low < high) {
            const int mid = low + (high - low) / 2;
            const int numSortedSums = countSortedSumsUnder(nums, mid);
            if (numSortedSums < k + 1) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    
    // Counts how many subsums are <= x
    // nums          = 1 2 3  4, x = 7
    // subsum[0...3] = 1 3 6 10
    //                     ^ right=3
    // subsum[1...3] =   2 5  9
    //                     ^ right=3
    // subsum[2...3] =     3  7
    //                        ^ right=4
    // subsum[3...3] =        4
    //                        ^ right=4
    int countSortedSumsUnder(const vector<int>& nums, const int x) {
        int subsum = 0;
        int count = 0;
        int right = 0;
        for (int left = 0; left < n; left++) {
            while (right < n && subsum + nums[right] <= x) {
                subsum += nums[right++];
            }
            count += right - left;
            
            subsum -= nums[left];
        }
        return count;
    }
    
    // Sum all sorted sums under x
    // sortedSums = 1 2 3 3 4 5 6 7 9 10
    //              ^ sum = 1 (x=1)
    //              ^^^ sum = 3 (x=2)
    //              ^^^^^^^ sum = 9 (x=3)
    //              ^^^^^^^^^ sum = 13 (x=4)
    //              ^^^^^^^^^^^ sum = 18 (x=5)
    //              ^^^^^^^^^^^^^ sum = 24 (x=6)
    //              ^^^^^^^^^^^^^^^ sum = 31 (x=7)
    // nums          = 1 2 3  4, x = 7
    // subsum[0...3] = 1 3 6 10
    //                     ^ right=3 (rowSum=1+3+6=10, nextRowSum=10-3*1=7)
    // subsum[1...3] =   2 5  9
    //                     ^ right=3 (rowSum=7, nextRowSum=7-2*2=3)
    // subsum[2...3] =     3  7
    //                        ^ right=4 (rowSum=3+7=10, nextRowSum=10-2*3=4)
    // subsum[3...3] =        4
    //                        ^ right=4 (rowSum=4, nextRowSum=4-1*4=0)
    int sumSortedSumsUnder(const vector<int>& nums, const int x) {
        int subsum = 0;
        int rowSum = 0;
        int totalRowSums = 0;
        int right = 0;
        for (int left = 0; left < n; left++) {
            while (right < n && subsum + nums[right] <= x) {
                subsum += nums[right++];
                rowSum += subsum;
            }
            totalRowSums += rowSum;
            totalRowSums %= MOD_VALUE;
            
            subsum -= nums[left];
            const int nextRowSum = rowSum - (right - left) * nums[left];
            rowSum = nextRowSum;
        }
        return totalRowSums;
    }
    
    const int MOD_VALUE = 1000000000 + 7;
    int n = 0;
    int minSum = 0;
    int maxSum = 0;
};