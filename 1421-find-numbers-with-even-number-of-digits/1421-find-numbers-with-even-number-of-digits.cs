public class Solution {
    public int FindNumbers(int[] nums) //* 1295 Find Numbers with Even Number of Digits
    {
        int count = 0;
        
        foreach (int num in nums)
        {
            count += (num) switch
            {
                >= 100000 => 1,
                >= 10000 => 0,
                >= 1000 => 1,
                >= 100 => 0,
                >= 10 => 1,
                >= 0 => 0
            };
        }

        return count;
    }
}