class ZeroEvenOdd {
private:
    int n;
    std::atomic<bool> isZero;
    std::atomic<bool> isOdd;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        isZero = true;
        isOdd = true;
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            while(!isZero) {
                std::this_thread::yield();
            }
            printNumber(0);
            isZero = false;
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            while(isZero || isOdd) {
                std::this_thread::yield();
            }
            printNumber(i);
            isZero = true;
            isOdd = true;
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            while(isZero || !isOdd) {
                std::this_thread::yield();
            }
            printNumber(i);
            isZero = true;
            isOdd = false;
        }
    }
};

/*
class ZeroEvenOdd {
private:
    int n;
    std::atomic<bool> isZero;
    std::atomic<bool> isOdd;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        isZero = true;
        isOdd = true;
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            while(!isZero.load(std::memory_order_acquire)) {
                std::this_thread::yield();
            }
            printNumber(0);
            isZero.store(false, std::memory_order_release);
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            while(isZero.load(std::memory_order_acquire) || 
                isOdd.load(std::memory_order_acquire)) {
                std::this_thread::yield();
            }
            printNumber(i);
            isZero.store(true, std::memory_order_release);
            isOdd.store(true, std::memory_order_release);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            while(isZero.load(std::memory_order_acquire) || 
                !isOdd.load(std::memory_order_acquire)) {
                std::this_thread::yield();
            }
            printNumber(i);
            isZero.store(true, std::memory_order_release);
            isOdd.store(false, std::memory_order_release);
        }
    }
};
*/