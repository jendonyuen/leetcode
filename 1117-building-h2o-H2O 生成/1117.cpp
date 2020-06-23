class H2O {
    atomic<int> HNum = 0;
public:
    H2O() {
            
    }
    void hydrogen(function<void()> releaseHydrogen) {
        while(HNum.load() == 2) {
            std::this_thread::yield();
        }
        releaseHydrogen();
        HNum++;
    }

    void oxygen(function<void()> releaseOxygen) {
        while(HNum.load() != 2) {
            std::this_thread::yield();
        }
        releaseOxygen();
        HNum.store(0);
    }
};