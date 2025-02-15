public class Solution {
    public bool IsValid(string s) {
        Stack<char> st = new Stack<char>();
        
        for(int i = 0; i < s.Length; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.Push(s[i]);
            }
            else{
                char c = s[i];
                switch(c){
                    case ')':
                        if(st.Count() > 0 && st.Peek() == '(') st.Pop();
                        else return false;
                        break;
                    case '}':
                        if(st.Count() > 0 && st.Peek() == '{') st.Pop();
                        else return false;
                        break;
                    case ']':
                        if(st.Count() > 0 && st.Peek() == '[') st.Pop();
                        else return false;
                        break;
                    default:
                        return false;
                }
            }
        }
        if(st.Count() == 0) return true;
        return false;
    }
}