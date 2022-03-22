#pragma once

#include <algorithm>
#include <optional>
#include <string>
#include <vector>

namespace Project5 {

/**
 * @brief String to double conversion using stod,
 * but fails if the entire string is not read.
 *
 * @param str
 * @param idx
 * @return double
 */
double stod_strict(const std::string &str, size_t *idx = nullptr) {
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
double stod_strict(const std::wstring &str, size_t *idx = nullptr) {
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

template <class Src, class Dst, class F>
void transform_if(Src &&src, Dst &&dst, F &&f) {
  for (auto &&x : std::forward<Src>(src)) {
    if (auto &&e = f(decltype(x)(x))) {
      *dst++ = *decltype(e)(e);
    }
  }
}

std::optional<double> parseDouble(const std::string &str) {
  try {
    double value = stod_strict(str);
    return std::optional(value);
  } catch (const std::invalid_argument &) {
  } catch (const std::out_of_range &) {
  }
  return std::nullopt;
}

std::vector<std::optional<double>>
readMaybeDouble(const std::vector<std::string> &vec) {
  std::vector<std::optional<double>> out;
  std::transform(vec.begin(), vec.end(), std::back_inserter(out), parseDouble);
  return out;
}

template <typename T>
std::vector<T> mapMaybe(const std::vector<std::optional<T>> &vec) {
  std::vector<T> out;
  transform_if(vec, std::inserter(out, out.begin()),
               [](const std::optional<T> opt) { return opt; });
  return out;
}

} // namespace Project5