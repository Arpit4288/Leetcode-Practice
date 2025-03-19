public class Solution 
{
    public int MinOperations(int[] nums) 
    {
        Queue<int> flipQueue = new Queue<int>();
        int count = 0;

        for (int i = 0; i < nums.Length; i++) 
        {
            while (flipQueue.Count > 0 && i > flipQueue.Peek() + 2) 
            {
                flipQueue.Dequeue();
            }

            if ((nums[i] + flipQueue.Count) % 2 == 0) 
            {
                if (i + 2 >= nums.Length) 
                {
                    return -1;
                }
                count++;
                flipQueue.Enqueue(i);
            }
        }

        return count;
    }
}