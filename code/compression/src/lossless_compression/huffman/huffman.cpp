/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * huffman compression synopsis
 *
 * template<typename _Tp>
 * struct BinaryTreeNode {
 *  _Tp value;
 *  std::shared_ptr<BinaryTreeNode<_Tp> > left, right;
 *  BinaryTreeNode(_Tp v,
 *                 std::shared_ptr<BinaryTreeNode<_Tp> > l = {},
 *                 std::shared_ptr<BinaryTreeNode<_Tp> > r = {});
 * };
 *
 * template<typename _Tp>
 * struct Comp {
 * public:
 *  bool operator()(_Tp a, _Tp b) const;
 * };
 *
 * class HuffmanTest;
 *
 * class Huffman {
 * private:
 *  typedef size_t                                                       size_type;
 *  typedef unsigned long long                                           base_type;
 *  typedef std::pair<char, size_type>                                   freq_node_type;
 *  typedef std::unordered_map<char, size_type>                          freq_type;
 *  typedef std::pair<size_type, std::pair<char, std::string> >          value_type;
 *  typedef BinaryTreeNode<value_type>                                   tree_node_type;
 *  typedef std::priority_queue<std::shared_ptr<tree_node_type>,
 *                              std::vector<std::shared_ptr<tree_node_type> >,
 *                              Comp<std::shared_ptr<tree_node_type> > > tree_type;
 *  typedef std::unordered_map<char, std::string>                        dictionary_type;
 *  typedef std::unordered_map<std::string, char>                        reverse_dictionary_type;
 *
 * public:
 *  Huffman()
 *      :frequency_(), tree_(), dictionary_(), reverse_dictionary_(), sentinel_(), binary_bit_();
 *
 *  std::string compression(std::string const &in);
 *
 *  std::string compression(std::istream &in);
 *
 *  void compression(std::string const &in, std::ostream &out);
 *
 *  void compression(std::istream &in, std::ostream &out);
 *
 *  std::string decompression(std::string const &in);
 *
 *  std::string decompression(std::istream &in);
 *
 *  void decompression(std::string const &in, std::ostream &out);
 *
 *  void decompression(std::istream &in, std::ostream &out);
 *
 * private:
 *  freq_type frequency_;
 *  tree_type tree_;
 *  dictionary_type dictionary_;
 *  reverse_dictionary_type reverse_dictionary_;
 *  std::shared_ptr<tree_node_type> sentinel_;
 *  size_type binary_bit_;
 *  std::vector<size_type> power_;
 *  const char DELIMITER = ' ';
 *  const size_type GUARANTEE_BIT = sizeof(base_type) * 8;
 *  const int HEX_BIT = 16;
 *
 *  void calculateFrequency(std::string const &input);
 *
 *  // no cover test
 *  void buildForest();
 *
 *  // no cover test
 *  void initialTree();
 *
 *  // no cover test
 *  void initialForest();
 *
 *  // no cover test
 *  void appendDegree();
 *
 *  // no cover test
 *  void buildDictionary();
 *
 *  std::pair<std::string, std::string> seperateHeaderAndCode(std::string const &str);
 *
 *  // no cover test
 *  std::string restore(std::string const &input);
 *
 *  std::string exportHeader();
 *
 *  std::string exportDictionary();
 *
 *  void importHeader(std::string const &str);
 *
 *  void importDictionary(std::string const &str);
 *
 *  std::string addSeperateCode(std::string const &str);
 *
 *  std::string removeSeperateCode(std::string const &str);
 *
 *  std::string stringToHex(std::string const &str);
 *
 *  std::string stringToBinary(std::string const &input);
 *
 *  // return string always fill 0 while size is not N * GUARANTEE_BIT
 *  std::string binaryToHex(std::string const &str);
 *
 *  std::string hexToBinary(std::string const &str);
 * };
 */

#include <functional>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <memory>
#include <cmath>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <iostream>

template<typename _Tp>
struct BinaryTreeNode
{
    _Tp value;
    std::shared_ptr<BinaryTreeNode<_Tp>> left, right;
    BinaryTreeNode(_Tp v,
                   std::shared_ptr<BinaryTreeNode<_Tp>> l = {},
                   std::shared_ptr<BinaryTreeNode<_Tp>> r = {}) : value(v), left(l), right(r)
    {
    };
};

template<typename _Tp>
struct Comp
{
public:
    bool operator()(_Tp a, _Tp b) const
    {
        return a->value.first > b->value.first;
    }
};

class HuffmanTest;

class Huffman {
private:
    typedef size_t size_type;
    typedef unsigned long long base_type;
    typedef std::pair<char, size_type>                                   freq_node_type;
    typedef std::unordered_map<char, size_type>                          freq_type;
    typedef std::pair<size_type, std::pair<char, std::string>>          value_type;
    typedef BinaryTreeNode<value_type>                                   tree_node_type;
    typedef std::priority_queue<std::shared_ptr<tree_node_type>,
                                std::vector<std::shared_ptr<tree_node_type>>,
                                Comp<std::shared_ptr<tree_node_type>>> tree_type;
    typedef std::unordered_map<char, std::string>                        dictionary_type;
    typedef std::unordered_map<std::string, char>                        reverse_dictionary_type;

public:
    Huffman()
        : frequency_(), tree_(), dictionary_(), reverse_dictionary_(), sentinel_(), binary_bit_()
    {
        power_.resize(GUARANTEE_BIT);
        for (auto i = GUARANTEE_BIT; i > 0; --i)
            power_.at(i - 1) = pow(2, GUARANTEE_BIT - i);
    };

    std::string compression(std::string const &in)
    {
        calculateFrequency(in);
        buildForest();
        buildDictionary();

        // don't change order on this and next line
        // because stringToHex will calc. binary length
        std::string res = stringToHex(in);
        res = addSeperateCode(exportHeader()) + res;

        return res;
    }

    std::string compression(std::istream &in)
    {
        return compression(readFile(in));
    }

    void compression(std::string const &in, std::ostream &out)
    {
        out << compression(in);
    }

    void compression(std::istream &in, std::ostream &out)
    {
        out << compression(in);
    }

    std::string decompression(std::string const &in)
    {
        std::pair<std::string, std::string> header_and_code = seperateHeaderAndCode(in);
        importHeader(header_and_code.first);
        std::string res = hexToBinary(header_and_code.second);
        res = restore(res);

        return res;
    }

    std::string decompression(std::istream &in)
    {
        return decompression(readFile(in));
    }

    void decompression(std::string const &in, std::ostream &out)
    {
        out << decompression(in);
    }

    void decompression(std::istream &in, std::ostream &out)
    {
        out << decompression(in);
    }

private:
    freq_type frequency_;
    tree_type tree_;
    dictionary_type dictionary_;
    reverse_dictionary_type reverse_dictionary_;
    std::shared_ptr<tree_node_type> sentinel_;
    unsigned long long binary_bit_;
    std::vector<size_type> power_;
    const char DELIMITER = ' ';
    const unsigned long long GUARANTEE_BIT = sizeof(base_type) * 8;
    const unsigned long long HEX_BIT = 16;

    std::string readFile(std::istream &in)
    {
        std::string s{};
        char c;
        while (in >> std::noskipws >> c)
            s.push_back(c);

        return s;
    }

    void calculateFrequency(std::string const &input)
    {
        char c;
        std::stringstream in(input);
        while (in >> std::noskipws >> c)
        {
            if (frequency_.find(c) == frequency_.end())
                frequency_.insert(std::make_pair(c, 1));
            else
                frequency_.at(c) += 1;
        }
    }

// no cover test
    void buildForest()
    {
        initialTree();
        initialForest();
        appendDegree();
    }

// no cover test
    void initialTree()
    {
        for_each(frequency_.begin(),
                 frequency_.end(),
                 [&] (freq_node_type freq_node)
        {
            value_type n{std::make_pair(freq_node.second, std::make_pair(freq_node.first, ""))};
            tree_.push({std::make_shared<tree_node_type>(tree_node_type((n),
                                                                        sentinel_,
                                                                        sentinel_))});
        });
        if (frequency_.size() == 1)
            tree_.push({std::make_shared<tree_node_type>(tree_node_type({}))});
    }

// no cover test
    void initialForest()
    {
        while (tree_.size() > 1)
        {
            std::shared_ptr<tree_node_type> left{}, right{}, parent{};
            left = tree_.top();
            tree_.pop();
            right = tree_.top();
            tree_.pop();
            if (Comp<std::shared_ptr<tree_node_type>>()(left, right))
                swap(left, right);
            parent = std::make_shared<tree_node_type>(tree_node_type({}, left, right));
            parent->value.first = left->value.first + right->value.first;
            tree_.push(parent);
        }
    }

// no cover test
    void appendDegree()
    {
        if (!tree_.empty())
        {
            std::string degree{};
            std::stack<std::shared_ptr<tree_node_type>> nodes;
            nodes.push(tree_.top());

            // post order travel
            while (!nodes.empty())
            {
                while (nodes.top()->left)
                {
                    nodes.push(nodes.top()->left);
                    degree += '0';
                }
                while (!nodes.empty() && nodes.top()->right == sentinel_)
                {
                    if (nodes.top()->left == sentinel_)
                        nodes.top()->value.second.second = degree;
                    nodes.pop();
                    while (!degree.empty() && degree.back() == '1')
                        degree.pop_back();
                    if (!degree.empty())
                        degree.pop_back();
                }
                if (!nodes.empty())
                {
                    auto right = nodes.top()->right;
                    nodes.pop();
                    nodes.push(right);
                    degree += '1';
                }
            }
        }
    }

// no cover test
    void buildDictionary()
    {
        if (tree_.size() == 1)
        {
            std::stack<std::shared_ptr<tree_node_type>> nodes;
            nodes.push(tree_.top());
            tree_.pop();

            // post order travel
            while (!nodes.empty())
            {
                while (nodes.top()->left != sentinel_)
                    nodes.push(nodes.top()->left);

                while (!nodes.empty() && nodes.top()->right == sentinel_)
                {
                    if (nodes.top()->left == sentinel_)
                        dictionary_.insert(make_pair(nodes.top()->value.second.first,
                                                     nodes.top()->value.second.second));
                    nodes.pop();
                }
                if (!nodes.empty())
                {
                    auto right = nodes.top()->right;
                    nodes.pop();
                    nodes.push(right);
                }
            }
        }
    }

    std::pair<std::string, std::string> seperateHeaderAndCode(std::string const &str)
    {
        auto it = --str.begin();
        size_type separate_count{};
        while (++it != str.end())
            if (separate_count == 4 && it + 1 != str.end() && *(it + 1) != ' ')
                break;
            else if (*it == ' ')
                ++separate_count;
            else
                separate_count = 0;


        return std::make_pair(std::string{str.begin(), it - 4}, std::string{it, str.end()});
    }

// no cover test
    std::string restore(std::string const &input)
    {
        std::stringstream ss{input};
        std::string res{};
        char c;
        std::string k;
        while (ss >> c)
        {
            k = {};
            ss.putback(c);
            while (reverse_dictionary_.find(k) == reverse_dictionary_.end())
            {
                if (ss >> c)
                    k.push_back(c);
                else
                    break;
            }
            if (reverse_dictionary_.find(k) != reverse_dictionary_.end())
                res.push_back(reverse_dictionary_.at(k));
            else
                break;
        }

        return res;
    }

    std::string exportHeader()
    {
        return std::to_string(binary_bit_) + DELIMITER + exportDictionary();
    }

    std::string exportDictionary()
    {
        std::string res{};
        for_each(dictionary_.begin(),
                 dictionary_.end(),
                 [&] (std::pair<char, std::string> value)
        {
            res.push_back(value.first);
            res += DELIMITER;
            res.append(value.second);
            res += DELIMITER;
        });
        if (!res.empty())
            res.erase(--res.end());

        return res;
    }

    void importHeader(std::string const &str)
    {
        auto it = str.begin();
        while (it != str.end() && *it != DELIMITER)
            ++it;
        binary_bit_ = stoull(std::string{str.begin(), it});
        if (it != str.end())
            ++it;
        importDictionary({it, str.end()});
    }

    void importDictionary(std::string const &str)
    {
        char key{}, delimiter{};
        std::stringstream ss{str};
        std::string value{};
        while (ss >> std::noskipws >> key)
        {
            ss >> std::noskipws >> delimiter;
            ss >> std::noskipws >> value;
            ss >> std::noskipws >> delimiter;
            reverse_dictionary_.insert(make_pair(value, key));
        }
    }

    std::string addSeperateCode(std::string const &str)
    {
        return str + DELIMITER + DELIMITER + DELIMITER + DELIMITER;
    }

    std::string removeSeperateCode(std::string const &str)
    {
        if (str.size() >= 4)
        {
            auto it = str.end();
            if (*--it == DELIMITER
                && *--it == DELIMITER
                && *--it == DELIMITER
                && *--it == DELIMITER)
                return std::string(str.begin(), str.end() - 4);
        }

        return str;
    }

    std::string stringToHex(std::string const &str)
    {
        return binaryToHex(stringToBinary(str));
    }

    std::string stringToBinary(std::string const &input)
    {
        std::string res{};
        char c{};
        std::stringstream in(input);
        while (in >> std::noskipws >> c)
            res.append(dictionary_.at(c));
        binary_bit_ = res.size();

        return res;
    }

// return string always fill 0 while size is not N * GUARANTEE_BIT
    std::string binaryToHex(std::string const &str)
    {
        if (str.empty())
            return {};

        std::stringstream res{};
        size_type seat{};
        base_type c{};
        while (true)
        {
            if (seat < str.size())
                c |= (str.at(seat) == '1') ? 1 : 0;
            ++seat;
            if ((seat % GUARANTEE_BIT) == 0)
            {
                res << std::hex << c << DELIMITER;
                c = {};
                if (seat >= str.size())
                    break;
            }
            c <<= 1;
        }

        return res.str();
    }

    std::string hexToBinary(std::string const &str)
    {
        std::stringstream in_ss{str};
        std::string res{}, s{};
        size_type seat{}, g{};
        base_type c{};
        seat = 0 - 1;
        while (true)
        {
            if (++seat < str.size())
            {
                in_ss >> s;
                c = static_cast<base_type>(stoull(s, 0, HEX_BIT));
                g = 0 - 1;
            }
            else if (g % GUARANTEE_BIT == 0)
                break;
            while (++g < GUARANTEE_BIT)
                if (c >= power_.at(g))
                {
                    c -= power_.at(g);
                    res.push_back('1');
                }
                else
                    res.push_back('0');

        }
        res.erase(res.begin() + binary_bit_, res.end());

        return res;
    }

// for test
    friend HuffmanTest;
};
