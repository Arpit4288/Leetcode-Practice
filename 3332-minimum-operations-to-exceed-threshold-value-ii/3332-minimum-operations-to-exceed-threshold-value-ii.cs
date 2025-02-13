public class Solution {
    public int MinOperations(int[] nums, int k)
    {
        var pq = new PriorityQueue<long, long>();

        // Add all numbers to the priority queue
        foreach (int num in nums)
        {
            pq.Enqueue(num, num); // Enqueue the value with itself as the priority
        }

        int count = 0;

        // Process until the smallest element in pq is at least k
        while (pq.Peek() < k)
        {
            Console.WriteLine("Peek is : " + pq.Peek());
            if (pq.Count < 2) break; // If we can't make another operation, return -1

            long min1 = pq.Dequeue();
            long min2 = pq.Dequeue();

            long newx = Math.Min(min1, min2) * 2 + Math.Max(min1, min2);
            pq.Enqueue(newx, newx);
            Console.WriteLine("Inserting : " + newx);
            count++;
        }

        return count;
    }
}