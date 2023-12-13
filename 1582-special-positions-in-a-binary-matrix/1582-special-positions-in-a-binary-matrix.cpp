class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0; // Initialize a counter for special elements

        // Iterate over each element in the matrix
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                // Check if the current element is 1 (a potential special element)
                if (mat[i][j] == 1) {
                    bool flag = true; // Initialize a flag to track if the element is special

                    // Check the entire row of the current element
                    for (int k = 0; k < mat[0].size(); k++) {
                        // If there is another 1 in the row (excluding the current element), it's not special
                        if (mat[i][k] != 0 && k != j)
                            flag = false;
                    }

                    // Check the entire column of the current element
                    for (int l = 0; l < mat.size(); l++) {
                        // If there is another 1 in the column (excluding the current element), it's not special
                        if (mat[l][j] != 0 && i != l)
                            flag = false;
                    }

                    // If the element passed both row and column checks, it's a special element
                    if (flag)
                        cnt++; // Increment the counter
                }
            }
        }

        // Return the total count of special elements
        return cnt;
    }
};