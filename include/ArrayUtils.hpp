#pragma once

#include <stdlib.h>

#include <complex>
#include <cstring>
#include <string>

namespace Project5 {
namespace Array {

/**
 * @brief Insertion sort
 *
 * @param data Initialized array
 * @param size Size of array
 */
void insertionSort(double data[], int size) {
  for (int i = 1; i < size; i++) {
    double value = data[i];
    int j = i - 1;

    while (j >= 0 && data[j] > value) {
      data[j + 1] = data[j];
      j--;
    }
    data[j + 1] = value;
  }
}

/**
 * @brief Selection sort
 *
 * @param data Initialized data
 * @param size Size of array
 */
void selectionSort(double data[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int s = i;
    for (int j = i + 1; j < size; j++) {
      if (data[j] < data[s])
        s = j;
    }
    std::swap(data[i], data[s]);
  }
}

/**
 * @brief Calculate mean of array
 *
 * @param data Initialized data
 * @param size Size of array
 * @return Mean
 */
double calculateMean(const double data[], int size) {
  if (size < 1) {
    return 0.0;
  }

  double sum = 0.0;
  for (int i = 0; i < size; i++) {
    sum += data[i];
  }
  return sum / size;
}

/**
 * @brief Calculate median of array
 *
 * @param data Initialized data
 * @param size Size of array
 * @param sorted Is data already sorted
 * @return Median
 */
double calculateMedian(const double data[], size_t size, bool sorted = false) {
  const auto calculate = [](const double data[], size_t size) {
    if (size < 1) {
      return 0.0;
    }

    if (size % 2) {
      return data[(size - 1) / 2];
    } else {
      return calculateMean(&data[size / 2 - 1], 2);
    }
  };

  if (sorted) {
    return calculate(data, size);
  } else {
    double dataSorted[size];
    memcpy(dataSorted, data, size * sizeof(double));
    selectionSort(dataSorted, size);
    return calculate(dataSorted, size);
  }
}

double calculateStandardDeviation(const double data[], size_t size) {
  double mean = calculateMean(data, size);
  double sum = 0;
  for (size_t i = 0; i < size; i++) {
    double diff = data[i] - mean;
    sum += diff * diff;
  }
  return std::sqrt(sum / size);
}

} // namespace Array
} // namespace Project5