#include <iostream>
#include "Tree.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Pass Tests")
{
    REQUIRE(1 == 1);
}

TEST_CASE("Fail test")
{
    REQUIRE(1 == 0);
}
