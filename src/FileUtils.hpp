#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace Project5 {
int readDataArray(const std::string &filePath, int bufferSize, double buffer[]);
std::vector<double> readDataVector(std::string filePath);
} // namespace Project5
