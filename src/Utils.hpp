#pragma once

#include <string>

namespace Project5 {

/**
 * @brief String to double conversion using stod,
 * but fails if the entire string is not read.
 * 
 * @param str 
 * @param idx 
 * @return double 
 */
double stod_strict(const std::string &str, size_t *idx = 0) {
  size_t read;
  double value = stod(str, &read);
  if (read == str.size()) {
    if (idx != nullptr) {
      *idx = read;
    }
    return value;
  } else {
    throw std::invalid_argument("stod_strict: no conversion");
  }
}
/**
 * @brief Wide string to double conversion using stod,
 * but fails if the entire string is not read.
 * 
 * @param str 
 * @param idx 
 * @return double 
 */
double stod_strict(const std::wstring &str, size_t *idx = 0) {
  size_t read;
  double value = stod(str, &read);
  if (read == str.size()) {
    if (idx != nullptr) {
      *idx = read;
    }
    return value;
  } else {
    throw std::invalid_argument("stod_strict: no conversion");
  }
}

} // namespace Project5