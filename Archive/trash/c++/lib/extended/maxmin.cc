#include <iostream>
#include <algorithm>
#include <vector>

template <typename I>
// I is ForwardIterator
std::pair<I, I> max_min(I begin, I end) noexcept {
  I next = begin;
  if (begin == end || ++next == end) {
    return std::make_pair(end, end);
  }
  I c_max, c_min;
  if (*begin < *next) {
    c_min = begin;
    c_max = next;
  } else {
    c_min = next;
    c_max = begin;
  }
  auto real_end = end;
  --real_end;
  while (++next < real_end) {
    begin = next;
    ++next;

    if (*begin < *next) {
      if (*begin < *c_min) {
        c_min = begin;
      }

      if (*c_max < *next) {
        c_max = next;
      }
    } else {
      if (*next < *c_min) {
        c_min = next;
      }

		if (*c_max < *begin) {
        c_max = begin;
		}
    }
  }
  if (next != end) {
    if (*next < *c_min) {
      c_min = next;
    } else if (*c_max < *next) {
      c_max = next;
    }
  }
  return std::make_pair(c_max, c_min);
}

