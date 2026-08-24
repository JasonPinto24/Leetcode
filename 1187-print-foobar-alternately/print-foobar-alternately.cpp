# include <semaphore>
using semaphore = std::counting_semaphore<1>;
class FooBar {
private:
    int n;
    semaphore footurn{1};
    semaphore barturn{0};

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            footurn.acquire();
        	printFoo();
            barturn.release();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            barturn.acquire();
        	printBar();
            footurn.release();
        }
    }
};