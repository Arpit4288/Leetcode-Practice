#include <vector>  
#include <algorithm>  
using namespace std;  

class Solution {  
public:  
    int minimizedMaximum(int n, vector<int>& quantities) {  
        int start = 1;  
        int end = *max_element(quantities.begin(), quantities.end());  
        
        while (start <= end) {  
            int mid = start + (end - start) / 2;  
            // Calculate the total number of stores needed for the current mid value  
            int total = 0;  
            for (int element : quantities) {  
                total += (element + mid - 1) / mid;  
            }  
            
            if (total <= n) {  
                // If the number of stores needed is less than or equal to the available stores,  
                // we try to minimize the maximum by reducing mid  
                end = mid - 1;  
            } else {  
                // If the number of stores needed is greater than the available stores,  
                // we need to increase mid to reduce the number of stores needed  
                start = mid + 1;  
            }  
        }  
        
        // The smallest value for which total <= n is `start`  
        return start;  
    }  
};