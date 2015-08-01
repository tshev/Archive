#ifndef FRACTION_H
#define FRACTION_H
#include <string>
#include <iostream>
#include "gcd.hpp"
namespace ext {
template <typename T> 
// T is Semiregualr or Regular or TotallyOrdered
class fraction
{

  T m;
  T n;
public:
  // Semiregular:
  fraction(const fraction& x) : m(x.m), n(x.n) {} // could be implicitly declared
  fraction(): m(0), n(1) {}                                    // could be implicitly declared sometimes
  fraction(const T& x, const T& y): m(x), n(y) {
  }
  ~fraction() {}                                   // could be implicitly declared 
  fraction& operator=(const fraction& x) {        // could be implicitly declared 
    m = x.m;
    n = x.n;
    return *this;
  }
  template <typename U>
  fraction(const fraction<U>& x) : m(x.m), n(x.n) {}
//  template<typename Q>
  operator double() const { return  double(m) / double(n); }
  // Regular
  friend
  bool operator==(const fraction& x, const fraction& y) {
    x.prepare();
    y.prepare();
    return x.m == y.n && x.n == y.n;
  }
  friend
  bool operator!=(const fraction& x, const fraction& y) {
    return !(x == y);
  }
  // TotallyOrdered
  friend
  bool operator<(const fraction& x, const fraction& y) { 
    T this_lcm = lcm(x.n, y.n);
    fraction a(x.m * (this_lcm / x.n) , this_lcm);
    fraction b(y.m * (this_lcm / y.n) , this_lcm);
    return a.m < b.m;
  }
  friend
  bool operator>(const fraction& x, const fraction& y) {
    return y < x;
  }
  friend
  bool operator<=(const fraction& x, const fraction& y) {
    return !(y < x);
  }
  friend
  bool operator>=(const fraction& x, const fraction& y) {
    return !(x < y);
  } 

  fraction& prepare() {
    T this_gcd = gcd(m, n);
    m = m / this_gcd;
    n = n / this_gcd;
    return *this;
  }
  friend
  fraction operator+(const fraction& x, const fraction& y) {
    T this_lcm = lcm(x.n, y.n);
    fraction a(x.m * (this_lcm / x.n) , this_lcm);
    fraction b(y.m * (this_lcm / y.n) , this_lcm);
    fraction result(a.m + b.m, this_lcm);
    result.prepare();
    return result;
  }

  friend
  fraction operator-(const fraction& x, const fraction& y) {
    T this_lcm = lcm(x.n, y.n);
    fraction a(x.m * (this_lcm / x.n) , this_lcm);
    fraction b(y.m * (this_lcm / y.n) , this_lcm);

    fraction result(a.m - b.m, this_lcm);
    result.prepare();
    return result;
  }

  friend
  fraction operator*(const fraction& x, const fraction& y) {
    auto result = fraction (x.m * y.m, x.n* y.n);
    result.prepare();
    return result;
  }

  friend
  fraction operator/(const fraction& x, const fraction& y) {
    auto result = fraction (x.m * y.n, x.n* y.m);
    result.prepare();
    return result;
  }

  friend
  std::ostream& operator<<(std::ostream &out, const fraction& fraction) {
    std::string m = std::to_string(fraction.m);
    std::string n = std::to_string(fraction.n);
    std::string result = m + "/" + n;
    out << result;
    return out;
  }
};

#endif

}
