#include "queue.h"

#include <thread>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

constexpr int WCOUNT = 10;
constexpr int JCOUNT = 1000;

int main()
{
    Queue q;
    vector<jthread> workers;

    for (int i = 0; i < WCOUNT; ++i) {
        workers.emplace_back([&q](stop_token st, int serial) {
            while (!st.stop_requested()) {
                auto item = q.get(st);
                if (!item) break;
                ostringstream oss;
                oss << "Thread " << serial << " working" << endl;
                cout << oss.str();
                item();
            }
        }, i);
    }

    for (int i = 0; i < JCOUNT; ++i) {
        q.push([i]() {
            ostringstream oss;
            oss << "Executing " << i << endl;
            cout << oss.str();
        });
    }
}