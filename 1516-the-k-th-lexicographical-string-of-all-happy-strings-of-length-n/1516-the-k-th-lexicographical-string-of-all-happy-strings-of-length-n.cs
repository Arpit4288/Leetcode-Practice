public class Solution {
    public string GetHappyString(int n, int k) {
        char[] ca=new char[n];
        k--; // adjust down since k=1 is the first possibility
        // all except the first character can be one of two possibilities
        // set from least significant bit
        for(int i=n-1; i>0; i--, k>>=1) { // backwards
            ca[i]=(char)(k&1); // write bit
        }
        // if first not 0-2, we are out of range
        if(k>2) return "";
        // set first letter
        char prev=ca[0]=(char)('a'+k);
        // set remaining letters
        for(int i=1; i<n; i++) {
            // prev=a:next=b,c - prev=b:next=a,c - prev=c:next=a,b
            prev=ca[i]="bcacab"[((prev-'a')<<1)+ca[i]];
        }
        return new string(ca);
    }
}