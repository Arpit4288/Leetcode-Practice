public class Solution {
    public int NumRabbits(int[] answers) {
        var counter = new Dictionary<int, int>();
int rabbits = answers.Length; // Who already answered

// Who possibly wasn't asked, but we decrement each time when we find one of the same color
// If we reach 0 it means there's a new color we haven't counted yet
foreach (var x in answers)
{
    if (counter.ContainsKey(x) && counter[x] > 0)
    {
        counter[x]--;
    }
    else
    {
        counter[x] = x;
    }
}

foreach (var x in counter.Values)
{
    rabbits += x;
}

return rabbits;
    }
}