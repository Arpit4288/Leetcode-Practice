class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow = 0, fast = 0;
        do{
            slow = arr[slow];
            fast = arr[fast];
            fast = arr[fast];
        }
        while(arr[slow] != arr[fast]);

        slow = 0;
        int here = 0;
        while(slow != fast){
            slow = arr[slow];
            fast = arr[fast];
        }
        here = slow;
        return here;
    }
};