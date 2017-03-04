class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        cap=size;
        s=0;
        avg=0.0;
    }
    
    double next(int val) {
        if(s<cap){
            l.push_back(val);
            avg=((double)avg*s+val)/(s+1);
            s++;
        }
        else{
            avg=(avg*s-l.front()+val)/s;
            l.pop_front();
            l.push_back(val);
        }
        return avg;
    }
private:
int cap=0;
int s=0;
list<int>l;
double avg;
};

