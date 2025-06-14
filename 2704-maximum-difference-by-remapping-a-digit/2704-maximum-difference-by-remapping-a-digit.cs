public class Solution {
    public int MinMaxDifference(int num) {
        List<int> digits = GetDigits(num);
        List<int> biggestDigits = ModifyNumber(digits, true);
        List<int> lowestDigits = ModifyNumber(digits, false);
        int biggest = GetNumberFromDigits(biggestDigits);
        int lowest = GetNumberFromDigits(lowestDigits);
        return biggest - lowest;
    }
    List<int> GetDigits(int num) {
        List<int> digits = new List<int>();
        while (num > 0) {
            digits.Add(num % 10);
            num /= 10;
        }
        digits.Reverse();
        return digits;
    }
    List<int> ModifyNumber(List<int> digits, bool biggest) {
        int[] change = Enumerable.Repeat(-1, 10).ToArray();
        List<int> modified = new List<int>(digits);
        int compDigit = biggest ? 9 : 0;
        for (int i = 0; i < digits.Count; i++) {
            if (digits[i] != compDigit) {
                change[digits[i]] = compDigit;
                break;
            }
        }
        for (int i = 0; i < digits.Count; i++) {
            if (change[digits[i]] != -1) {
                modified[i] = compDigit;
            }
        }
        return modified;
    }
    int GetNumberFromDigits(List<int> digits) {
        int res = 0;
        for (int i = 0; i < digits.Count; i++) {
            res = res * 10 + digits[i];
        }
        return res;
    }
}