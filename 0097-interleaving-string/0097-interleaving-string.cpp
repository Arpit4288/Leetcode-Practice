class Solution {
    
    unordered_map<string, bool> mem;
    bool check(string s1, string s2, string s3, int l1, int l2, int l3, int p1, int p2, int p3){
        if(p3 == l3){
            return p1 == l1 && p2 == l2 ? true: false;
        }
        
        string key = to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);
        
        if(mem.find(key) != mem.end()) return mem[key];
        
        if(p1 == l1){
            return mem[key] = s3[p3] == s2[p2] ? check(s1, s2, s3, l1, l2 ,l3, p1, p2 + 1, p3 + 1): false;
        }
        
        if(p2 == l2){
            return mem[key] = s3[p3] == s1[p1] ? check(s1, s2, s3, l1, l2, l3, p1 + 1, p2, p3 + 1): false;
        }
        
        bool first = false, sec = false;
        
        if(s3[p3] == s1[p1]){
            first = check(s1, s2, s3, l1, l2, l3, p1 + 1, p2, p3 + 1);
        }
        
        if(s3[p3] == s2[p2]){
            sec = check(s1, s2, s3, l1, l2, l3, p1, p2 + 1, p3 + 1);
        }
        
        return mem[key] = first or sec;
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        
        if(l3 != l1 + l2) return false;
        return check(s1, s2, s3, l1, l2, l3, 0, 0, 0);
    }
};