#include "ArrayUtils.hpp"
#include "FileUtils.hpp"
#include "Utils.hpp"
#include "VectorUtils.hpp"

#include "fmt/format.h"

class Vec2 {
public:
  double x, y;

  Vec2() : x(0), y(0) {}
  Vec2(double _x, double _y) : x(_x), y(_y) {}
  Vec2(const Vec2 &o) : x(o.x), y(o.y) {}
  Vec2(Vec2 &&o) noexcept : x(0), y(0) { *this = std::move(o); }
  Vec2 &operator=(Vec2 &&o) noexcept {
    if (this != &o) {
      x = std::move(o.x);
      y = std::move(o.y);
      return *this;
    }
    return *this;
  }
  Vec2 operator+(const Vec2 &right) const {
    return Vec2(x + right.x, y + right.y);
  }
  Vec2 operator-(const Vec2 &right) const {
    return Vec2(x - right.x, y - right.y);
  }
  template <typename T> Vec2 operator*(const T &right) const {
    return Vec2(x * right, y * right);
  }
  template <typename T> Vec2 operator/(const T &right) const {
    return Vec2(x / right, y / right);
  }
};

int main() {
  std::vector<Vec2> fooVec = {Vec2(0, 0), Vec2(1, 2), Vec2(3, 5)};
  std::cout << Project5::Vector::calculateMean(fooVec.begin(), fooVec.end(),
                                               Vec2(0, 0))
                   .y
            << std::endl;

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

  std::cout << "Mean: " << fmt::format(std::locale("en_US"), "${:.2Lf}", arrayMean) << std::endl;
  std::cout << "Median: " << fmt::format(std::locale("en_US"), "${:.2Lf}", arrayMedian) << std::endl;

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

  std::cout << "Mean: " << fmt::format(std::locale("en_US"), "${:.2Lf}", vectorMean) << std::endl;
  std::cout << "Median: " << fmt::format(std::locale("en_US"), "${:.2Lf}", vectorMedian) << std::endl;
}