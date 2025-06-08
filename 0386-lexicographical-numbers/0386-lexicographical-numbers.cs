public class Solution {
    public IList<int> LexicalOrder(int n) {
        List<int> result = new List<int>();
        Back(0, n, result);
        return result;
    }
    void Back(int last, int n, List<int> res) {
        if (last > n) {
            return;
        }
        if (last == n) {
            res.Add(last);
            return;
        }
        if (last != 0) {
            res.Add(last);
        }
        for (int i = 0; i <= 9; i++) {
            if (last * 10 + i == 0) {
                continue;
            }
            Back(last * 10 + i, n, res);
        }
    }
}