class MedianFinder {
public:
    priority_queue<int>mx;
    priority_queue<int,vector<int>,greater<int>>mn;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.empty() || num<mx.top()){
            mx.push(num);
        }else{
            mn.push(num);
        }

        if(mx.size()>mn.size()+1){
            mn.push(mx.top());
            mx.pop();
        }
        if(mn.size()>mx.size()+1){
            mx.push(mn.top());
            mn.pop();
        }
    }
    
    double findMedian() {
        if(mx.size() == mn.size()){
            return (mx.top()+mn.top())/2.0;
        }else{
           return mx.size()>mn.size()?mx.top():mn.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */