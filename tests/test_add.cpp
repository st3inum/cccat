#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "myheader.hpp"

TEST_CASE("Add function works correctly", "[add]") {
    REQUIRE(add(1, 1) == 2);
    REQUIRE(add(-1, -1) == -2);
    REQUIRE(add(0, 0) == 0);
    REQUIRE(add(-1, 1) == 0);
}
