class Foo {
    int i;
public:
    Foo() {
        i = 1;
    }

    void first(function<void()> printFirst) {
        printFirst();
        i = 2;
    }

    void second(function<void()> printSecond) {
        while(i != 2) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        printSecond();
        i = 3;
    }

    void third(function<void()> printThird) {
        while(i != 3) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        printThird();
        i = 1;
    }
};

/*
class Foo {
    std::mutex mtx2;
    std::mutex mtx3;
public:
    Foo() {
        mtx2.lock();
        mtx3.lock();
    }

    void first(function<void()> printFirst) {
        printFirst();
        mtx2.unlock();
    }

    void second(function<void()> printSecond) {
        mtx2.lock();
        printSecond();
        mtx2.unlock();
        mtx3.unlock();
    }

    void third(function<void()> printThird) {
        mtx3.lock();
        printThird();
        mtx3.unlock();
    }
};
*/