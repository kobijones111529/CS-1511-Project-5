#pragma once

#include <numeric>

namespace Project5 {
namespace Vector {

template <typename T, typename InputIterator>
T calculateMean(InputIterator first, InputIterator last, T defaultValue) {
  if (first >= last) {
    return defaultValue;
  }
  return static_cast<T>(std::accumulate(first + 1, last, *first) /
         static_cast<double>(last - first));
}

template <typename T, typename InputIterator>
T calculateMedian(InputIterator first, InputIterator last, T defaultValue, bool sorted = false) {
  if (first >= last) {
    return defaultValue;
  }

  const auto calculate = [](auto first, auto last, auto defaultValue) {
    if (first >= last) {
      return defaultValue;
    }
    auto count = last - first;
    if (count % 2) {
      return static_cast<T>(*(first + (count - 1) / 2));
    } else {
      auto middle = first + count / 2;
      return static_cast<T>(calculateMean(middle - 1, middle + 1, defaultValue));
    }
  };

  if (sorted) {
    return static_cast<T>(calculate(first, last, defaultValue));
  } else {
    auto count = last - first;
    const auto dataSorted = [](auto first, auto last) {
      auto dataSorted = std::vector(first, last);
      std::sort(dataSorted.begin(), dataSorted.end());
      return dataSorted;
    }(first, last);
    return static_cast<T>(calculate(dataSorted.begin(), dataSorted.end(), defaultValue));
  }
}

} // namespace Vector
} // namespace Project5