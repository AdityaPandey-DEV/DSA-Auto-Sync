class MedianFinder {
public:
    priority_queue<int> leftMax;  
    priority_queue<int, vector<int>, greater<int>> rightMin;  

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftMax.push(num);
        rightMin.push(leftMax.top());
        leftMax.pop();
        if (rightMin.size() > leftMax.size()) {
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }
    
    double findMedian() {
        if (leftMax.size() > rightMin.size()) {
            return leftMax.top();
        }
        return (leftMax.top() + rightMin.top()) / 2.0;
    }
};