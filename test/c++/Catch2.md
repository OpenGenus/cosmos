Catch2
===
Assume you have the foo function in sample.cpp and want to test it, then you shold create test-sample.cpp and include sample.cpp, but DON'T re-define CATCH\_CONFIX\_MAIN, just compile your sample file and link it (you could use build.sh):

The param can be multiple files
```
sh build.sh sample.sh
```

The test files may be like:
```
// sample.cpp
bool isEqual(int a, int b) {
   return a == b;
}

// test-sample.cpp
#include "catch.hpp"
#include "sample.cpp"

TEST_CASE("just sample", "[sample]") {
    REQUIRE(isEqual(1, 0) == false);
}

// test-main.cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
```
