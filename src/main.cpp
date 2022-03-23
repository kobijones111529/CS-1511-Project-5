#include "ArrayUtils.hpp"
#include "FileUtils.hpp"
#include "Utils.hpp"
#include "Vec2.hpp"
#include "VectorUtils.hpp"

#include <fmt/format.h>

template <typename T> struct PriceData {
  T mean;
  T median;

  PriceData(T _mean, T _median) : mean(_mean), median(_median) {}
};

std::string formatPrice(double);
std::string prompt(const std::string &);
template <typename T = double>
PriceData<T> usingArrays(const std::string &, const int);
template <typename T = double> PriceData<T> usingVectors(const std::string &);

int main() {
  // std::vector<Vec2> fooVec = {Vec2(0, 0), Vec2(1, 2), Vec2(3, 5)};
  // std::cout << Project5::Vector::calculateMean(fooVec.begin(), fooVec.end(),
  //                                              Vec2(0, 0))
  //                  .y
  //           << std::endl;

  const std::string filePath = "prices.txt";
  const int bufferSize = 100;

  // Prompt user if program should use C style arrays or C++ style vectors
  bool useVectors = [](const std::string &input) {
    return input == "y" || input == "Y";
  }(prompt("Use fancy vector stuff (y/n): "));

  // Read and process data
  PriceData data =
      useVectors ? usingVectors(filePath) : usingArrays(filePath, bufferSize);

  // Print formatted data
  std::cout << "Mean: " << formatPrice(data.mean) << std::endl;
  std::cout << "Median: " << formatPrice(data.median) << std::endl;
}

/**
 * @brief Pretty currency formatting
 * 
 * @param price
 * @return Prettified string
 */
std::string formatPrice(double price) {
  return fmt::format(std::locale("en_US.UTF-8"), "${:.2Lf}", price);
}

/**
 * @brief Get input from user
 * 
 * @param msg Prompt for the user
 * @return Input
 */
std::string prompt(const std::string &msg) {
  std::string input;
  std::cout << msg;
  std::cin >> input;
  return input;
}

/**
 * @brief Get data using C style arrays
 * 
 * @tparam T Numerical type
 * @param filePath Path to data file
 * @param bufferSize Buffer size to allocate
 * @return Price data
 */
template <typename T>
PriceData<T> usingArrays(const std::string &filePath, const int bufferSize) {
  double data[bufferSize];
  int size = Project5::readDataFromFile(filePath, bufferSize, data);
  return PriceData<T>(Project5::Array::calculateMean(data, size),
                      Project5::Array::calculateMedian(data, size));
}

/**
 * @brief Get data using C++ style vectors
 * 
 * @tparam T Numerical type
 * @param filePath Path to data file
 * @return Price data
 */
template <typename T> PriceData<T> usingVectors(const std::string &filePath) {
  auto dataMaybe =
      Project5::readMaybeDouble(Project5::readDataFromFile(filePath));

  // Notify user of invalid lines in data file
  std::vector<int> invalidLines;
  for (int i = 0; i < dataMaybe.size(); i++) {
    if (!dataMaybe[i]) {
      invalidLines.push_back(i + 1);
    }
  }
  Project5::printInvalidLines(invalidLines);

  auto data = Project5::mapMaybe(dataMaybe);
  return PriceData<T>(
      Project5::Vector::calculateMean(data.begin(), data.end(), 0.0),
      Project5::Vector::calculateMedian(data.begin(), data.end(), 0.0));
}