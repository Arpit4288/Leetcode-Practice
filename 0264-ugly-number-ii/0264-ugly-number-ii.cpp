class Solution {
public:
    int nthUglyNumber(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
         // Ugly number is a positive integer where the factors of it are limited to 2, 3 and 5
         // Given an integer n then we need to return the nth ugly number.
    // nth ugly number
    // 1 2 3 4 5 6 8 9 10 12
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    // Min heap is a tree ds where the root element is always lesser than the left and right child elements. And on adding a new element or popping out any old element the heapify function will be called.
    pq.push(1LL);
    // pq --> 1
    // pq --> 2, 3, 5
    // pq --> 3, 4, 5, 6, 10
    vector<int> primes{2LL, 3LL, 5LL};
    unordered_set<long long> us;
    long long currVal = LONG_LONG_MIN;
    for(int i = 1 ; i <= n ; i++){
        currVal = pq.top();
        pq.pop();
        for(auto &prime : primes){
            if(us.find(currVal * prime) == us.end()){
                pq.push(prime*currVal);
                us.insert(currVal * prime);
            }
            // Same number twice
        }
    }
    return currVal;
    }
};