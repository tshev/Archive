#include <iostream>
#include <vector>
#include <mutex>
#include <atomic>
#include <thread>

void long_work() {
    std::cout << "Long_work\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}
struct current_t {
    int max;
    std::atomic<int> current;
    std::mutex mutex;
    current_t (int x) : max{x}, current{x} {
    }
    void operator()() {
        bool done = false;
        if (current.load() == -1) { std::cout <<"BEDAAAA\n"; }
        {
            if (current.load() == 0) {
                done = true;
                std::cout << current.load() << std::endl;
                current = max;
            } else {
                current.fetch_sub(1); //current--;
            }
        }
        if (done) {
            long_work();
        }
    }
};
int main() {
   current_t c(5);
   int n = 10000;
   std::vector<std::thread> workers;
   workers.reserve(n);
   for (int i = 0; i < n; i++) { workers.emplace_back([&c](){ for(int i = 0; i < 5; i++) { c(); } }); }
   for (auto &t : workers) { t.join(); }
}
