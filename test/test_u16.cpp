#include "bit_converter/bit_converter.hpp"
#include <catch2/catch.hpp>

using std::vector;

TEST_CASE("test u16 to bytes", "[u16]") {
  auto get_bytes = [](uint16_t value, bool is_big_endian) -> vector<uint8_t> {
    vector<uint8_t> bytes(sizeof(uint16_t));
    bit_converter::u16_to_bytes(value, is_big_endian, bytes.begin());
    return bytes;
  };
  SECTION("value < 256") {
    REQUIRE(get_bytes(214, true) == vector<uint8_t>{0, 214});
    REQUIRE(get_bytes(214, false) == vector<uint8_t>{214, 0});
    REQUIRE(get_bytes(255, true) == vector<uint8_t>{0, 255});
    REQUIRE(get_bytes(255, false) == vector<uint8_t>{255, 0});
  }
  SECTION("value >= 256") {
    REQUIRE(get_bytes(256, true) == vector<uint8_t>{1, 0});
    REQUIRE(get_bytes(256, false) == vector<uint8_t>{0, 1});
    REQUIRE(get_bytes(65535, true) == vector<uint8_t>{255, 255});
    REQUIRE(get_bytes(65535, false) == vector<uint8_t>{255, 255});
  }
}