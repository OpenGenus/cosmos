/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * tree serializer synopsis
 *
 * class TreeSerializer
 * {
 * public:
 *  using NodeType = TreeNode<int>;
 *  using PNodeType = std::shared_ptr<NodeType>;
 *
 *  // Encodes a tree to a single string.
 *  std::string serialize(PNodeType root);
 *
 *  // Decodes your encoded data to tree.
 *  PNodeType deserialize(std::string data);
 *
 * private:
 *  std::vector<std::string> splitToVector(std::string s);
 * };
 */

#ifndef TREE_SERIALIZER
#define TREE_SERIALIZER

#include <vector>
#include <stack>
#include <queue>
#include <iterator>
#include <memory>
#include <string>
#include <sstream>
#include "../node/node.cpp"

class TreeSerializer
{
public:
    using NodeType = TreeNode<int>;
    using PNodeType = std::shared_ptr<NodeType>;

// Encodes a tree to a single string.
    std::string serialize(PNodeType root)
    {
        if (root)
        {
            std::string ret {};
            std::stack<PNodeType> st {};
            PNodeType old {};

            st.push(root);
            ret.append(std::to_string(root->value()) + " ");

            while (!st.empty())
            {
                while (st.top() && st.top()->left())
                {
                    st.push(st.top()->left());
                    ret.append(std::to_string(st.top()->value()) + " ");
                }
                if (!st.top()->left())
                    ret.append("# ");
                while (!st.empty())
                {
                    old = st.top();
                    st.pop();
                    if (old->right())
                    {
                        st.push(old->right());
                        if (st.top())
                            ret.append(std::to_string(st.top()->value()) + " ");
                        break;
                    }
                    else
                        ret.append("# ");
                }
            }

            return ret;
        }
        else
            return "# ";
    }

// Decodes your encoded data to tree.
    PNodeType deserialize(std::string data)
    {
        if (data.at(0) == '#')
            return nullptr;

        auto nodes = splitToVector(data);
        std::stack<PNodeType> st{};
        PNodeType ret = std::make_shared<NodeType>(stoi(nodes.at(0))), old{};
        st.push(ret);
        size_t i{}, sz {nodes.size()};
        i++;
        bool check_l{true};
        while (!st.empty())
        {
            while (i < sz && nodes.at(i) != "#" && check_l)
            {
                st.top()->left(std::make_shared<NodeType>(stoi(nodes.at(i++))));
                st.push(st.top()->left());
            }
            st.top()->left(nullptr);
            i++;
            check_l = false;
            while (!st.empty())
            {
                old = st.top();
                st.pop();
                check_l = true;
                if (nodes.at(i) != "#")
                {
                    old->right(std::make_shared<NodeType>(stoi(nodes.at(i++))));
                    st.push(old->right());
                    break;
                }
                else
                {
                    old->right(nullptr);
                    i++;
                }
            }
        }

        return ret;
    }

private:
    std::vector<std::string> splitToVector(std::string s)
    {
        std::stringstream ss(s);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> vstrings(begin, end);

        return vstrings;
    }
};

#endif // TREE_SERIALIZER
