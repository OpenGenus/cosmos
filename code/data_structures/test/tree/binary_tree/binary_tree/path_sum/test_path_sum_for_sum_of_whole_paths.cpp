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

TEST_CASE("sum of paths between root to bottom") {
    PathSum<int> sol;
    size_t (PathSum<int>::* pf)(PNode, int) = &PathSum<int>::countPathsOfSum;

    TreeSerializer ts;
    PNode root = nullptr;
    auto res = (sol.*pf)(root, 0);

    SECTION("give empty tree") {
        root = ts.deserialize("# ");
        for (int i = -20; i < 20; ++i)
        {
            res = (sol.*pf)(root, i);
            CHECK(res == 0);
        }
    }

    SECTION("give one node") {
        root = ts.deserialize("1 # # ");
        for (int i = -20; i < 20; ++i)
        {
            res = (sol.*pf)(root, i);
            if (i == 1)
                CHECK(res == 1);
            else
                CHECK(res == 0);
        }
    }

    SECTION("give balance tree") {
        root = ts.deserialize("1 2 # # 3 # # ");
        for (int i = -20; i < 20; ++i)
        {
            res = (sol.*pf)(root, i);
            if (i == 3 || i == 4)
                CHECK(res == 1);
            else
                CHECK(res == 0);
        }

        root = ts.deserialize("1 2 4 # # # 3 5 # # # ");
        for (int i = -20; i < 20; ++i)
        {
            res = (sol.*pf)(root, i);
            if (i == 7 || i == 9)
                CHECK(res == 1);
            else
                CHECK(res == 0);
        }

        root = ts.deserialize("1 2 4 # # # 3 # 5 # # ");
        for (int i = -20; i < 20; ++i)
        {
            res = (sol.*pf)(root, i);
            if (i == 7 || i == 9)
                CHECK(res == 1);
            else
                CHECK(res == 0);
        }

        root = ts.deserialize("1 2 # 4 # # 3 5 # # # ");
        for (int i = -20; i < 20; ++i)
        {
            res = (sol.*pf)(root, i);
            if (i == 7 || i == 9)
                CHECK(res == 1);
            else
                CHECK(res == 0);
        }

        root = ts.deserialize("1 2 # 4 # # 3 # 5 # # ");
        for (int i = -20; i < 20; ++i)
        {
            res = (sol.*pf)(root, i);
            if (i == 7 || i == 9)
                CHECK(res == 1);
            else
                CHECK(res == 0);
        }
    }

    SECTION("give unbalance tree") {
        SECTION("left is more deep") {
            root = ts.deserialize("1 2 # # # ");
            for (int i = -20; i < 20; ++i)
            {
                res = (sol.*pf)(root, i);
                if (i == 3)
                    CHECK(res == 1);
                else
                    CHECK(res == 0);
            }

            root = ts.deserialize("1 2 3 # # # # ");
            for (int i = -20; i < 20; ++i)
            {
                res = (sol.*pf)(root, i);
                if (i == 6)
                    CHECK(res == 1);
                else
                    CHECK(res == 0);
            }

            root = ts.deserialize("1 2 # 3 # # # ");
            for (int i = -20; i < 20; ++i)
            {
                res = (sol.*pf)(root, i);
                if (i == 6)
                    CHECK(res == 1);
                else
                    CHECK(res == 0);
            }

            root = ts.deserialize("1 2 4 # # # 3 # # ");
            for (int i = -20; i < 20; ++i)
            {
                res = (sol.*pf)(root, i);
                if (i == 4 || i == 7)
                    CHECK(res == 1);
                else
                    CHECK(res == 0);
            }

            root = ts.deserialize("1 2 # 4 # # 3 # # ");
            for (int i = -20; i < 20; ++i)
            {
                res = (sol.*pf)(root, i);
                if (i == 4 || i == 7)
                    CHECK(res == 1);
                else
                    CHECK(res == 0);
            }
        }

        SECTION("right is more deep") {
            root = ts.deserialize("1 # 2 # # ");
            for (int i = -20; i < 20; ++i)
            {
                res = (sol.*pf)(root, i);
                if (i == 3)
                    CHECK(res == 1);
                else
                    CHECK(res == 0);
            }

            root = ts.deserialize("1 # 2 3 # # # ");
            for (int i = -20; i < 20; ++i)
            {
                res = (sol.*pf)(root, i);
                if (i == 6)
                    CHECK(res == 1);
                else
                    CHECK(res == 0);
            }

            root = ts.deserialize("1 # 2 # 3 # # ");
            for (int i = -20; i < 20; ++i)
            {
                res = (sol.*pf)(root, i);
                if (i == 6)
                    CHECK(res == 1);
                else
                    CHECK(res == 0);
            }

            root = ts.deserialize("1 2 # # 3 4 # # # ");
            for (int i = -20; i < 20; ++i)
            {
                res = (sol.*pf)(root, i);
                if (i == 3 || i == 8)
                    CHECK(res == 1);
                else
                    CHECK(res == 0);
            }

            root = ts.deserialize("1 2 # # 3 # 4 # # ");
            for (int i = -20; i < 20; ++i)
            {
                res = (sol.*pf)(root, i);
                if (i == 3 || i == 8)
                    CHECK(res == 1);
                else
                    CHECK(res == 0);
            }
        }
    }
}
