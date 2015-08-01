#include <string>
#include <iostream>
struct Counter {
    enum {access=0, less=1};
    static size_t counts[2];
};

size_t Counter::counts[2];

struct String : std::string, Counter {

    String() : std::string() {}
    String(const std::string& s) : std::string(s) {}
    template<typename S> String(S s) : std::string(s) {}

    char& operator[](unsigned int i) {
        counts[access]++;
        return std::string::operator[](i);
    }
    const char& operator[](unsigned int i) const {
        std::cout << "Call\n";
        counts[access]++;
        return std::string::operator[](i);
    }


};
void foo(const std::string &x) {
    std::cout << x[0] << std::endl;
}
int main() {
    String greatings = "hello world!";
    String x = greatings.substr(0, 3);
    std::cout << x << std::endl;
    return 0;
}
