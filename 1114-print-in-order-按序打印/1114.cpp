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