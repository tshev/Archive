## namespace extended

### Function iota - put sequence of values with customizable step to output iterator

	template <typename ForwardIterator, typename T>
	void iota(ForwardIterator begin, ForwardIterator end, T value, const T &step);


	template <typename ForwardIterator, typename T> 
	void iota(ForwardIterator begin, size_t size, T value, const T &step);

### Fucntion gcd  - greatest commond divisor
	template <typename T> T gcd(T x, T y);

### Class fraction

template <typename T> class fraction;

