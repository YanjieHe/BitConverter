#include "bit_converter/bit_converter.hpp"
#include <catch2/catch.hpp>

using std::vector;

TEST_CASE("test i64 to bytes", "[i64]") {
  auto get_bytes = [](int64_t value, bool is_big_endian) -> vector<uint8_t> {
    vector<uint8_t> bytes(sizeof(int64_t));
    bit_converter::i64_to_bytes(value, is_big_endian, bytes.begin());
    return bytes;
  };
  SECTION("large positive integers") {
    REQUIRE(get_bytes(512409557603043100, true) ==
            vector<uint8_t>{7, 28, 113, 199, 28, 113, 199, 28});
    REQUIRE(get_bytes(512409557603043100, false) ==
            vector<uint8_t>{28, 199, 113, 28, 199, 113, 28, 7});
  }
  SECTION("small negative integers") {
    REQUIRE(get_bytes(-658812288346769700, true) ==
            vector<uint8_t>{246, 219, 109, 182, 219, 109, 182, 220});
    REQUIRE(get_bytes(-658812288346769700, false) ==
            vector<uint8_t>{220, 182, 109, 219, 182, 109, 219, 246});
  }
}

TEST_CASE("test bytes to i64", "[i64]") {
  auto to_i64 = [](const vector<uint8_t> &bytes,
                   bool is_big_endian) -> int64_t {
    return bit_converter::bytes_to_i64(bytes.begin(), is_big_endian);
  };
  SECTION("large positive integers") {
    REQUIRE(to_i64(vector<uint8_t>{7, 28, 113, 199, 28, 113, 199, 28}, true) ==
            512409557603043100);
    REQUIRE(to_i64(vector<uint8_t>{28, 199, 113, 28, 199, 113, 28, 7}, false) ==
            512409557603043100);
  }
  SECTION("small negative integers") {
    REQUIRE(to_i64(vector<uint8_t>{246, 219, 109, 182, 219, 109, 182, 220},
                   true) == -658812288346769700);
    REQUIRE(to_i64(vector<uint8_t>{220, 182, 109, 219, 182, 109, 219, 246},
                   false) == -658812288346769700);
  }
}
