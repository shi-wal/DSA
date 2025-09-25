// If an oxygen thread arrives at the barrier when no hydrogen threads are present, it must wait for two hydrogen threads.
// If a hydrogen thread arrives at the barrier when no other threads are present, it must wait for an oxygen thread and another hydrogen thread.

class H2O {
    int turn;
    mutex m;
    condition_variable cv;
public:
    H2O() {
        turn=0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(m);
        while(turn==2) cv.wait(lock);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        turn++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(m);
        while(turn!=2) cv.wait(lock);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        turn=0;
        cv.notify_all();
    }
};
