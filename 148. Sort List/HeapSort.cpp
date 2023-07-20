


class MinHeap {
    // helpers for navigating up/down the tree structure
    int capacity = 16;// if we run out of space, we can double it
    int size = 0;
    int *items = static_cast<int *>(malloc(sizeof(int) * capacity));

    int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }

    int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }

    int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }

    bool hasLeftChild(int index) { return getLeftChildIndex(index) < size; }

    bool hasRightChild(int index) { return getRightChildIndex(index) < size; }

    bool hasParent(int index) { return getParentIndex(index) >= 0; }

    int leftChild(int index) { return items[getLeftChildIndex(index)]; }

    int rightChild(int index) { return items[getRightChildIndex(index)]; }

    int parent(int index) { return items[getParentIndex(index)]; }


    void swap(int indexOne, int indexTwo) {
        int temp = items[indexOne];
        items[indexOne] = items[indexTwo];
        items[indexTwo] = temp;
    }

    void ensureExtraCapacity() {
        if (size == capacity) {
            items = static_cast<int *>(realloc(items, sizeof(int) * capacity * 2));
            capacity *= 2;
        }
    }

    void heapifyDown() {
        int index = 0;
        while (hasLeftChild(index)) {
            int smallerChildIndex = getLeftChildIndex(index);
            if (hasRightChild(index) && rightChild(index) < leftChild(index)) {
                smallerChildIndex = getRightChildIndex(index);
            }
            if (items[index] <= items[smallerChildIndex])break;// all is heapify
            swap(index, smallerChildIndex);
            index = smallerChildIndex;
        }


    }

    void heapifyUp() {
        int index = size - 1;
        while (hasParent(index) && parent(index) > items[index]) {
            swap(index, getParentIndex(index));
            index = getParentIndex(index);
        };


    }

public:
    void printHeap() {
        for (int i = 0; i < size; ++i) {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty() { return size == 0; }

    int getSize() { return size; }

    int peek() {
        if (size == 0)throw invalid_argument("Empty heap - underflow");
        return items[0];
    }

    int poll() {
        int item = peek();
        items[0] = items[size - 1];
        size--;
        heapifyDown();// to correct the heap order
        return item;
    }

    void add(int item) {
        ensureExtraCapacity();
        items[size] = item;
        size++;
        heapifyUp();
    }

};


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
    MinHeap minHeap;
    for (int num: nums) {
        minHeap.add(num);
    }

    nums.clear();
    while (!minHeap.isEmpty()) {
        nums.push_back(minHeap.poll());
    }
    return nums;

}   
  
};
