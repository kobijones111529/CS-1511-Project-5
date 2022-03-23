#pragma once

#include "Utils.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

namespace Project5 {

void printInvalidLines(const std::vector<int> &lines) {
  if (lines.size() < 1) {
    return;
  }

  std::stringstream ss;
  ss << "Ignoring bad data on line";
  if (lines.size() > 1) {
    ss << "s";
  }
  ss << " ";
  for (size_t i = 0; i < lines.size() - 1; i++) {
    ss << lines[i] << ", ";
  }
  ss << lines[lines.size() - 1];
  std::cerr << ss.str() << std::endl;
}

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
  std::vector<int> invalidLines = {};
  while (i < bufferSize && fileStream >> line) {
    std::optional<double> price = parseDouble(line);
    if (const auto &&p = parseDouble(line)) {
      buffer[i++] = *p;
    }
    lineNum++;
  }
  printInvalidLines(invalidLines);
  return i;
}

std::vector<std::string> readDataVectorString(const std::string &filePath) {
  std::ifstream inStream;

  inStream.open(filePath);
  if (!inStream.is_open()) {
    std::cerr << "Failed to open " << filePath << std::endl;
    return {};
  }

  std::string line;
  std::vector<std::string> data;
  while (inStream >> line) {
    data.push_back(line);
  }
  return data;
}

} // namespace Project5
