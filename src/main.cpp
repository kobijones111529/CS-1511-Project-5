#include "ArrayUtils.hpp"
#include "FileUtils.hpp"
#include "Utils.hpp"
#include "Vec2.hpp"
#include "VectorUtils.hpp"

#include <fmt/format.h>

std::string formatPrice(double price) {
  return fmt::format(std::locale("en_US.UTF-8"), "${:.2Lf}", price);
}

int main() {
  // std::vector<Vec2> fooVec = {Vec2(0, 0), Vec2(1, 2), Vec2(3, 5)};
  // std::cout << Project5::Vector::calculateMean(fooVec.begin(), fooVec.end(),
  //                                              Vec2(0, 0))
  //                  .y
  //           << std::endl;

  const std::string filePath = "prices.txt";
  const int bufferSize = 100;

  // Using array
  std::cout << "Using array:" << std::endl;

  double array[bufferSize];

  // Read prices from file
  int arraySize = Project5::readDataArray(filePath, bufferSize, array);

  // Calculate mean
  double arrayMean = Project5::Array::calculateMean(array, arraySize);
  // double arrayMean = Project5::Vector::calculateMean(std::begin(array),
  // std::begin(array) + arraySize);

  // Calculate median
  double arrayMedian = Project5::Array::calculateMedian(array, arraySize);
  // double arrayMedian = Project5::Vector::calculateMedian(std::begin(array),
  // std::begin(array) + arraySize, 0.0);

  std::cout << "Mean: " << formatPrice(arrayMean) << std::endl;
  std::cout << "Median: " << formatPrice(arrayMedian) << std::endl;

  // Using vector
  std::cout << "Using vector:" << std::endl;

  std::vector<double> vector = Project5::mapMaybe(
      Project5::readMaybeDouble(Project5::readDataVectorString(filePath)));

  // Calculate mean
  double vectorMean =
      Project5::Vector::calculateMean(vector.begin(), vector.end(), 0.0);

  // Calculate median
  double vectorMedian =
      Project5::Vector::calculateMedian(vector.begin(), vector.end(), 0.0);

  std::cout << "Mean: " << formatPrice(vectorMean) << std::endl;
  std::cout << "Median: " << formatPrice(vectorMedian) << std::endl;
}