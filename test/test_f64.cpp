#include "bit_converter/bit_converter.hpp"
#include <catch2/catch.hpp>

using std::vector;

TEST_CASE("test f64 to bytes", "[f64]") {
  SECTION("floating-point numbers") {
    REQUIRE(bit_converter::f64_to_bytes(3.14, false) ==
            vector<uint8_t>{31, 133, 235, 81, 184, 30, 9, 64});
  }
}
