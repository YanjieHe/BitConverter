#include "bit_converter/bit_converter.hpp"
#include <catch2/catch.hpp>

using std::vector;

TEST_CASE("test f32 to bytes", "[f32]") {
  auto get_bytes = [](float_t value, bool is_big_endian) -> vector<uint8_t> {
    vector<uint8_t> bytes(sizeof(float_t));
    bit_converter::f32_to_bytes(value, is_big_endian, bytes.begin());
    return bytes;
  };
  SECTION("floating-point numbers") {
    REQUIRE(get_bytes(3.14, false) == vector<uint8_t>{195, 245, 72, 64});
  }
}

TEST_CASE("test bytes to f32", "[f32]") {
  auto to_f32 = [](const vector<uint8_t> &bytes,
                   bool is_big_endian) -> float_t {
    return bit_converter::bytes_to_f32(bytes.begin(), is_big_endian);
  };
  SECTION("floating-point numbers") {
    REQUIRE(to_f32(vector<uint8_t>{195, 245, 72, 64}, false) == Approx(3.14F));
  }
}
