#include <algorithm>
#include <cmath>
#include <cstdint>
#include <vector>

namespace bit_converter {

using std::vector;

inline vector<uint8_t> i16_to_bytes(int16_t value, bool is_big_endian) {
  vector<uint8_t> result;
  result.reserve(sizeof(int16_t));
  if (is_big_endian) {
    result.push_back(static_cast<uint8_t>(value >> 8));
    result.push_back(static_cast<uint8_t>(value & 0xFF));
  } else {
    result.push_back(static_cast<uint8_t>(value & 0xFF));
    result.push_back(static_cast<uint8_t>(value >> 8));
  }
  return result;
}

inline vector<uint8_t> u16_to_bytes(uint16_t value, bool is_big_endian) {
  return i16_to_bytes(static_cast<uint16_t>(value), is_big_endian);
}

inline vector<uint8_t> i32_to_bytes(int32_t value, bool is_big_endian) {
  vector<uint8_t> result;
  result.reserve(sizeof(int32_t));
  if (is_big_endian) {
    for (int i = 0; i < sizeof(int32_t); i++) {
      result.push_back(static_cast<uint8_t>((value >> (24 - i * 8)) & 0xFF));
    }
  } else {
    for (int i = sizeof(int32_t) - 1; i >= 0; i--) {
      result.push_back(static_cast<uint8_t>((value >> (24 - i * 8)) & 0xFF));
    }
  }
  return result;
}

inline vector<uint8_t> u32_to_bytes(uint32_t value, bool is_big_endian) {
  return i32_to_bytes(static_cast<int32_t>(value), is_big_endian);
}

inline vector<uint8_t> i64_to_bytes(int64_t value, bool is_big_endian) {
  vector<uint8_t> result;
  result.reserve(sizeof(int64_t));
  if (is_big_endian) {
    for (int i = 0; i < sizeof(int64_t); i++) {
      result.push_back(static_cast<uint8_t>((value >> (56 - i * 8)) & 0xFF));
    }
  } else {
    for (int i = sizeof(int64_t) - 1; i >= 0; i--) {
      result.push_back(static_cast<uint8_t>((value >> (56 - i * 8)) & 0xFF));
    }
  }
  return result;
}

inline vector<uint8_t> u64_to_bytes(uint64_t value, bool is_big_endian) {
  return i64_to_bytes(static_cast<int64_t>(value), is_big_endian);
}

inline vector<uint8_t> create_bytes_from_bits(const vector<bool> &bits) {
  vector<uint8_t> result;
  size_t n = bits.size() / 8;
  result.reserve(n);
  for (int i = 0; i < static_cast<int>(n); i++) {
    uint8_t b = 0;
    for (int j = 0; j < 8; j++) {
      b = b + (bits[i * 8 + j] << j);
    }
    result.push_back(b);
  }
  return result;
}

inline vector<uint8_t> f32_to_bytes(float_t value, bool is_big_endian) {
  vector<bool> bits;
  bits.reserve(sizeof(float_t) * 8);
  bits.push_back(value < 0);

  int exponent;
  float_t mantissa = std::frexp(value, &exponent);
  exponent = (exponent - 1) + 127;

  for (int i = 0; i < 8; i++) {
    bits.push_back(exponent % 2);
    exponent = exponent / 2;
  }
  std::reverse(bits.begin() + 1, bits.begin() + 1 + 8);
  mantissa = mantissa * 2 - 1;
  for (int i = 0; i < 23; i++) {
    mantissa = mantissa * 2;
    if (mantissa >= 1.0) {
      mantissa = mantissa - 1.0;
      bits.push_back(true);
    } else {
      bits.push_back(false);
    }
  }
  if (is_big_endian) {
    return create_bytes_from_bits(bits);
  } else {
    std::reverse(bits.begin(), bits.end());
    return create_bytes_from_bits(bits);
  }
}

inline vector<uint8_t> f64_to_bytes(double_t value, bool is_big_endian) {
  vector<bool> bits;
  bits.reserve(sizeof(double_t) * 8);
  bits.push_back(value < 0);

  int exponent;
  double_t mantissa = std::frexp(value, &exponent);
  exponent = (exponent - 1) + 1023;

  for (int i = 0; i < 11; i++) {
    bits.push_back(exponent % 2);
    exponent = exponent / 2;
  }
  std::reverse(bits.begin() + 1, bits.begin() + 1 + 11);
  mantissa = mantissa * 2 - 1;
  for (int i = 0; i < 52; i++) {
    mantissa = mantissa * 2;
    if (mantissa >= 1.0) {
      mantissa = mantissa - 1.0;
      bits.push_back(true);
    } else {
      bits.push_back(false);
    }
  }
  if (is_big_endian) {
    return create_bytes_from_bits(bits);
  } else {
    std::reverse(bits.begin(), bits.end());
    return create_bytes_from_bits(bits);
  }
}

}; // namespace bit_converter