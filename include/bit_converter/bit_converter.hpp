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

}; // namespace bit_converter