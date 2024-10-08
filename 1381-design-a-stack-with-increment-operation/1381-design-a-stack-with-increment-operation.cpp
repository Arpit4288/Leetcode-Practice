class CustomStack {
public:
    vector<int> stack;  
    int maxSize;         
    CustomStack(int maxSize) : maxSize(maxSize) {}

    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);  
        }
    }

    int pop() {
        if (stack.empty()) {
            return -1;           
        }

        int value = stack.back(); 
        stack.pop_back();         
        return value;            
    }

    void increment(int k, int val) {
        int size = stack.size();
        for (int i = 0; i < min(k, size); ++i) {
            stack[i] += val;      
        }
    }
};