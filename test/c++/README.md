Catch2
===
Assuming you have the foo function in sample.cpp and want to test it, you should create test-sample.cpp and include sample.cpp, and don't forgot that define `#define CATCH\_CONFIX\_MAIN`.

Since Catch2 is a large file and is not often changed, we should pre-compile it to save time.

Sample
===

#### Source file
```
// sample.cpp
bool isEqual(int a, int b) {
   return a == b;
}

// test_sample.cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "sample.cpp"
TEST_CASE("just sample", "[sample]") {
    REQUIRE(isEqual(1, 0) == false);
}
```

#### Compile with g++-7
`g++-7 test_sample.cpp`

