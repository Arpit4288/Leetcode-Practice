class MyCircularDeque {
public:
    vector<int> dq;
    int size, capacity, front, back;
    MyCircularDeque(int k) {
        dq.resize(k, -1);
        front = 0;
        size = 0;
        back = k - 1;
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;
        front = (front - 1 + capacity) % capacity;
        dq[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;
        back = (back + 1) % capacity;
        dq[back] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;
        back = (back - 1 + capacity) % capacity;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        return dq[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;
        return dq[back];
    }

    bool isEmpty() {
        if (size == 0)
            return true;
        return false;
    }

    bool isFull() {
        if (size == capacity)
            return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */