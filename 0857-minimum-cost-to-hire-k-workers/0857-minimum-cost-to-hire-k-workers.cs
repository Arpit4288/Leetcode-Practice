public class Solution {
    public record Worker(int Quality, double Ratio);
    public double MincostToHireWorkers(int[] quality, int[] wage, int k) {
        var workers = quality
            .Select((q, i) => new Worker(q, (double)wage[i] / q))
            .OrderBy(w => w.Ratio)
            .ToArray();
        double best = double.MaxValue;
        PriorityQueue<int, int> qualityHeap = new(k);
        for (int i = 0, totalQuality = 0, n = quality.Length; i < n; i++) {
            int q = workers[i].Quality;
            totalQuality += q;
            if (qualityHeap.Count < k)
                qualityHeap.Enqueue(q, -q);
            else
                totalQuality -= qualityHeap.DequeueEnqueue(q, -q);
            if (qualityHeap.Count == k)
                best = Math.Min(best, totalQuality * workers[i].Ratio);
        }
        return best;
    }
}