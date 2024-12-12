class Solution
{
public:
    // // C++ program to demonstrate working of fill()
    // #include <bits/stdc++.h>
    // using namespace std;

    // int main ()
    // {
    //   vector<int> vect(8);

    //   // calling fill to initialize values in the
    //   // range to 4
    //   fill(vect.begin() + 2, vect.end() - 1, 4);

    //   for (int i=0; i<vect.size(); i++)
    //     cout << vect[i] << " ";

    //   return 0;
    // }
    // Output :
    // 0 0 4 4 4 4 4 0

    // filling the vector of pairs  -->>>    vector<pair<int,int>> arr(n+1, pair<int,int>({0,0}));
    // filling the vector of vectors -->>> vector<vector<bool>> visited(n, vector<bool>(n, false));

    // priority_queue<container, vector<container>, greater<container> > q;   // for min heap min at top  you can provide your own comparator at a place of greater  -->

    //  have to declare outside the class in leetcode
    // call this mycomp by mycomp; // something like this inside leetcode function
    // class myComparator
    // {
    // public:
    //     bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    //     {
    //         if (p1.first == p2.first)
    //             return p1.second < p2.second;

    //         return p1.first > p2.first;
    //     }
    // };

    // But if You want to pass some extra function to the comparator then--->

    // class mycomp
    // { // call this mycomp by   mycomp(k);  // something like this inside leetcode function
    //     int k;

    // public:
    //     mycomp(int p) : k(p) {}

    //     bool operator()(const vector<int> &arr1, const vector<int> arr2)
    //     {
    //         return arr1[k] > arr2[k];
    //     }
    // };

    // Iterate words form sentence
    // string str = "Anyone can learn any language very easily";
    // istringstream iss(str);
    // do
    // {
    //     string word;
    //     iss >> word;
    //     cout << word << endl;

    // } while (iss);

    // General syntax to declare the priority queue is priority_queue<data_type, container, comparator>
    //       the default values for container is vector<data_type> and for comparator is less<data_type>.
    //       It automatically take the datatype what to give.

    //       In case of max heap, we declare it as => priority_queue<int> maxHeap;
    //       Its basically a shorthand of this => priority_queue<int, vector<int>, less<int>> maxHeap;
    //       we don't write the defualt values

    //       and in case of min heap we declare it as => priority_queue<int, vector<int> greater<int>> minHeap;

    //  initalization of 2-D vector with all same value say -1 vector<vector<int>> dp(n, vector<int>(n, -1));

    // comperator for vector of pairs (sort a/c to the second element if second is equal then a/c to first)

    bool mycomp(pair<char, int> &a, pair<char, int> &b)
    { // call this mycomp by   mycomp;  // something like this inside leetcode function
        // it should be outside from the class onto leetcode for working
        if (a.second > b.second)
            return true;
        if (a.second == b.second)
            return (a.first > b.first);
        return false;
    }

    // for finding the GCD of two numbers
    // __gcd(a, b)  we can directly use predefine function as well
    int gcd(int a, int b)
    {
        // euclidean algorithm
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    // for fiinding the LCM
    int lcm(int a, int b)
    {
        // a*b = gcd(a,b) * lcm(a,b)  this is a standard formula
        return (a * b) / gcd(a, b);
    }

    // for finding the factorial of a number
    int fact(int n)
    {
        if (n == 0)
            return 1;
        return n * fact(n - 1);
    }

    // for checking the prime numbers
    bool isprime(int n)
    {
        // this implementation is 3 times faster than normal implementation
        if (n == 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    double powerWithN(double x, int n)
    {
        double res = 1;
        while (n > 0)
        {
            if (n & 1)
                res *= x;
            x *= x;
            n /= 2;
        }
        return res;
    }
    int powerWithMod(long long x, unsigned int y, int m)
    {
        // pow with mod when we have a big value
        int res = 1; // Initialize result

        x = x % m; // Update x if it is more than or
                   // equal to p

        if (x == 0)
            return 0; // In case x is divisible by p;

        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res * x) % m;

            // y must be even now
            y = y >> 1; // y = y/2
            x = (x * x) % m;
        }
        return res;
    }

    bool isPowOf2(int n)
    {
        return (n != 0) && ((n & (n - 1)) == 0);
    }

    string D_to_B(long n)
    {
        string ans = "";
        while (n > 0)
        {
            int r = n % 2;
            ans = to_string(r) + ans;
            n /= 2;
        }
        return ans;
    }

    int countDigits(int n)
    {
        return log10(n) + 1;
    }

    long long pickGifts(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>> q;

        for (int i = 0; i < arr.size(); i++)
        {
            q.push(arr[i]);
        }
        int count = 0;
        while (count < k)
        {
            // cout<<count<<" ";
            int temp = floor(sqrt((double)q.top()));
            q.pop();
            q.push(temp);
            count++;
        }
        // cout<<endl;
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            // cout<<arr[i]<<" ";
            sum += q.top();
            q.pop();
        }
        return sum;
    }
};