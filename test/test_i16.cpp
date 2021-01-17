#include "bit_converter/bit_converter.hpp"
#include <catch2/catch.hpp>

using std::vector;

TEST_CASE("test i16 to bytes", "[i16]") {
  SECTION("value < 256") {
    REQUIRE(bit_converter::i16_to_bytes(-4334, true) ==
            vector<uint8_t>{239, 18});
    REQUIRE(bit_converter::i16_to_bytes(-4334, false) ==
            vector<uint8_t>{18, 239});
  }
  SECTION("value >= 256") {
    REQUIRE(bit_converter::i16_to_bytes(30000, true) ==
            vector<uint8_t>{117, 48});
    REQUIRE(bit_converter::i16_to_bytes(30000, false) ==
            vector<uint8_t>{48, 117});
  }
}
