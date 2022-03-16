#pragma once

#include <array>
#include <numeric>
#include <vector>

namespace Project5 {
namespace Vector {

double calculateMean(const std::vector<double> &values) {
  return (double)std::accumulate(values.begin(), values.end(), (double)0) /
         values.size();
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
    return (double)std::accumulate(middle.begin(), middle.end(), (double)0) /
           middle.size();
  }
}
} // namespace Vector
} // namespace Project5