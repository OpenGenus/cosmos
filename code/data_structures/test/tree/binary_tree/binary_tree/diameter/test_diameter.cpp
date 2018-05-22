#define CATCH_CONFIG_MAIN
#include "../../../../../../../test/c++/catch.hpp"
#include "../../../../../src/tree/binary_tree/binary_tree/serializer/serializer.cpp"
#include "../../../../../src/tree/binary_tree/binary_tree/node/node.cpp"
#include "../../../../../src/tree/binary_tree/binary_tree/diameter/diameter.cpp"
#include <string>

TEST_CASE("diameter of binary tree")
{
    TreeSerializer ts;
    std::string str;

    SECTION("empty tree")
    {
        str = "#";
        CHECK(diameter<std::shared_ptr<TreeNode<int>>>(ts.deserialize(str)) == 0);
    }

    SECTION("one-node tree")
    {
        str = "1 # #";
        CHECK(diameter<std::shared_ptr<TreeNode<int>>>(ts.deserialize(str)) == 1);
    }

    SECTION("non-empty tree")
    {
        /*
         *       1
         *      / \
         *     2   2
         *    / \
         *   3   3
         *  /     \
         * 4       4
         * /
         * 5
         */
        str = "1 2 3 4 5 # # # # 3 # 4 # # 2 # #";
        CHECK(diameter<std::shared_ptr<TreeNode<int>>>(ts.deserialize(str)) == 6);

        /*
         *       1
         *      / \
         *     2   2
         *    / \
         *   3   3
         *  /     \
         * 4       4
         * /         \
         * 5           5
         */
        str = "1 2 3 4 5 # # # # 3 # 4 # 5 # # 2 # #";
        CHECK(diameter<std::shared_ptr<TreeNode<int>>>(ts.deserialize(str)) == 7);

        /*
         *            1
         *       /         \
         *     2            2
         *    / \          /
         *   3   3        3
         *  /    /\      /
         * 4    4  4    4
         * /            /
         * 5            5
         */
        str = "1 2 3 4 5 # # # # 3 4 # # 4 # # 2 3 4 5 # # # # #";
        CHECK(diameter<std::shared_ptr<TreeNode<int>>>(ts.deserialize(str)) == 9);
    }
}
