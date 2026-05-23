class MedianFinder {
   public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    MedianFinder() {}

    void addNum(int num) {

        if (minheap.empty() || num > minheap.top())
            minheap.push(num);
        else
            maxheap.push(num);

        if (minheap.size() > maxheap.size() + 1) {
            maxheap.push(minheap.top());
            minheap.pop();
        } 
        
        else if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }

    double findMedian() {

        if ((minheap.size() + maxheap.size()) % 2) {

            if (minheap.size() > maxheap.size())
                return minheap.top();

            return maxheap.top();
        }

        return (minheap.top() + maxheap.top()) / 2.0;
    }
};