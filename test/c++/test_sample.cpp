#include "catch.hpp"
#include "sample.cpp"

TEST_CASE("just sample", "[sample]") {
    REQUIRE(isEqual(1, 0) == false);
}
