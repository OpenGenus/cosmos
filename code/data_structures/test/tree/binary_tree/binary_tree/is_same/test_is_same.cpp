#define CATCH_CONFIG_MAIN
#ifndef TEST_TREE_COMPARER
#define TEST_TREE_COMPARER

#include <memory>
#include <functional>
#include <utility>
#include "../../../../../../../test/c++/catch.hpp"
#include "../../../../../src/tree/binary_tree/binary_tree/is_same/is_same.cpp"
#include "../../../../../src/tree/binary_tree/binary_tree/serializer/serializer.cpp"
#include "../../../../../src/tree/binary_tree/binary_tree/node/node.cpp"

TEST_CASE("check two tree is same", "[isSameTree]") {
    TreeSerializer serializer;
    std::shared_ptr<TreeNode<int>> root_a, root_b;
    TreeComparer<int> comparer;

    SECTION("has empty tree") {
        root_a = serializer.deserialize("# ");
        root_b = serializer.deserialize("# ");
        REQUIRE(comparer.isSameTree(root_a, root_b));

        root_a = serializer.deserialize("1 # # ");
        root_b = serializer.deserialize("1 # # ");
        REQUIRE(comparer.isSameTree(root_a, root_b));

        root_a = serializer.deserialize("# ");
        root_b = serializer.deserialize("1 # # ");
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));
        std::swap(root_a, root_b);
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));
    }

    SECTION("has same value") {
        root_a = serializer.deserialize("1 # # ");
        root_b = serializer.deserialize("1 # # ");
        REQUIRE(comparer.isSameTree(root_a, root_b));
        std::swap(root_a, root_b);
        REQUIRE(comparer.isSameTree(root_a, root_b));

        root_a = serializer.deserialize("1 # 2 # # ");
        root_b = serializer.deserialize("1 # 2 # # ");
        REQUIRE(comparer.isSameTree(root_a, root_b));
        std::swap(root_a, root_b);
        REQUIRE(comparer.isSameTree(root_a, root_b));

        root_a = serializer.deserialize("1 2 3 4 # # 5 # # # #");
        root_b = serializer.deserialize("1 2 3 4 # # 5 # # # #");
        REQUIRE(comparer.isSameTree(root_a, root_b));
        std::swap(root_a, root_b);
        REQUIRE(comparer.isSameTree(root_a, root_b));
    }

    SECTION("has not same value") {
        root_a = serializer.deserialize("# ");
        root_b = serializer.deserialize("1 # # ");
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));
        std::swap(root_a, root_b);
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));

        root_a = serializer.deserialize("1 # # ");
        root_b = serializer.deserialize("2 # # ");
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));
        std::swap(root_a, root_b);
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));

        root_a = serializer.deserialize("1 # 2 # # ");
        root_b = serializer.deserialize("1 # 3 # # ");
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));
        std::swap(root_a, root_b);
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));

        root_a = serializer.deserialize("1 2 # # # ");
        root_b = serializer.deserialize("1 3 # # # ");
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));
        std::swap(root_a, root_b);
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));

        root_a = serializer.deserialize("1 2 3 4 # # 5 # # # #");
        root_b = serializer.deserialize("1 2 3 4 # # 6 # # # #");
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));
        std::swap(root_a, root_b);
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));
    }

    SECTION("has reflex node") {
        root_a = serializer.deserialize("1 2 # # 3 # # ");
        root_b = serializer.deserialize("1 3 # # 2 # #");
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));
        std::swap(root_a, root_b);
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));

        root_a = serializer.deserialize("1 2 # 3 # # 4 # # ");
        root_b = serializer.deserialize("1 4 # # 2 3 # # # ");
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));
        std::swap(root_a, root_b);
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));

        root_a = serializer.deserialize("1 2 3 # # # 4 # # ");
        root_b = serializer.deserialize("1 4 # # 2 # 3 # # ");
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));
        std::swap(root_a, root_b);
        REQUIRE_FALSE(comparer.isSameTree(root_a, root_b));
    }
}

#endif // TEST_TREE_COMPARER
