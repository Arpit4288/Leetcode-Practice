public class Solution {
    public int DifferenceOfSums(int n, int m) {
        int m_in_n = n / m;
        int num2 = (m_in_n * (m_in_n + 1) / 2) * m;
        int num1 = (n * (n + 1)) / 2 - num2;
        return num1 - num2;
    }
}