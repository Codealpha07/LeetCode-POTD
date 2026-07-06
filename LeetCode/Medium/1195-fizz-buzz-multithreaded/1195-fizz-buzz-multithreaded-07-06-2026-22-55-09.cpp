class FizzBuzz {
private:
    int limit;
    int current;
    mutex mutexLock;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        limit = n;
        current = 1;
    }

    void fizz(function<void()> printFizz) {
        while (current <= limit) {
            unique_lock<mutex> lock(mutexLock);

            while (current <= limit && !(current % 3 == 0 && current % 5 != 0)) cv.wait(lock);
            if (current <= limit) {
                printFizz();
                current++;
            }
            cv.notify_all();
        }
    }
    void buzz(function<void()> printBuzz) {
        while (current <= limit) {
            unique_lock<mutex> lock(mutexLock);

            while (current <= limit &&
                   !(current % 5 == 0 && current % 3 != 0))
                cv.wait(lock);

            if (current <= limit) {
                printBuzz();
                current++;
            }

            cv.notify_all();
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while (current <= limit) {
            unique_lock<mutex> lock(mutexLock);

            while (current <= limit &&
                   !(current % 3 == 0 && current % 5 == 0))
                cv.wait(lock);

            if (current <= limit) {
                printFizzBuzz();
                current++;
            }

            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (current <= limit) {
            unique_lock<mutex> lock(mutexLock);

            while (current <= limit &&
                   !(current % 3 != 0 && current % 5 != 0))
                cv.wait(lock);

            if (current <= limit) {
                printNumber(current);
                current++;
            }

            cv.notify_all();
        }
    }
};