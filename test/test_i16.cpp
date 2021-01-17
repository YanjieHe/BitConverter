#include "bit_converter/bit_converter.hpp"
#include <catch2/catch.hpp>

using std::vector;

TEST_CASE("test i16 to bytes", "[i16]") {
  auto get_bytes = [](int16_t value, bool is_big_endian) -> vector<uint8_t> {
    vector<uint8_t> bytes(sizeof(int16_t));
    bit_converter::i16_to_bytes(value, is_big_endian, bytes.begin());
    return bytes;
  };
  SECTION("value < 256") {
    REQUIRE(get_bytes(-4334, true) == vector<uint8_t>{239, 18});
    REQUIRE(get_bytes(-4334, false) == vector<uint8_t>{18, 239});
  }
  SECTION("value >= 256") {
    REQUIRE(get_bytes(30000, true) == vector<uint8_t>{117, 48});
    REQUIRE(get_bytes(30000, false) == vector<uint8_t>{48, 117});
  }
}
