#include "FileUtils.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>

// Implementation of insertion sort
void sortArray(double data[], int size) {
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

double calculateMeanOfArray(const double data[], int size) {
  if (size < 1) {
    return 0;
  }

  double sum = 0;
  for (int i = 0; i < size; i++) {
    sum += data[i];
  }
  return sum / size;
}

double calculateMedianOfSortedArray(const double data[], int size) {
  if (size < 1) {
    return 0;
  }

  if (size % 2) {
    return data[(size - 1) / 2];
  } else {
    return (data[size / 2 - 1] + data[size / 2]) / 2;
  }
}

double calculateMeanOfVector(const std::vector<double> &values) {
  return std::accumulate(values.begin(), values.end(), 0) / (double)values.size();
}

double calculateMedianOfSortedVector(const std::vector<double> &values) {
  if (values.size() == 0) {
    return 0;
  }

  if (values.size() % 2) {
    return values[(values.size() - 1) / 2];
  } else {
    std::array<double, 2> middle = {values[values.size() / 2 - 1], values[values.size() / 2]};
    return std::accumulate(middle.begin(), middle.end(), 0) / middle.size();
  }
}

int main() {
  const std::string filePath = "prices.txt";
  const int bufferSize = 100;

  // Using array
  std::cout << "Using array:" << std::endl;

  double array[bufferSize];

  // Read prices from file
  int arraySize = Project5::readDataArray(filePath, bufferSize, array);

  // Sort data
  sortArray(array, arraySize);

  // Calculate mean
  double arrayMean = calculateMeanOfArray(array, arraySize);

  // Calculate median
  double arrayMedian = calculateMedianOfSortedArray(array, arraySize);

  std::cout << "Mean: " << arrayMean << std::endl;
  std::cout << "Median: " << arrayMedian << std::endl;

  // Using vector
  std::cout << "Using vector:" << std::endl;

  // Read prices from file
  std::vector<double> vector = Project5::readDataVector(filePath);

  // Sort data
  std::sort(vector.begin(), vector.end());

  // Calculate mean
  double vectorMean = calculateMeanOfVector(vector);

  // Calculate median
  double vectorMedian = calculateMedianOfSortedVector(vector);

  std::cout << "Mean: " << vectorMean << std::endl;
  std::cout << "Median: " << vectorMedian << std::endl;
}