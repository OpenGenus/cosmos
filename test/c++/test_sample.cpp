#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// this function should be stored in code folder
bool isEqual(int a, int b) {
   return a == b;
}

TEST_CASE("just sample", "[sample]") {
    REQUIRE(isEqual(1, 0) == false);
}
