#define CATCH_CONFIG_MAIN
#include "../../../../../../../test/c++/catch.hpp"
#include <vector>
#include <memory>
#include <queue>
#include "../../../../../src/tree/binary_tree/binary_tree/node/node.cpp"
#include "../../../../../src/tree/binary_tree/binary_tree/serializer/serializer.cpp"
#include "../../../../../src/tree/binary_tree/binary_tree/path_sum/path_sum.hpp"

using Node = TreeNode<int>;
using PNode = std::shared_ptr<Node>;

TEST_CASE("sum of paths between any node") {
    PathSum<int> sol(PathSum<int>::PathType::Part);
    size_t (PathSum<int>::* pf)(PNode, int) = &PathSum<int>::countPathsOfSum;

    TreeSerializer ts;
    PNode root = nullptr;
    auto res = (sol.*pf)(root, 0);

    SECTION("give empty tree") {
        root = ts.deserialize("# ");
        res = (sol.*pf)(root, 0);
        CHECK(res == 0);
    }

    SECTION("give one node") {
        root = ts.deserialize("1 # # ");
        res = (sol.*pf)(root, 1);
        CHECK(res == 1);
    }

    SECTION("give balance tree") {
        root = ts.deserialize("0 1 # # 1 # # ");
        res = (sol.*pf)(root, 0);
        CHECK(res == 1);
        res = (sol.*pf)(root, 1);
        CHECK(res == 4);

        root = ts.deserialize("1 2 # # 3 # # ");
        res = (sol.*pf)(root, 1);
        CHECK(res == 1);
        res = (sol.*pf)(root, 2);
        CHECK(res == 1);
        res = (sol.*pf)(root, 3);
        CHECK(res == 2);
        res = (sol.*pf)(root, 4);
        CHECK(res == 1);

        root = ts.deserialize("0 1 1 # # # 1 1 # # # ");
        res = (sol.*pf)(root, 0);
        CHECK(res == 1);
        res = (sol.*pf)(root, 1);
        CHECK(res == 6);
        res = (sol.*pf)(root, 2);
        CHECK(res == 4);

        root = ts.deserialize("0 1 # 1 # # 1 # 1 # # ");
        res = (sol.*pf)(root, 0);
        CHECK(res == 1);
        res = (sol.*pf)(root, 1);
        CHECK(res == 6);
        res = (sol.*pf)(root, 2);
        CHECK(res == 4);

        root = ts.deserialize("1 2 4 # # # 3 5 # # # ");
        res = (sol.*pf)(root, 1);
        CHECK(res == 1);
        res = (sol.*pf)(root, 2);
        CHECK(res == 1);
        res = (sol.*pf)(root, 3);
        CHECK(res == 2);
        res = (sol.*pf)(root, 4);
        CHECK(res == 2);
        res = (sol.*pf)(root, 5);
        CHECK(res == 1);
        res = (sol.*pf)(root, 6);
        CHECK(res == 1);
        res = (sol.*pf)(root, 7);
        CHECK(res == 1);
        res = (sol.*pf)(root, 8);
        CHECK(res == 1);
        res = (sol.*pf)(root, 9);
        CHECK(res == 1);

        root = ts.deserialize("1 2 4 # # # 3 # 5 # # ");
        res = (sol.*pf)(root, 1);
        CHECK(res == 1);
        res = (sol.*pf)(root, 2);
        CHECK(res == 1);
        res = (sol.*pf)(root, 3);
        CHECK(res == 2);
        res = (sol.*pf)(root, 4);
        CHECK(res == 2);
        res = (sol.*pf)(root, 5);
        CHECK(res == 1);
        res = (sol.*pf)(root, 6);
        CHECK(res == 1);
        res = (sol.*pf)(root, 7);
        CHECK(res == 1);
        res = (sol.*pf)(root, 8);
        CHECK(res == 1);
        res = (sol.*pf)(root, 9);
        CHECK(res == 1);

        root = ts.deserialize("1 2 # 4 # # 3 5 # # # ");
        res = (sol.*pf)(root, 1);
        CHECK(res == 1);
        res = (sol.*pf)(root, 2);
        CHECK(res == 1);
        res = (sol.*pf)(root, 3);
        CHECK(res == 2);
        res = (sol.*pf)(root, 4);
        CHECK(res == 2);
        res = (sol.*pf)(root, 5);
        CHECK(res == 1);
        res = (sol.*pf)(root, 6);
        CHECK(res == 1);
        res = (sol.*pf)(root, 7);
        CHECK(res == 1);
        res = (sol.*pf)(root, 8);
        CHECK(res == 1);
        res = (sol.*pf)(root, 9);
        CHECK(res == 1);

        root = ts.deserialize("1 2 # 4 # # 3 # 5 # # ");
        res = (sol.*pf)(root, 1);
        CHECK(res == 1);
        res = (sol.*pf)(root, 2);
        CHECK(res == 1);
        res = (sol.*pf)(root, 3);
        CHECK(res == 2);
        res = (sol.*pf)(root, 4);
        CHECK(res == 2);
        res = (sol.*pf)(root, 5);
        CHECK(res == 1);
        res = (sol.*pf)(root, 6);
        CHECK(res == 1);
        res = (sol.*pf)(root, 7);
        CHECK(res == 1);
        res = (sol.*pf)(root, 8);
        CHECK(res == 1);
        res = (sol.*pf)(root, 9);
        CHECK(res == 1);
    }

    SECTION("give unbalance tree") {
        SECTION("left is more deep") {
            root = ts.deserialize("1 2 # # # ");
            res = (sol.*pf)(root, 1);
            CHECK(res == 1);
            res = (sol.*pf)(root, 2);
            CHECK(res == 1);
            res = (sol.*pf)(root, 3);
            CHECK(res == 1);

            root = ts.deserialize("1 2 3 # # # # ");
            res = (sol.*pf)(root, 1);
            CHECK(res == 1);
            res = (sol.*pf)(root, 2);
            CHECK(res == 1);
            res = (sol.*pf)(root, 3);
            CHECK(res == 2);
            res = (sol.*pf)(root, 5);
            CHECK(res == 1);

            root = ts.deserialize("1 2 # 3 # # # ");
            res = (sol.*pf)(root, 1);
            CHECK(res == 1);
            res = (sol.*pf)(root, 2);
            CHECK(res == 1);
            res = (sol.*pf)(root, 3);
            CHECK(res == 2);
            res = (sol.*pf)(root, 5);
            CHECK(res == 1);

            root = ts.deserialize("1 1 1 # # # 1 # # ");
            res = (sol.*pf)(root, 1);
            CHECK(res == 4);
            res = (sol.*pf)(root, 2);
            CHECK(res == 3);
            res = (sol.*pf)(root, 3);
            CHECK(res == 1);

            root = ts.deserialize("1 1 # 1 # # 1 # # ");
            res = (sol.*pf)(root, 1);
            CHECK(res == 4);
            res = (sol.*pf)(root, 2);
            CHECK(res == 3);
            res = (sol.*pf)(root, 3);
            CHECK(res == 1);

            root = ts.deserialize("1 2 4 # # # 3 # # ");
            res = (sol.*pf)(root, 1);
            CHECK(res == 1);
            res = (sol.*pf)(root, 2);
            CHECK(res == 1);
            res = (sol.*pf)(root, 3);
            CHECK(res == 2);
            res = (sol.*pf)(root, 4);
            CHECK(res == 2);
            res = (sol.*pf)(root, 6);
            CHECK(res == 1);

            root = ts.deserialize("1 2 # 4 # # 3 # # ");
            res = (sol.*pf)(root, 1);
            CHECK(res == 1);
            res = (sol.*pf)(root, 2);
            CHECK(res == 1);
            res = (sol.*pf)(root, 3);
            CHECK(res == 2);
            res = (sol.*pf)(root, 4);
            CHECK(res == 2);
            res = (sol.*pf)(root, 6);
            CHECK(res == 1);
        }

        SECTION("right is more deep") {
            root = ts.deserialize("1 # 2 # # ");
            res = (sol.*pf)(root, 1);
            CHECK(res == 1);
            res = (sol.*pf)(root, 2);
            CHECK(res == 1);
            res = (sol.*pf)(root, 3);
            CHECK(res == 1);

            root = ts.deserialize("1 # 2 3 # # # ");
            res = (sol.*pf)(root, 1);
            CHECK(res == 1);
            res = (sol.*pf)(root, 2);
            CHECK(res == 1);
            res = (sol.*pf)(root, 3);
            CHECK(res == 2);
            res = (sol.*pf)(root, 5);
            CHECK(res == 1);

            root = ts.deserialize("1 # 2 # 3 # # ");
            res = (sol.*pf)(root, 1);
            CHECK(res == 1);
            res = (sol.*pf)(root, 2);
            CHECK(res == 1);
            res = (sol.*pf)(root, 3);
            CHECK(res == 2);
            res = (sol.*pf)(root, 5);
            CHECK(res == 1);

            root = ts.deserialize("1 1 # # 1 1 # # # ");
            res = (sol.*pf)(root, 1);
            CHECK(res == 4);
            res = (sol.*pf)(root, 2);
            CHECK(res == 3);
            res = (sol.*pf)(root, 3);
            CHECK(res == 1);

            root = ts.deserialize("1 1 # # 1 # 1 # # ");
            res = (sol.*pf)(root, 1);
            CHECK(res == 4);
            res = (sol.*pf)(root, 2);
            CHECK(res == 3);
            res = (sol.*pf)(root, 3);
            CHECK(res == 1);

            root = ts.deserialize("1 2 # # 3 4 # # # ");
            res = (sol.*pf)(root, 1);
            CHECK(res == 1);
            res = (sol.*pf)(root, 2);
            CHECK(res == 1);
            res = (sol.*pf)(root, 3);
            CHECK(res == 2);
            res = (sol.*pf)(root, 4);
            CHECK(res == 2);
            res = (sol.*pf)(root, 7);
            CHECK(res == 1);

            root = ts.deserialize("1 2 # # 3 # 4 # # ");
            res = (sol.*pf)(root, 1);
            CHECK(res == 1);
            res = (sol.*pf)(root, 2);
            CHECK(res == 1);
            res = (sol.*pf)(root, 3);
            CHECK(res == 2);
            res = (sol.*pf)(root, 4);
            CHECK(res == 2);
            res = (sol.*pf)(root, 7);
            CHECK(res == 1);
        }
    }
}
