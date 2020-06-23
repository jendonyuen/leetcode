#include <semaphore.h>

class FizzBuzz {
private:
    int i;
    int n;
    sem_t fizzSem;
    sem_t buzzSem;
    sem_t fizzbuzzSem;
    sem_t numberSem;

    void controller() {
        ++i;
        if (i > n) {
            sem_post(&fizzSem);
            sem_post(&buzzSem);
            sem_post(&fizzbuzzSem);
            sem_post(&numberSem);
        }
        else if (i % 3 == 0 && i % 5) sem_post(&fizzSem);
        else if (i % 3 && i % 5 == 0) sem_post(&buzzSem);
        else if (i % 3 == 0 && i % 5 == 0) sem_post(&fizzbuzzSem);
        else if (i % 3 && i % 5) sem_post(&numberSem);
    }

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
        sem_init(&fizzSem, 0, 0);
        sem_init(&buzzSem, 0, 0);
        sem_init(&fizzbuzzSem, 0, 0);
        sem_init(&numberSem, 0, 1);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            sem_wait(&fizzSem);
            if (i > n) break;
            printFizz();
            controller();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (i <= n) {
            sem_wait(&buzzSem);
            if (i > n) break;
            printBuzz();
            controller();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true) {
            sem_wait(&fizzbuzzSem);
            if (i > n) break;
            printFizzBuzz();
            controller();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true) {
            sem_wait(&numberSem);
            if (i > n) break;
            printNumber(i);
            controller();
        }
    }
};