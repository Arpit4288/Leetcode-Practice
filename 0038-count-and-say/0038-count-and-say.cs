public class Solution {    
    public string CountAndSay(int n) {
        char[] curr=new char[] { '1' };
        while(n-->1) {
            // calculate length of next string
            char prev=' ';
            int count=0, i=0, l=curr.Length;
            for(; i<curr.Length; i++) {
                char ch=curr[i];
                if(ch==prev) l--;
                prev=ch;
            }
            // allocate next string
            char[] next=new char[l<<1];
            // build next string
            prev=curr[0];            
            for (i=l=0; i<curr.Length; i++, count++) {
                char ch=curr[i];
                if (ch!=prev) {
                    next[l++]=(char)('0'+count); count=0;
                    next[l++]=prev; prev=ch;
                }
            }
            next[l++]=(char)('0'+count);
            next[l]=prev;
            curr=next;
        }
        return new string(curr);
    }
}