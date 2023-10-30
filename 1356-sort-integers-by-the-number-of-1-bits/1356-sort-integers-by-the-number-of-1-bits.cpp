class Solution {
public:
    int countbits(int i) {
        // Function to count the number of 1s in the binary representation of a number.
        int one = 0;
        while (i >= 1) {
            if (i % 2 == 1) {
                one++;
            }
            i /= 2;
        }
        return one;
    }

    vector<int> sortByBits(vector<int>& arr) {
        // Function to sort array based on the number of 1s in binary representation and then by value.
        vector<int> ans;
        sort(arr.begin(), arr.end()); // Sort the array first to ensure order for equal 1s count.
        map<int, vector<int>> m; // Map to store numbers grouped by their count of 1s.
        for (int a: arr) {
            m[countbits(a)].push_back(a); // Group numbers by their count of 1s.
        }
        for (auto &[k, v]: m) {
            ans.insert(ans.end(), v.begin(), v.end()); // Concatenate vectors into final answer.
        }
        return ans;
    }
};