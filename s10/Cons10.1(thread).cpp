#include <thread>
#include <iostream>

using std::cin, std::cout, std::endl;
using std::jthread, std::thread;
using std::ref;
// reference_wrapper

struct A
{
public:
    int counter = 0;
    ~A() {cout << __PRETTY_FUNCTION__ << endl;}
};

int main()
{
    jthread th;
    // jthread auto-join

    cout << jthread::hardware_concurrency() << endl;
    int x;
    cin >> x;
    th = jthread([a = x](std::stop_token st, int y){
        while (!st.stop_requested()) {
            cout << y << ',' << a << endl;
        }
    }, x);

    th.request_stop();
    th = jthread([](){
        A t;
    });
    th.detach();
    A aa;

    th = jthread([a = x](std::stop_token st, int y, A &aa){
        ++aa.counter;
        while (!st.stop_requested()) {
            cout << y << ',' << a << endl;
        }
    }, x, ref(aa));

    th.request_stop();
    th.join();
    cout << aa.counter << endl;
}