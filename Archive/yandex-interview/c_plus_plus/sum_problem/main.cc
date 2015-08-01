#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>
#include <unordered_map>
template <typename It, typename Map = std::unordered_multimap<
                           typename std::iterator_traits<It>::value_type,
                           typename std::iterator_traits<It>::value_type>>
// It is input iterator
std::pair<It, It>
find_pair_eq_sum(It b, It e, typename std::iterator_traits<It>::value_type n) {
  typedef typename std::iterator_traits<It>::value_type T;
  Map map;
  for (auto it = b; it != e; it++) {
    map.emplace(*it, n - *it);
  }
  auto item = std::find_if(map.begin(), map.end(), [&map](const auto &x) {
    auto res = map.equal_range(x.second);
    auto size = std::distance(res.first, res.second);
    switch (size) {
    case 0:
      return false;
    case 1:
      return x.second != res.first->second;
    default:
      return x.second == res.first->second;
    }
  });
  if (item == map.end()) {
    return std::make_pair(e, e);
  } else {
    auto first = std::find(b, e, item->first);
    auto second = std::find(b, e, item->second);
    if (second < first) {
      return std::make_pair(second, first);
    } else {
      return std::make_pair(first, second);
    }
  }
}

int main() {
  std::vector<int> a = {4, 4, 0};
  auto pair = find_pair_eq_sum(a.begin(), a.end(), 4);
  if (pair.first != a.end())
    std::cout << *pair.first << "\t" << *pair.second << std::endl;
  return 0;
}
