public class Solution {
    public IList<IList<int>> Subsets(int[] nums) {
        var result=new List<IList<int>>();
        result.Add(new List<int>());

        int len=nums.Length;

        for(int i=0;i<len;i++)
        {
            int l=result.Count();
            for(int j=0;j<l;j++)
            {
                var list=result[j].ToList();
                list.Add(nums[i]);
                result.Add(list);
            }
        }
        return result;
    }
}