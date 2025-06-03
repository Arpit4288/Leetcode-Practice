public class Solution
{
    public int MaxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes)
    {
        var total = status.MaxCandiesExtension(candies, keys, containedBoxes, initialBoxes);

        return total;
    }
}

public static class BoxExtensions
{
    /// <summary>Extension method on an int[] “status” array that computes the maximum candies</summary>
    public static int MaxCandiesExtension(
        this int[] status,
        int[] candies,
        int[][] keys,
        int[][] containedBoxes,
        int[] initialBoxes)
    {
        int n = status.Length;
        
        bool[] hasKey = new bool[n];
        bool[] isOpened = new bool[n];
        bool[] inPossession = new bool[n];

        foreach (var b in initialBoxes)
        {
            inPossession[b] = true;
        }

        int totalCandies = 0;
        bool progress = true;

        while (progress)
        {
            progress = false;

            // Try every box in [0..n-1]
            for (int box = 0; box < n; box++)
            {

                if (inPossession[box] && !isOpened[box] && (status[box] == 1 || hasKey[box]))
                {
                    isOpened[box] = true;
                    progress = true;

                    totalCandies += candies[box];

                    foreach (var inner in containedBoxes[box])
                    {
                        if (!inPossession[inner])
                        {
                            inPossession[inner] = true;
                        }
                    }

                    foreach (var k in keys[box])
                    {
                        if (!hasKey[k])
                        {
                            hasKey[k] = true;
                        }
                    }
                }
            }
        }

        return totalCandies;
    }

}
