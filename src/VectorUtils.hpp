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

double calculateMedian(const std::vector<double> &data, bool sorted) {
  if (data.size() == 0) {
    return 0;
  }

  const auto calculate = [](const std::vector<double> &data) {
    if (data.size() % 2) {
      return data[(data.size() - 1) / 2];
    } else {
      return calculateMean(
          {data[data.size() / 2 - 1], data[data.size() / 2]});
    }
  };

  if (sorted) {
    return calculate(data);
  } else {
    const std::vector<double> dataSorted = [&data]() {
      std::vector<double> dataSorted = data;
      std::sort(dataSorted.begin(), dataSorted.end());
      return dataSorted;
    }();
    return calculate(dataSorted);
  }
}

} // namespace Vector
} // namespace Project5