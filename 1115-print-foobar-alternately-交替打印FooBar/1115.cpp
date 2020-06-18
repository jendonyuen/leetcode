class FooBar {
private:
    int n;
    mutex mtxFoo;
    mutex mtxBar;

public:
    FooBar(int n) {
        this->n = n;
        mtxBar.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            mtxFoo.lock();
        	printFoo();
            mtxBar.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            mtxBar.lock();
        	printBar();
            mtxFoo.unlock();
        }
    }
};