class MedianFinder {
   public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    MedianFinder() {}

    void addNum(int num) {
        // if curr is > top of minheap push into minheap
        // check and balance if diff > 1 then push the top to other side

        if (minheap.empty() || num > minheap.top())
            minheap.push(num);
        else
            maxheap.push(num);

        if (minheap.size() > maxheap.size() + 1) {
            int curr = minheap.top();
            minheap.pop();
            maxheap.push(curr);
        } else if (maxheap.size() > minheap.size() + 1) {
            int curr = maxheap.top();
            maxheap.pop();
            minheap.push(curr);
        }
    }

    double findMedian() {
        int size = minheap.size() + maxheap.size();
        double ans;
        if (size % 2 == 1) {
            if (minheap.size() > maxheap.size())
                ans = 1.0 * minheap.top();
            else
                ans = 1.0 * maxheap.top();
        } else {
            ans = (minheap.top() + maxheap.top()) / 2.0;
        }
        return ans;
    }
};
