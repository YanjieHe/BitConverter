#include "bit_converter/bit_converter.hpp"
#include <catch2/catch.hpp>

using std::vector;

TEST_CASE("test i64 to bytes", "[i64]") {
  SECTION("large positive integers") {
    REQUIRE(bit_converter::i64_to_bytes(512409557603043100, true) ==
            vector<uint8_t>{7, 28, 113, 199, 28, 113, 199, 28});
    REQUIRE(bit_converter::i64_to_bytes(512409557603043100, false) ==
            vector<uint8_t>{28, 199, 113, 28, 199, 113, 28, 7});
  }
  SECTION("small negative integers") {
    REQUIRE(bit_converter::i64_to_bytes(-658812288346769700, true) ==
            vector<uint8_t>{246, 219, 109, 182, 219, 109, 182, 220});
    REQUIRE(bit_converter::i64_to_bytes(-658812288346769700, false) ==
            vector<uint8_t>{220, 182, 109, 219, 182, 109, 219, 246});
  }
}
