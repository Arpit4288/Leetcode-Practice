class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
    unordered_map<int, int> remainderCount;

    // Iterate over the array and compute the remainder for each element
    for (int num : arr) {
        // Compute remainder while ensuring it's non-negative
        int remainder = ((num % k) + k) % k;
        remainderCount[remainder]++;
    }

    // Now, check if the remainders can form valid pairs
    for (auto& [remainder, count] : remainderCount) {
        if (remainder == 0) {
            // Special case: remainders of 0 must be even (they can only pair with themselves)
            if (count % 2 != 0) {
                return false;
            }
        } else {
            // The count of remainder r must match the count of k - r
            int complement = k - remainder;
            if (remainderCount[remainder] != remainderCount[complement]) {
                return false;
            }
        }
    }

    return true;
}

};