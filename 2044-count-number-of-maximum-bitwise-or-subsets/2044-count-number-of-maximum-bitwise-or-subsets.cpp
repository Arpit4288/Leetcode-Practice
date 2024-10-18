class Solution {
public:
    int countMaxOrSubsets(vector<int>& _nums) {
        // initialize
        nums = _nums;
        n = nums.size();
        orFrom = nums;
        for( int i = orFrom.size() - 2; i >= 0; i-- ) {
            orFrom[i] = orFrom[i] | orFrom[i + 1];
        }
        fullOr = orFrom.front();

        // count subsets
        int subsetsCount = countMaxSubsets( 0, 0 );

        return subsetsCount;
    }

private:
    int n = 0; // nums count
    vector<int> nums; // nums
    vector<int> orFrom; // orFrom[i] = or( nums[i:] )
    int fullOr = 0; // or(nums)

    // get number of subsets s of nums[prefixEnd:]
    // where or( s ) | prefixOr = fullOr
    int countMaxSubsets( int prefixOr, int prefixEnd ) const
    {
        // end of recursion
        if( prefixEnd == n ) {
            return fullOr == prefixOr ? 1 : 0;
        }
        // optimize recursion tail: all seq is good
        if( fullOr == prefixOr ) {
            return 1 << ( nums.size() - prefixEnd );
        }
        // optimize recursion tail: all seq is bad
        if( ( prefixOr | orFrom[prefixEnd] ) != fullOr ) {
            return 0;
        }
        // recursion's body
        int subsetsCount = 0;
        for( int i = prefixEnd; i < n; i++ ) {
            subsetsCount += countMaxSubsets( prefixOr | nums[i], i + 1 );
        }
        return subsetsCount;
    }
};