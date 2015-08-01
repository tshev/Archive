#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
struct Bar;
struct Foo;

struct Bar {
    void operator()(int) {
        Foo foo;
        std::vector<int> vec(2 << 20);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        foo();
    }
};
struct Foo {
    void operator()() {
        Bar bar;
        bar();
    }
};
int main() {
    foo();
}
