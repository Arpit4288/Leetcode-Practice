public class Solution {

        public int TupleSameProduct(int[] nums)
        {
            Dictionary<int, HashSet<string>> map = new Dictionary<int, HashSet<string>>();
            for (int i = 0; i < nums.Length; i++)
            {
                for (int j = 0; j < nums.Length; j++)
                {
                    if (i == j) continue;
                    string s = i < j ? $"{i}:{j}" : $"{j}:{i}";
                    int product = nums[i] * nums[j];

                    if (!map.ContainsKey(product))
                    {
                        map.Add(product, new HashSet<string>());
                    }
                    map[product].Add(s);
                }
            }
            int result = 0;
            foreach (var key in map.Keys)
            {
                int i = 1;

                while (i < map[key].Count)
                {
                    result += (i * 8);
                    i++;
                }
            }
            return result;
        }
}