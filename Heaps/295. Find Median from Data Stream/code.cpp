class MedianFinder {
public:
    priority_queue<int> s; // Max-heap (stores the smaller half)
    priority_queue<int, vector<int>, greater<int>> g; // Min-heap (stores the larger half)

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(s.size() == 0){ // 1st insertion
            s.push(num);
            return;
        }
        else if(s.size() > g.size()){
           if(num < s.top()){
             g.push(s.top());
             s.pop();
             s.push(num);
           } 
           else{
             g.push(num);
           }
        }
        else{ // s.size() == g.size()
           if(num < s.top()) s.push(num);
           else{
             g.push(num);
             s.push(g.top());
             g.pop();
           } 
        }
    }
    
    double findMedian() {
        if(s.size() > g.size()) return (double)(s.top());
        else return (s.top() + g.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
