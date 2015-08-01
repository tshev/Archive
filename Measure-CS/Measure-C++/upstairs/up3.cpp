#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <fstream>
std::vector<int> readData(std::istream &cn) {
  int N;
  std::cin >> N;
  std::vector<int> list(N);
  for (int i = 0; i < N; i++) {
    cn >> list[i];
  }
  return list;
}
int solve(std::vector<int> list) {
  int N = list.size(), j = -1;
  if (N == 2) {
    if (abs(list[0] - list[1]) + list[1] - 1 <
        abs(list[0] - list[1]) + list[0] - 1) {
      return j;
    } else {
      return 1;
    }
  }
  if (N == 1) {
    return -1;
  }
  std::vector<int> zipped_difference(list.size());
  std::vector<int> range(list.size() - 1);
  std::iota(std::begin(range), std::end(range), 0);

  std::for_each(range.begin(), range.end(), [&zipped_difference, &list](int v) {
    zipped_difference[v] = abs(list[v + 1] - list[v]);
  });

  int base_sum =
      std::accumulate(zipped_difference.begin(), zipped_difference.end(), 0,
                      [](int x, int y) { return x + y; });
  int tmp, minvalue = base_sum;
  for (int i = 0; i < zipped_difference.size(); i++) {
    if (i > 0 && i < N - 2) {
      tmp = base_sum - zipped_difference[i - 1] - zipped_difference[i + 1] -
            zipped_difference[i] + abs(list[i - 1] - list[i + 1]) +
            abs(list[i + 1] - list[i]) + abs(list[i] - list[i + 2]);
    } else if (i == 0) {
      tmp = base_sum - zipped_difference[i] - zipped_difference[i + 1] +
            abs(list[i + 1] - list[i]) + abs(list[i] - list[i + 2]);
    } else if (i == N - 2) {
      tmp = base_sum - zipped_difference[i] - zipped_difference[i - 1] +
            abs(list[i + 1] - list[i - 1]) + abs(list[i + 1] - list[i]);
    }
    if (tmp < minvalue) {
      minvalue = tmp;
      j = i + 1;
    }
  }
  return j;
}
int main() {
  std::vector<int> v = readData(std::cin);
  std::cout << solve(v) << std::endl;
}
