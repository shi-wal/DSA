// Modify the given class to output the series "010203040506..." where the length of the series must be 2n.

class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cv;
    int turn;
    int i;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        turn=0;
        i=1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(turn!=0 && i<=n) cv.wait(lock);
            if(i>n) break;
            printNumber(0);
            turn=i%2?1:2;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(turn!=2 && i<=n) cv.wait(lock);
            if(i>n) break;
            printNumber(i++);
            turn=0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(turn!=1 && i<=n) cv.wait(lock);
            if(i>n) break;
            printNumber(i++);
            turn=0;
            cv.notify_all();
        }
    }
};
