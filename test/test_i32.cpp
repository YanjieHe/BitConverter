#include "bit_converter/bit_converter.hpp"
#include <catch2/catch.hpp>

using std::vector;

TEST_CASE("test i32 to bytes", "[i32]") {
  auto get_bytes = [](int32_t value, bool is_big_endian) -> vector<uint8_t> {
    vector<uint8_t> bytes(sizeof(int32_t));
    bit_converter::i32_to_bytes(value, is_big_endian, bytes.begin());
    return bytes;
  };
  SECTION("large positive integers") {
    REQUIRE(get_bytes(214748364, true) == vector<uint8_t>{12, 204, 204, 204});
    REQUIRE(get_bytes(214748364, false) == vector<uint8_t>{204, 204, 204, 12});
  }
  SECTION("small negative integers") {
    REQUIRE(get_bytes(-238609294, true) == vector<uint8_t>{241, 199, 28, 114});
    REQUIRE(get_bytes(-238609294, false) == vector<uint8_t>{114, 28, 199, 241});
  }
}
