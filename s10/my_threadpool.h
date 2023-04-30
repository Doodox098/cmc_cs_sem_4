#include "queue.h"

#include <thread>

class Worker
{
    std::jthread thr;
    std::atomic_bool stop_requested{};
    std::atomic_bool stopped{};

    void run () {
        while (!stop_requested) {

        }
        stopped = true;
    }
public:
    void start () {
        thr = std::jthread([this]() {run();});
    }
    void request_stop() noexcept {
        stop_requested = true;
    }
};