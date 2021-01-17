#include "bit_converter/bit_converter.hpp"
#include <catch2/catch.hpp>

using std::vector;

TEST_CASE("test f32 to bytes", "[f32]") {
  SECTION("floating-point numbers") {
    REQUIRE(bit_converter::f32_to_bytes(3.14, false) ==
            vector<uint8_t>{195, 245, 72, 64});
  }
}
