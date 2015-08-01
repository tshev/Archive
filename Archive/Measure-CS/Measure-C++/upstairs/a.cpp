#include <array>
#include <algorithm>
#include <iterator>
#include <iostream>

template<int ...>
struct seq { };

template<int N, int ...S>
struct gens : gens<N-1, N-1, S...> { };

template<int ...S>
struct gens<0, S...> {
  typedef seq<S...> type;
};

constexpr int f(int n) {
	if (n==0)
		return 0;
	/*if (n==1)
		return 1;
	if (n==2)
		return 1;
	int last = 1;
	int end = 1;
	for (int i = 1; i < n; i++) {
		int tmp = end;
		end = last + end;
		last = tmp;
	}	*/
  return 3;
}

template <int N>
class array_thinger {
  typedef typename gens<N>::type list;

  template <int ...S>
  static constexpr std::array<int,N> make_arr(seq<S...>) {
    return std::array<int,N>{{f(S)...}};
  }
public:
  static constexpr std::array<int,N> arr = make_arr(list()); 
};

template <int N>
constexpr std::array<int,N> array_thinger<N>::arr;

int main() {
//  std::copy(begin(array_thinger<10>::arr), end(array_thinger<10>::arr))
//            std::ostream_iterator<int>(std::cout, "\n"));
	auto arr = array_thinger<10>::arr;
	std::cout << arr[0];
}
