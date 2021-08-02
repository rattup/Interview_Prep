class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int> > minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int l=maxheap.size();
        int r=minheap.size();
        if(l==r)
        {
            if(maxheap.size()==0)
            maxheap.push(num);
            else
            {
                if(num<maxheap.top())
                maxheap.push(num);
                else
                {
                    minheap.push(num);
                    int temp=minheap.top();
                    minheap.pop();
                    maxheap.push(temp);
                }
            }
            
        }
        else
        {
            if(maxheap.size()==1)
            {
               if(num>maxheap.top())
                 minheap.push(num);
                else
                {
                    int temp=maxheap.top();
                    maxheap.pop();
                    maxheap.push(num);
                    minheap.push(temp);
                }
                
            }
            else
            {
                if(num>maxheap.top())
                minheap.push(num);
                else
                {
                    int temp=maxheap.top();
                    maxheap.pop();
                    maxheap.push(num);
                    minheap.push(temp);
                }
                    
                
                
            }
            
        }
        
    }
    
    double findMedian() {
        int l=maxheap.size();
        int r=minheap.size();
        double res;
        if(l==r)
        {
            res=(double(maxheap.top()) +double(minheap.top()))/2.0;
            return res;
            
        }
        res=double(maxheap.top());
        return res;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
