#include <iostream>
#include <deque>
#include <mutex>
#include <algorithm>
#include <vector>
#include <memory>
#include <thread>
#include <atomic>
#include <future>

class progression_t {
  int _delta;
  std::atomic<int> _current;
public:
  progression_t(int current, int delta) : _delta{delta}, _current{current} {}
  int next() {
    return _current.fetch_add(_delta, std::memory_order_seq_cst);
  }
};

int main() {
  progression_t progression(2, 3);
  return 0;
}
