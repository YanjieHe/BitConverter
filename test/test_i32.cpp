#include "bit_converter/bit_converter.hpp"
#include <catch2/catch.hpp>

using std::vector;

TEST_CASE("test i32 to bytes", "[i32]") {
  SECTION("large positive integers") {
    REQUIRE(bit_converter::i32_to_bytes(214748364, true) ==
            vector<uint8_t>{12, 204, 204, 204});
    REQUIRE(bit_converter::i32_to_bytes(214748364, false) ==
            vector<uint8_t>{204, 204, 204, 12});
  }
  SECTION("small negative integers") {
    REQUIRE(bit_converter::i32_to_bytes(-238609294, true) ==
            vector<uint8_t>{241, 199, 28, 114});
    REQUIRE(bit_converter::i32_to_bytes(-238609294, false) ==
            vector<uint8_t>{114, 28, 199, 241});
  }
}
