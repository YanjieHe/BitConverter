#include "bit_converter/bit_converter.hpp"
#include <catch2/catch.hpp>

using std::vector;

TEST_CASE("test f64 to bytes", "[f64]") {
  auto get_bytes = [](double_t value, bool is_big_endian) -> vector<uint8_t> {
    vector<uint8_t> bytes(sizeof(double_t));
    bit_converter::f64_to_bytes(value, is_big_endian, bytes.begin());
    return bytes;
  };
  SECTION("floating-point numbers") {
    REQUIRE(get_bytes(3.14, false) ==
            vector<uint8_t>{31, 133, 235, 81, 184, 30, 9, 64});
  }
}

TEST_CASE("test bytes to f64", "[f64]") {
  auto to_f64 = [](const vector<uint8_t> &bytes,
                   bool is_big_endian) -> double_t {
    return bit_converter::bytes_to_f64(bytes.begin(), is_big_endian);
  };
  SECTION("floating-point numbers") {
    REQUIRE(to_f64(vector<uint8_t>{31, 133, 235, 81, 184, 30, 9, 64}, false) ==
            Approx(3.14));
  }
}
