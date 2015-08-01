namespace ext {
template<typename T>
T gcd(T x, T y) {
  T r;
  while (true) {
    r = x % y;
    if (r == 0) {
	return y;
    }
     else {
		x = y;
        y = r;
     }
  }
}
template<typename T>
T lcm(const T& x, const T& y) {
  return x * y / gcd(x, y);
}

}
