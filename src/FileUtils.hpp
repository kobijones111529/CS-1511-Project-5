#pragma once

#include "Utils.hpp"

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace Project5 {

size_t readDataArray(const std::string &filePath, int bufferSize,
                  double buffer[]) {
  std::ifstream fileStream;
  std::string line;

  fileStream.open(filePath);
  if (!fileStream.is_open()) {
    std::cerr << "Failed to open " << filePath << std::endl;
    return 0;
  }
  int i = 0;
  int lineNum = 1;
  while (i < bufferSize && fileStream >> line) {
    const auto readFailed = [](int line) {
      std::cerr << "Ignoring bad data on line " << line << std::endl;
    };
    try {
      double price = stod_strict(line);
      buffer[i] = price;
      i++;
    } catch (const std::invalid_argument &) {
      readFailed(lineNum);
    } catch (const std::out_of_range &) {
      readFailed(lineNum);
    }
    lineNum++;
  }
  return i;
}

std::vector<double> readDataVector(const std::string &filePath) {
  std::ifstream inStream;
  std::string line;
  std::vector<double> prices = {};

  inStream.open(filePath);
  if (!inStream.is_open()) {
    std::cerr << "Failed to open " << filePath << std::endl;
    return {};
  }
  int lineNum = 1;
  while (inStream >> line) {
    const auto readFailed = [](int line) {
      std::cerr << "Ignoring bad data on line " << line << std::endl;
    };
    try {
      size_t readSize;
      double price = stod_strict(line, &readSize);

      prices.push_back(price);
    } catch (const std::invalid_argument &) {
      readFailed(lineNum);
    } catch (const std::out_of_range &) {
      readFailed(lineNum);
    }
    lineNum++;
  }
  inStream.close();

  return prices;
}

} // namespace Project5
