#pragma once

#include <queue>
#include <functional>
#include <mutex>

class Queue
{
public:
    using ItemType = std::function<void ()>;
private:
    std::queue<std::function<void ()>> tasks;
    std::mutex m;
public:
    void put(ItemType item)
    {
        std::lock_guard lk(m);
        tasks.push(item);
    }
    ItemType get()
    {
        std::lock_guard lk(m);
        auto r = tasks.front();
        tasks.pop();
        return r;
    }
};