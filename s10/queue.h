#pragma once
#include <queue>
#include <functional>
#include <mutex> // recursive_mutex
#include <condition_variable>

class Queue
{
public:
    using ItemType = std::function<void ()>;
private:
    std::queue<std::function<void ()>> tasks;
    std::mutex m;
    std::condition_variable c;
public:
    void push(ItemType item)
    {
        std::lock_guard lk(m);
        if (tasks.empty()) {
            c.notify_one();
        }
        tasks.push(item);
    }
    ItemType get(std::stop_token & st)
    {
        std::unique_lock lk(m);
        while (tasks.empty() && !st.stop_requested()) {
            c.wait(lk);
        }
        if (st.stop_requested()) {
            return {};
        }
        auto r = tasks.front();
        tasks.pop();
        return r;
    }
};