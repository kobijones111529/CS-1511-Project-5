#pragma once

namespace Project5 {
namespace Array {

/**
 * @brief Insertion sort
 * 
 * @param data Initialized array
 * @param size Size of array
 */
void sort(double data[], int size) {
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

double calculateMean(const double data[], int size) {
  if (size < 1) {
    return 0;
  }

  double sum = 0;
  for (int i = 0; i < size; i++) {
    sum += data[i];
  }
  return sum / size;
}

double calculateMedianSorted(const double data[], int size) {
  if (size < 1) {
    return 0;
  }

  if (size % 2) {
    return data[(size - 1) / 2];
  } else {
    return (data[size / 2 - 1] + data[size / 2]) / 2;
  }
}

} // namespace Array
} // namespace Proejct5