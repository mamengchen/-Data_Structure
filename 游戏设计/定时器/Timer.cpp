#include <iostream>
#include <chrono>
#include <functional>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>

/*
设计一个通用定时器时，主要需求包括执行定时任务的间隔控制、任务的添加与取消、重复执行以及保证线程安全等。
设计需求：
1.支持多任务：允许同时添加多个定时任务。
2.单次与周期性执行：支持一次性执行的任务和周期性执行的任务。
3.任务管理：可以添加、取消、查询任务。
4.线程安全：适应多线程环境，避免数据竞争和死锁。
5.高效的任务调度：支持大规模任务，尽可能减少 CPU 和内存开销。

可以使用以下的设计框架来实现定时器：
1.1 任务队列和优先队列
|| 使用优先队列存储任务，可以根据任务的下次执行时间排序，确保最先到达的任务被优先执行。
|| 优先队列可以使用小顶端（std::priority_queue）来存储和管理任务。
1.2 调度线程
|| 创建一个单独的调度线程，不断检查优先队列中最近的任务是否到期。如果到期则取出执行，然后更新下次执行时间或删除。
1.3 线程安全
|| 使用 std::mutex 保护优先队列，避免多线程环境下的竞争。
|| 使用 std::condition_varible 控制调度线程的休眠和唤醒。
*/ 

class Timer {
public:
    Timer() : stopFlag(false) {
        worker = std::thread([this](){run();});
    }

    ~Timer() {
        stop();
    }


    // 添加定时任务
    void addTask(int delay, std::function<void()> func, bool repeat = false) {
        std::lock_guard<std::mutex> lock(mtx);
        auto execTime = std::chrono::steady_clock::now() + std::chrono::milliseconds(delay);
        tasks.push({execTime, func, delay, repeat});
        cv.notify_one();
    }

    // 停止所有任务
    void stop() {
        stopFlag.store(true);
        cv.notify_one();
        if (worker.joinable()) {
            worker.join();
        }
    }
private:
    struct Task
    {
        std::chrono::steady_clock::time_point exectime;
        std::function<void()> func;
        int interval;
        bool repeat;
        bool operator<(const Task& other) const {
            return exectime > other.exectime;
        }
    };
    


    std::priority_queue<Task> tasks;   // 优先队列
    std::mutex mtx;                 // 锁
    std::thread worker;             // 工作线程
    std::atomic<bool> stopFlag;
    std::condition_variable cv;

    // 调度线程运行逻辑
    void run() {
        while (!stopFlag.load())
        {
            std::unique_lock<std::mutex> lock(mtx);
            if (tasks.empty())
            {
                cv.wait(lock);
            }
            else {
                auto now = std::chrono::steady_clock::now();
                if (tasks.top().exectime <= now) {
                    auto task = tasks.top();
                    tasks.pop();
                    lock.unlock();

                    task.func(); // 执行任务。
                    if (task.repeat)
                    {
                        task.exectime = now + std::chrono::milliseconds(task.interval);
                        std::lock_guard<std::mutex> lk(mtx);
                        tasks.push(task);
                        cv.notify_one();
                    }
                } 
                else
                {
                    cv.wait_until(lock, tasks.top().exectime); // 等到下一个任务到
                }
            }
            
        }
        
    }
};

int main() {
    Timer timer;

    timer.addTask(1000, [](){
        std::cout << "task 1 exectued" << std::endl;
    });

    timer.addTask(2000,[](){
        std::cout << "task 2 exectued" << std::endl;
    }, true);

    std::this_thread::sleep_for(std::chrono::seconds(10));
    timer.stop();

    return 0;
}
