#pragma once

#include <array>
#include <numeric>
#include <vector>

namespace Project5 {
namespace Vector {

double calculateMean(const std::vector<double> &values) {
  return std::accumulate(values.begin(), values.end(), 0) /
         (double)values.size();
}

double calculateMedianSorted(const std::vector<double> &values) {
  if (values.size() == 0) {
    return 0;
  }

  if (values.size() % 2) {
    return values[(values.size() - 1) / 2];
  } else {
    std::array<double, 2> middle = {values[values.size() / 2 - 1],
                                    values[values.size() / 2]};
    return std::accumulate(middle.begin(), middle.end(), 0) / middle.size();
  }
}
} // namespace Vector
} // namespace Project5