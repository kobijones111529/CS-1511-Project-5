#pragma once

#include <optional>
#include <vector>

namespace Project5 {

/**
 * @brief std::identity works in Clang 13.0.0 but not GCC 9.3.0 so I just copied
 * a possible implementation
 */
struct identity {
  using is_transparent = void;

  template <typename T> constexpr T &&operator()(T &&t) const noexcept {
    return std::forward<T>(t);
  }
};

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

template <typename Src, typename Dst, typename F = identity>
void transform_if(Src &&src, Dst &&dst, F &&f = {}) {
  for (auto &&x : std::forward<Src>(src)) {
    if (auto &&e = f(decltype(x)(x))) {
      *dst++ = *decltype(e)(e);
    }
  }
}

/**
 * @brief Parse string to double
 *
 * @param str String to parse
 * @return Value or empty
 */
std::optional<double> parseDouble(const std::string &str) {
  try {
    double value = stod_strict(str);
    return std::optional(value);
  } catch (const std::invalid_argument &) {
  } catch (const std::out_of_range &) {
  }
  return std::nullopt;
}

/**
 * @brief Parse list of strings to doubles
 *
 * @param vec Strings to parse
 * @return List of optionals
 */
std::vector<std::optional<double>>
readMaybeDouble(const std::vector<std::string> &vec) {
  std::vector<std::optional<double>> out;
  std::transform(vec.begin(), vec.end(), std::back_inserter(out), parseDouble);
  return out;
}

/**
 * @brief Haskell inspired optional filtering
 *
 * @tparam T Inner type
 * @param vec List of optionals
 * @return Filtered list
 */
template <typename T>
std::vector<T> mapMaybe(const std::vector<std::optional<T>> &vec) {
  std::vector<T> out;
  transform_if(vec, std::back_inserter(out));
  return out;
}

} // namespace Project5