class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0, i2 = 0;
        int v1 = version1.size(), v2 = version2.size();
        
        while (i1 < v1 && i2 < v2) { // Changed from || to &&
            int num1 = 0, num2 = 0;
            while (i1 < v1 && version1[i1] != '.') {
                num1 = num1 * 10 + (version1[i1] - '0');
                i1++;
            }
            while (i2 < v2 && version2[i2] != '.') {
                num2 = num2 * 10 + (version2[i2] - '0');
                i2++;
            }
            
            if (num1 < num2) return -1;
            else if (num1 > num2) return 1;
            
            // Move to the next segment
            i1++;
            i2++;
        }
        
        // Check if there are remaining segments in version1
        while (i1 < v1) {
            int num1 = 0;
            while (i1 < v1 && version1[i1] != '.') {
                num1 = num1 * 10 + (version1[i1] - '0');
                i1++;
            }
            if (num1 != 0) return 1; // version1 has more non-zero segments
            i1++; // Move to the next segment
        }
        
        // Check if there are remaining segments in version2
        while (i2 < v2) {
            int num2 = 0;
            while (i2 < v2 && version2[i2] != '.') {
                num2 = num2 * 10 + (version2[i2] - '0');
                i2++;
            }
            if (num2 != 0) return -1; // version2 has more non-zero segments
            i2++; // Move to the next segment
        }
        
        return 0;
    }
};