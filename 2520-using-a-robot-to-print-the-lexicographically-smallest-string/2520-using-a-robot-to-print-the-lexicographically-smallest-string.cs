public class Solution {
    public string RobotWithString(string s) {
        var res = new StringBuilder();
        var n = s.Length;
        var min = 'a';
        var max = 'z';
        var last = 0;
        var stack = new Stack<char>(n);
        for (int cur = min; cur <= max; cur++) {
            while(stack.Count > 0 && stack.Peek() <= cur) {
                var c = stack.Pop();
                res.Append(c);
            }
            for (var i = last; i < n; i++) {
                if (s[i] == cur) {
                    for (int j = last; j < i; j++) {
                        stack.Push(s[j]);
                    }
                    res.Append(s[i]);
                    last = i + 1;
                }
            }
        }

        while(stack.Count > 0) {
            var c = stack.Pop();
            res.Append(c);
        }

        return res.ToString();
    }
}