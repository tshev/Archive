#ifndef PRIMES
#define PRIMES
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

template<typename T>
class gries_misra_t {
    T n;
    std::vector<T> primes;
    std::vector<T> num;
    std::function<T(T)> sqrt = [](T x) { return static_cast<T>(std::sqrt(x)) + 1; };
public:
    gries_misra_t() = default;

    gries_misra_t(T n) {
        prefetch(n);
    }

    template<typename F>
    gries_misra_t(T n, F _sqrt) : sqrt{_sqrt} {
        prefetch(n);
    }

   /* T operator()(T n) const {
        return primes[n];
    }*/

    T operator()(T n) {
        if ( n >= primes.size()) {
            prefetch(n * n);
        }
        return primes[n];
    }

    size_t size() const {
        return primes.size();
    }
private:
    void prefetch(T n) {
        num.resize(n + 1);
        std::fill(num.begin(), num.end(), 0);
        primes.reserve(sqrt(num.size()));
        for (T i = 2; i <= n; ++i) {
            if (num[i] == 0) {
                num[i] = i;
                if (std::lower_bound(primes.begin(), primes.end(), i) == primes.end());
                    primes.push_back(i);
            }

            for(T j = 0; j < primes.size() && primes[j] <= num[i] && i * primes[j] <= n; j++) {
                auto index = i * primes[j];
                if (index >= num.size() || primes[j] > num[i]) {
                    break;
                }
                num[index] = primes[j];
            }
        } 
    }
};

#endif
