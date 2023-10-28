class Solution {
public:
    int mod = 1000000007;

    // i -> number of characters in the current word
    // n -> length of required word
    // c -> last used character
    int solve(int i, char c, int n, unordered_map<string, int>&mp)
    {
        if(i==n)
            return 1; // if we have used n letters, ONE string is made

        //Memoization
        string st = "";
        st+=c;
        st+="-"+to_string(i);
        if(mp.find(st)!=mp.end())
            return mp[st];

        // Cases 
        // Case 1. Each vowel 'a' may only be followed by an 'e'.
        // Case 2. Each vowel 'e' may only be followed by an 'a' or an 'i'.
        // Case 3. Each vowel 'i' may not be followed by another 'i'.
        // Case 4. Each vowel 'o' may only be followed by an 'i' or a 'u'.
        // Case 5. Each vowel 'u' may only be followed by an 'a'.
        if(c=='a')
            return mp[st]=solve(i+1, 'e', n, mp);
        else if(c=='e')
            return mp[st]=(0LL+solve(i+1, 'a', n, mp) + solve(i+1, 'i', n, mp))%mod;
        else if(c=='i')
            return mp[st]=(0LL+solve(i+1, 'a', n, mp)+solve(i+1, 'e', n, mp) + solve(i+1, 'o', n, mp) + solve(i+1, 'u', n, mp))%mod;
        else if(c=='o')
            return mp[st]=(0LL+solve(i+1, 'i', n, mp) + solve(i+1, 'u', n, mp))%mod;
        else if(c=='u')
            return mp[st]=solve(i+1, 'a', n, mp);
        return 0;
    }
    int countVowelPermutation(int n) {
        unordered_map<string, int>mp;
        return (0LL+solve(1, 'a', n, mp) + solve(1, 'e', n, mp) + solve(1, 'i', n, mp) + solve(1, 'o', n, mp) + solve(1, 'u', n, mp))%mod;
    }
};