Catch2
===
Assuming you have the foo function in sample.cpp and want to test it, you should create test-sample.cpp and include sample.cpp, but DON'T re-define CATCH\_CONFIX\_MAIN.

Since Catch2 is a large file and is not often changed, we should pre-compile it to save time.

Sample
===

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
```

Convenient tool
===
You could use build.sh to compile and link your test file :

```
// The parameters can be multiple files
sh build.sh sample.sh
```
