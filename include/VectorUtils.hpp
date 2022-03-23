#pragma once

#include <complex>
#include <numeric>

namespace Project5 {
namespace Vector {

/**
 * @brief Calculate mean of range
 *
 * @tparam T Data type
 * @tparam InputIterator Iterator type
 * @param first Start iterator
 * @param last End iterator
 * @param defaultValue Value if empty range
 * @return Mean
 */
template <typename T, typename InputIterator>
T calculateMean(InputIterator first, InputIterator last, T defaultValue) {
  if (first >= last) {
    return defaultValue;
  }
  return static_cast<T>(std::accumulate(first + 1, last, *first) /
                        static_cast<double>(last - first));
}

/**
 * @brief Calculate median of range
 *
 * @tparam T Data type
 * @tparam InputIterator Iterator type
 * @param first Start iterator
 * @param last End iterator
 * @param defaultValue Value if empty range
 * @param sorted Is data already sorted
 * @return Median
 */
template <typename T, typename InputIterator>
T calculateMedian(InputIterator first, InputIterator last, T defaultValue,
                  bool sorted = false) {
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
      return static_cast<T>(
          calculateMean(middle - 1, middle + 1, defaultValue));
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
    return static_cast<T>(
        calculate(dataSorted.begin(), dataSorted.end(), defaultValue));
  }
}

template <typename T, typename InputIterator>
T calculateStandardDeviation(InputIterator first, InputIterator last,
                             T defaultValue) {
  if (first >= last) {
    return defaultValue;
  }
  auto mean = calculateMean(first, last, defaultValue);
  auto binaryOp = [&mean](auto acc, auto x) {
    auto diff = x - mean;
    return acc + diff * diff;
  };
  auto diff0 = *first - mean;
  auto sum = std::accumulate(first + 1, last, diff0 * diff0, binaryOp);
  return std::sqrt(sum / static_cast<double>(last - first));
}

} // namespace Vector
} // namespace Project5