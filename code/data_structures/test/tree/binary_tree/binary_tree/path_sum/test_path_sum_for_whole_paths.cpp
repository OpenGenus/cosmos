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

bool isSame(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    if (a.size() != b.size())
        return false;
    for (size_t i = 0; i < a.size(); ++i)
    {
        if (a.at(i).size() != b.at(i).size())
            return false;
        for (size_t j = 0; j < a.at(i).size(); ++j)
            if (a.at(i).at(j) != b.at(i).at(j))
                return false;
    }
    return true;
}

TEST_CASE("paths between root to leaf") {
    PathSum<int> sol;
    std::vector<std::vector<int>> (PathSum<int>::* pf)(PNode, int) = &PathSum<int>::getPathsOfSum;

    TreeSerializer ts;
    PNode root = nullptr;
    auto res = (sol.*pf)(root, 0);
    std::vector<std::vector<int>> expect{};

    SECTION("give empty tree") {
        root = ts.deserialize("# ");
        res = (sol.*pf)(root, 0);
        expect = {};
        CHECK(isSame(res, expect));
    }

    SECTION("give one node") {
        root = ts.deserialize("1 # # ");
        res = (sol.*pf)(root, 0);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 1);
        expect = {{1}};
        CHECK(isSame(res, expect));
    }

    SECTION("user define") {
        root = ts.deserialize("5 4 11 7 # # 2 # # # 8 13 # # 4 5 # # 1 # # ");
        res = (sol.*pf)(root, 22);
        expect = {{5, 4, 11, 2}, {5, 8, 4, 5}};
        CHECK(isSame(res, expect));
    }

    SECTION("give balance tree") {
        root = ts.deserialize("1 2 # # 3 # # ");
        res = (sol.*pf)(root, 1);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 2);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 3);
        expect = {{1, 2}};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 4);
        expect = {{1, 3}};
        CHECK(isSame(res, expect));

        root = ts.deserialize("1 2 4 # # # 3 5 # # # ");
        res = (sol.*pf)(root, 7);
        expect = {{1, 2, 4}};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 9);
        expect = {{1, 3, 5}};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 1);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 2);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 3);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 4);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 5);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 6);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 8);
        expect = {};
        CHECK(isSame(res, expect));

        root = ts.deserialize("1 2 4 # # # 3 # 5 # # ");
        res = (sol.*pf)(root, 7);
        expect = {{1, 2, 4}};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 9);
        expect = {{1, 3, 5}};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 1);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 2);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 3);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 4);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 5);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 6);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 8);
        expect = {};
        CHECK(isSame(res, expect));

        root = ts.deserialize("1 2 # 4 # # 3 5 # # # ");
        res = (sol.*pf)(root, 7);
        expect = {{1, 2, 4}};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 9);
        expect = {{1, 3, 5}};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 1);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 2);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 3);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 4);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 5);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 6);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 8);
        expect = {};
        CHECK(isSame(res, expect));

        root = ts.deserialize("1 2 # 4 # # 3 # 5 # # ");
        res = (sol.*pf)(root, 7);
        expect = {{1, 2, 4}};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 9);
        expect = {{1, 3, 5}};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 1);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 2);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 3);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 4);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 5);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 6);
        expect = {};
        CHECK(isSame(res, expect));
        res = (sol.*pf)(root, 8);
        expect = {};
        CHECK(isSame(res, expect));
    }

    SECTION("give unbalance tree") {
        SECTION("left is more deep") {
            root = ts.deserialize("1 2 # # # ");
            res = (sol.*pf)(root, 1);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 2);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 3);
            expect = {{1, 2}};
            CHECK(isSame(res, expect));

            root = ts.deserialize("1 2 3 # # # # ");
            res = (sol.*pf)(root, 1);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 2);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 3);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 5);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 6);
            expect = {{1, 2, 3}};
            CHECK(isSame(res, expect));

            root = ts.deserialize("1 2 # 3 # # # ");
            res = (sol.*pf)(root, 1);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 2);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 3);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 5);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 6);
            expect = {{1, 2, 3}};
            CHECK(isSame(res, expect));

            root = ts.deserialize("1 2 4 # # # 3 # # ");
            res = (sol.*pf)(root, 4);
            expect = {{1, 3}};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 7);
            expect = {{1, 2, 4}};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 1);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 2);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 3);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 5);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 6);
            expect = {};
            CHECK(isSame(res, expect));

            root = ts.deserialize("1 2 # 4 # # 3 # # ");
            res = (sol.*pf)(root, 4);
            expect = {{1, 3}};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 7);
            expect = {{1, 2, 4}};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 1);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 2);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 3);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 5);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 6);
            expect = {};
            CHECK(isSame(res, expect));
        }

        SECTION("right is more deep") {
            root = ts.deserialize("1 # 2 # # ");
            res = (sol.*pf)(root, 1);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 2);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 3);
            expect = {{1, 2}};
            CHECK(isSame(res, expect));

            root = ts.deserialize("1 # 2 3 # # # ");
            res = (sol.*pf)(root, 1);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 2);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 3);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 5);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 6);
            expect = {{1, 2, 3}};
            CHECK(isSame(res, expect));

            root = ts.deserialize("1 # 2 # 3 # # ");
            res = (sol.*pf)(root, 1);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 2);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 3);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 5);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 6);
            expect = {{1, 2, 3}};
            CHECK(isSame(res, expect));

            root = ts.deserialize("1 2 # # 3 4 # # # ");
            res = (sol.*pf)(root, 3);
            expect = {{1, 2}};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 8);
            expect = {{1, 3, 4}};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 1);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 2);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 4);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 5);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 7);
            expect = {};
            CHECK(isSame(res, expect));

            root = ts.deserialize("1 2 # # 3 # 4 # # ");
            res = (sol.*pf)(root, 3);
            expect = {{1, 2}};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 8);
            expect = {{1, 3, 4}};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 1);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 2);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 4);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 5);
            expect = {};
            CHECK(isSame(res, expect));
            res = (sol.*pf)(root, 7);
            expect = {};
            CHECK(isSame(res, expect));
        }
    }
}
