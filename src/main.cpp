#include "ArrayUtils.hpp"
#include "FileUtils.hpp"
#include "VectorUtils.hpp"


int main() {
  const std::string filePath = "prices.txt";
  const int bufferSize = 100;

  // Using array
  std::cout << "Using array:" << std::endl;

  double array[bufferSize];

  // Read prices from file
  int arraySize = Project5::readDataArray(filePath, bufferSize, array);

  // Sort data
  Project5::Array::sort(array, arraySize);

  // Calculate mean
  double arrayMean = Project5::Array::calculateMean(array, arraySize);

  // Calculate median
  double arrayMedian = Project5::Array::calculateMedianSorted(array, arraySize);

  std::cout << "Mean: " << arrayMean << std::endl;
  std::cout << "Median: " << arrayMedian << std::endl;

  // Using vector
  std::cout << "Using vector:" << std::endl;

  // Read prices from file
  std::vector<double> vector = Project5::readDataVector(filePath);

  // Sort data
  std::sort(vector.begin(), vector.end());

  // Calculate mean
  double vectorMean = Project5::Vector::calculateMean(vector);

  // Calculate median
  double vectorMedian = Project5::Vector::calculateMedianSorted(vector);

  std::cout << "Mean: " << vectorMean << std::endl;
  std::cout << "Median: " << vectorMedian << std::endl;
}