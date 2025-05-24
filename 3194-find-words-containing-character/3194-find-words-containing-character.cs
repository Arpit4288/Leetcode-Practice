public class Solution {
    public IList<int> FindWordsContaining(string[] words, char x) {
         List<int> list=new List<int>();
         int i=0;
         foreach(string u in words){
              if(u.Contains(x)){
                  list.Add(i);
              }
              i++;
         }
         return list;
    }
}