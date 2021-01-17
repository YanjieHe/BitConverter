#include "bit_converter/bit_converter.hpp"
#include <catch2/catch.hpp>

using std::vector;

TEST_CASE("test u16 to bytes", "[u16]") {
  SECTION("value < 256") {
    REQUIRE(bit_converter::u16_to_bytes(214, true) == vector<uint8_t>{0, 214});
    REQUIRE(bit_converter::u16_to_bytes(214, false) == vector<uint8_t>{214, 0});
    REQUIRE(bit_converter::u16_to_bytes(255, true) == vector<uint8_t>{0, 255});
    REQUIRE(bit_converter::u16_to_bytes(255, false) == vector<uint8_t>{255, 0});
  }
  SECTION("value >= 256") {
    REQUIRE(bit_converter::u16_to_bytes(256, true) == vector<uint8_t>{1, 0});
    REQUIRE(bit_converter::u16_to_bytes(256, false) == vector<uint8_t>{0, 1});
    REQUIRE(bit_converter::u16_to_bytes(65535, true) ==
            vector<uint8_t>{255, 255});
    REQUIRE(bit_converter::u16_to_bytes(65535, false) ==
            vector<uint8_t>{255, 255});
  }
}