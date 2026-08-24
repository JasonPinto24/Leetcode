# include <semaphore>
using semaphore= std::counting_semaphore<1>;
class ZeroEvenOdd {
private:
    int n;
    semaphore zeroturn{1};
    semaphore oddturn{0};
    semaphore eventurn{0};

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=1;i<=n;i++){
            zeroturn.acquire();
            printNumber(0);
            if(i%2==1){
                oddturn.release();
            }else{
                eventurn.release();
            }
        }
        
    }

    void even(function<void(int)> printNumber) {
        for(int i=2;i<=n;i+=2){
            eventurn.acquire();
            printNumber(i);
            zeroturn.release();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=1;i<=n;i+=2){
            oddturn.acquire();
            printNumber(i);
            zeroturn.release();
        }
    }
};