/*
 Part of Cosmos by OpenGenus Foundation

 test lists for std::list-like
 */

#ifndef XOR_LINKED_LIST_TEST_CPP
#define XOR_LINKED_LIST_TEST_CPP

#include "catch.hpp"
#include "xor_linked_list.cpp"
#include <iostream>
#include <list>
#include <vector>
using namespace std;

const size_t RandomSize = 100000 + rand() % 2;

// const size_t RandomSize = 10000;

TEST_CASE("-ctors converts and its types")
{
    srand(static_cast<unsigned int>(clock()));
    SECTION("iterator")
    {
        SECTION("begin")
        {
            std::list<int> expect;
            std::list<int>::iterator expectIt1(expect.begin());
            std::list<int>::const_iterator expectIt2(expect.begin());
            std::list<int>::reverse_iterator expectIt3(expect.begin());
            std::list<int>::const_reverse_iterator expectIt4(expect.begin());

            std::list<int>::const_iterator expectCIt2(expect.cbegin());
            std::list<int>::const_reverse_iterator expectCIt4(expect.cbegin());

            std::list<int>::reverse_iterator expectRIt3(expect.rbegin());
            std::list<int>::const_reverse_iterator expectRIt4(expect.rbegin());

            std::list<int>::const_reverse_iterator expectCRIt4(expect.crbegin());

            XorLinkedList<int> actual;
            XorLinkedList<int>::iterator actualIt1(actual.begin());
            XorLinkedList<int>::const_iterator actualIt2(actual.begin());
            XorLinkedList<int>::reverse_iterator actualIt3(actual.begin());
            XorLinkedList<int>::const_reverse_iterator actualIt4(actual.begin());

            XorLinkedList<int>::const_iterator actualCIt2(actual.cbegin());
            XorLinkedList<int>::const_reverse_iterator actualCIt4(actual.cbegin());

            XorLinkedList<int>::reverse_iterator actualRIt3(actual.rbegin());
            XorLinkedList<int>::const_reverse_iterator actualRIt4(actual.rbegin());

            XorLinkedList<int>::const_reverse_iterator actualCRIt4(actual.crbegin());
        }

        SECTION("begin errors")
        {
            std::list<int> expect;

            // std::list<int>::iterator expectCIt1(expect.cbegin());
            // std::list<int>::reverse_iterator expectCIt3(expect.cbegin());
            //
            // std::list<int>::iterator expectRIt1(expect.rbegin());
            // std::list<int>::const_iterator expectRIt2(expect.rbegin());
            //
            // std::list<int>::iterator expectCRIt1(expect.crbegin());
            // std::list<int>::const_iterator expectCRIt2(expect.crbegin());
            // std::list<int>::reverse_iterator expectCRIt3(expect.crbegin());

            XorLinkedList<int> actual;

            // XorLinkedList<int>::iterator actualCIt1(actual.cbegin());
            // XorLinkedList<int>::reverse_iterator actualCIt3(actual.cbegin());

            // XorLinkedList<int>::iterator actualRIt1(actual.rbegin());
            // XorLinkedList<int>::const_iterator actualRIt2(actual.rbegin());

            // XorLinkedList<int>::iterator actualCRIt1(actual.crbegin());
            // XorLinkedList<int>::const_iterator actualCRIt2(actual.crbegin());
            // XorLinkedList<int>::reverse_iterator actualCRIt3(actual.crbegin());
        }

        SECTION("end")
        {
            std::list<int> expect;
            std::list<int>::iterator expectIt1(expect.end());
            std::list<int>::const_iterator expectIt2(expect.end());
            std::list<int>::reverse_iterator expectIt3(expect.end());
            std::list<int>::const_reverse_iterator expectIt4(expect.end());

            std::list<int>::const_iterator expectCIt2(expect.cend());
            std::list<int>::const_reverse_iterator expectCIt4(expect.cend());

            std::list<int>::reverse_iterator expectRIt3(expect.rend());
            std::list<int>::const_reverse_iterator expectRIt4(expect.rend());

            std::list<int>::const_reverse_iterator expectCRIt4(expect.crend());

            XorLinkedList<int> actual;
            XorLinkedList<int>::iterator actualIt1(actual.end());
            XorLinkedList<int>::const_iterator actualIt2(actual.end());
            XorLinkedList<int>::reverse_iterator actualIt3(actual.end());
            XorLinkedList<int>::const_reverse_iterator actualIt4(actual.end());

            XorLinkedList<int>::const_iterator actualCIt2(actual.cend());
            XorLinkedList<int>::const_reverse_iterator actualCIt4(actual.cend());

            XorLinkedList<int>::reverse_iterator actualRIt3(actual.rend());
            XorLinkedList<int>::const_reverse_iterator actualRIt4(actual.rend());

            XorLinkedList<int>::const_reverse_iterator actualCRIt4(actual.crend());
        }

        SECTION("end error")
        {
            std::list<int> expect;

            // std::list<int>::iterator expectCIt1(expect.cend());
            // std::list<int>::reverse_iterator expectCIt3(expect.cend());
            //
            // std::list<int>::iterator expectRIt1(expect.rend());
            // std::list<int>::const_iterator expectRIt2(expect.rend());
            //
            // std::list<int>::iterator expectCRIt1(expect.crend());
            // std::list<int>::const_iterator expectCRIt2(expect.crend());
            // std::list<int>::reverse_iterator expectCRIt3(expect.crend());

            XorLinkedList<int> actual;

            // XorLinkedList<int>::iterator actualCIt1(actual.cend());
            // XorLinkedList<int>::reverse_iterator actualCIt3(actual.cend());
            //
            // XorLinkedList<int>::iterator actualRIt1(actual.rend());
            // XorLinkedList<int>::const_iterator actualRIt2(actual.rend());
            //
            // XorLinkedList<int>::iterator actualCRIt1(actual.crend());
            // XorLinkedList<int>::const_iterator actualCRIt2(actual.crend());
            // XorLinkedList<int>::reverse_iterator actualCRIt3(actual.crend());
        }

        SECTION("const begin")
        {
            std::list<int> const expect;

            std::list<int>::const_iterator expectIt2(expect.begin());
            std::list<int>::const_reverse_iterator expectIt4(expect.begin());

            std::list<int>::const_iterator expectCIt2(expect.cbegin());
            std::list<int>::const_reverse_iterator expectCIt4(expect.cbegin());

            std::list<int>::const_reverse_iterator expectRIt4(expect.rbegin());

            std::list<int>::const_reverse_iterator expectCRIt4(expect.crbegin());

            XorLinkedList<int> const actual;

            XorLinkedList<int>::const_iterator actualIt2(actual.begin());
            XorLinkedList<int>::const_reverse_iterator actualIt4(actual.begin());

            XorLinkedList<int>::const_iterator actualCIt2(actual.cbegin());
            XorLinkedList<int>::const_reverse_iterator actualCIt4(actual.cbegin());

            XorLinkedList<int>::const_reverse_iterator actualRIt4(actual.rbegin());

            XorLinkedList<int>::const_reverse_iterator actualCRIt4(actual.crbegin());
        }

        SECTION("const begin errors")
        {
            std::list<int> const expect;

            // std::list<int>::iterator expectIt1(expect.begin());
            // std::list<int>::reverse_iterator expectIt3(expect.begin());
            //
            // std::list<int>::iterator expectCIt1(expect.cbegin());
            // std::list<int>::reverse_iterator expectCIt3(expect.cbegin());
            //
            // std::list<int>::iterator expectRIt1(expect.rbegin());
            // std::list<int>::const_iterator expectRIt2(expect.rbegin());
            // std::list<int>::reverse_iterator expectRIt3(expect.rbegin());
            //
            // std::list<int>::iterator expectCRIt1(expect.crbegin());
            // std::list<int>::const_iterator expectCRIt2(expect.crbegin());
            // std::list<int>::reverse_iterator expectCRIt3(expect.crbegin());

            XorLinkedList<int> const actual;

            // XorLinkedList<int>::iterator actualIt1(actual.begin());
            // XorLinkedList<int>::reverse_iterator actualIt3(actual.begin());
            //
            // XorLinkedList<int>::iterator actualCIt1(actual.cbegin());
            // XorLinkedList<int>::reverse_iterator actualCIt3(actual.cbegin());
            //
            // XorLinkedList<int>::iterator actualRIt1(actual.rbegin());
            // XorLinkedList<int>::const_iterator actualRIt2(actual.rbegin());
            // XorLinkedList<int>::reverse_iterator actualRIt3(actual.rbegin());
            //
            // XorLinkedList<int>::iterator actualCRIt1(actual.crbegin());
            // XorLinkedList<int>::const_iterator actualCRIt2(actual.crbegin());
            // XorLinkedList<int>::reverse_iterator actualCRIt3(actual.crbegin());
        }

        SECTION("const end")
        {
            std::list<int> const expect;

            std::list<int>::const_iterator expectIt2(expect.end());
            std::list<int>::const_reverse_iterator expectIt4(expect.end());

            std::list<int>::const_iterator expectCIt2(expect.cend());
            std::list<int>::const_reverse_iterator expectCIt4(expect.cend());

            std::list<int>::const_reverse_iterator expectRIt4(expect.rend());

            std::list<int>::const_reverse_iterator expectCRIt4(expect.crend());

            XorLinkedList<int> const actual;

            XorLinkedList<int>::const_iterator actualIt2(actual.end());
            XorLinkedList<int>::const_reverse_iterator actualIt4(actual.end());

            XorLinkedList<int>::const_iterator actualCIt2(actual.cend());
            XorLinkedList<int>::const_reverse_iterator actualCIt4(actual.cend());

            XorLinkedList<int>::const_reverse_iterator actualRIt4(actual.rend());

            XorLinkedList<int>::const_reverse_iterator actualCRIt4(actual.crend());
        }

        SECTION("const end error")
        {
            std::list<int> const expect;

            // std::list<int>::iterator expectIt1(expect.end());
            // std::list<int>::reverse_iterator expectIt3(expect.end());
            //
            // std::list<int>::iterator expectCIt1(expect.cend());
            // std::list<int>::reverse_iterator expectCIt3(expect.cend());
            //
            // std::list<int>::iterator expectRIt1(expect.rend());
            // std::list<int>::const_iterator expectRIt2(expect.rend());
            // std::list<int>::reverse_iterator expectRIt3(expect.rend());
            //
            // std::list<int>::iterator expectCRIt1(expect.crend());
            // std::list<int>::const_iterator expectCRIt2(expect.crend());
            // std::list<int>::reverse_iterator expectCRIt3(expect.crend());

            XorLinkedList<int> const actual;

            // XorLinkedList<int>::iterator actualIt1(actual.end());
            // XorLinkedList<int>::reverse_iterator actualIt3(actual.end());
            //
            // XorLinkedList<int>::iterator actualCIt1(actual.cend());
            // XorLinkedList<int>::reverse_iterator actualCIt3(actual.cend());
            //
            // XorLinkedList<int>::iterator actualRIt1(actual.rend());
            // XorLinkedList<int>::const_iterator actualRIt2(actual.rend());
            // XorLinkedList<int>::reverse_iterator actualRIt3(actual.rend());
            //
            // XorLinkedList<int>::iterator actualCRIt1(actual.crend());
            // XorLinkedList<int>::const_iterator actualCRIt2(actual.crend());
            // XorLinkedList<int>::reverse_iterator actualCRIt3(actual.crend());
        }
    }

    SECTION("container")
    {
        std::list<int> l1;
        std::list<int> l2(l1);
        std::list<int> l3{1, 2, 3};

        XorLinkedList<int> x1;
        XorLinkedList<int> x2(x1);
        XorLinkedList<int> x3{1, 2, 3};
    }
}

TEST_CASE("const semantic")
{
    SECTION("iterators")
    {
        SECTION("non-const")
        {
            XorLinkedList<int> actual;
            std::list<int> expect;

            CHECK(is_const<decltype(actual.begin())>() == is_const<decltype(expect.begin())>());
            CHECK(is_const<decltype(actual.begin().operator->())>()
                == is_const<decltype(expect.begin().operator->())>());
            CHECK(is_const<decltype(*actual.begin())>() == is_const<decltype(*expect.begin())>());
            CHECK(is_const<decltype(actual.end())>() == is_const<decltype(expect.end())>());
            CHECK(is_const<decltype(actual.end().operator->())>()
                == is_const<decltype(expect.end().operator->())>());
            CHECK(is_const<decltype(*actual.end())>() == is_const<decltype(*expect.end())>());

            CHECK(is_const<decltype(actual.cbegin())>() == is_const<decltype(expect.cbegin())>());
            CHECK(is_const<decltype(actual.cbegin().operator->())>()
                == is_const<decltype(expect.cbegin().operator->())>());
            CHECK(is_const<decltype(*actual.cbegin())>()
                == is_const<decltype(*expect.cbegin())>());
            CHECK(is_const<decltype(actual.cend())>() == is_const<decltype(expect.cend())>());
            CHECK(is_const<decltype(actual.cend().operator->())>()
                == is_const<decltype(expect.cend().operator->())>());
            CHECK(is_const<decltype(*actual.cend())>() == is_const<decltype(*expect.cend())>());

            CHECK(is_const<decltype(actual.rbegin())>() == is_const<decltype(expect.rbegin())>());
            CHECK(is_const<decltype(actual.rbegin().operator->())>()
                == is_const<decltype(expect.rbegin().operator->())>());
            CHECK(is_const<decltype(*actual.rbegin())>()
                == is_const<decltype(*expect.rbegin())>());
            CHECK(is_const<decltype(actual.rend())>() == is_const<decltype(expect.rend())>());
            CHECK(is_const<decltype(actual.rend().operator->())>()
                == is_const<decltype(expect.rend().operator->())>());
            CHECK(is_const<decltype(*actual.rend())>() == is_const<decltype(*expect.rend())>());

            CHECK(is_const<decltype(actual.crbegin())>()
                == is_const<decltype(expect.crbegin())>());
            CHECK(is_const<decltype(actual.crbegin().operator->())>()
                == is_const<decltype(expect.crbegin().operator->())>());
            CHECK(is_const<decltype(*actual.crbegin())>()
                == is_const<decltype(*expect.crbegin())>());
            CHECK(is_const<decltype(actual.crend())>() == is_const<decltype(expect.crend())>());
            CHECK(is_const<decltype(actual.crend().operator->())>()
                == is_const<decltype(expect.crend().operator->())>());
            CHECK(is_const<decltype(*actual.crend())>() == is_const<decltype(*expect.crend())>());

            CHECK(is_const<decltype(actual.rbegin().base())>()
                == is_const<decltype(expect.rbegin().base())>());
            CHECK(is_const<decltype(actual.rbegin().base().operator->())>()
                == is_const<decltype(expect.rbegin().base().operator->())>());
            CHECK(is_const<decltype(*actual.rbegin().base())>()
                == is_const<decltype(*expect.rbegin().base())>());
            CHECK(is_const<decltype(actual.rend().base())>()
                == is_const<decltype(expect.rend().base())>());
            CHECK(is_const<decltype(actual.rend().base().operator->())>()
                == is_const<decltype(expect.rend().base().operator->())>());
            CHECK(is_const<decltype(*actual.rend().base())>()
                == is_const<decltype(*expect.rend().base())>());

            CHECK(is_const<decltype(actual.crbegin().base())>()
                == is_const<decltype(expect.crbegin().base())>());
            CHECK(is_const<decltype(actual.crbegin().base().operator->())>()
                == is_const<decltype(expect.crbegin().base().operator->())>());
            CHECK(is_const<decltype(actual.crend().base())>()
                == is_const<decltype(expect.crend().base())>());
            CHECK(is_const<decltype(*actual.crbegin().base())>()
                == is_const<decltype(*expect.crbegin().base())>());
            CHECK(is_const<decltype(*actual.crbegin().base().operator->())>()
                == is_const<decltype(*expect.crbegin().base().operator->())>());
            CHECK(is_const<decltype(*actual.crend().base())>()
                == is_const<decltype(*expect.crend().base())>());
        }

        SECTION("const")
        {
            XorLinkedList<int> const actual;
            std::list<int> const expect;

            CHECK(is_const<decltype(actual.begin())>() == is_const<decltype(expect.begin())>());
            CHECK(is_const<decltype(actual.begin().operator->())>()
                == is_const<decltype(expect.begin().operator->())>());
            CHECK(is_const<decltype(*actual.begin())>() == is_const<decltype(*expect.begin())>());
            CHECK(is_const<decltype(actual.end())>() == is_const<decltype(expect.end())>());
            CHECK(is_const<decltype(actual.end().operator->())>()
                == is_const<decltype(expect.end().operator->())>());
            CHECK(is_const<decltype(*actual.end())>() == is_const<decltype(*expect.end())>());

            CHECK(is_const<decltype(actual.cbegin())>() == is_const<decltype(expect.cbegin())>());
            CHECK(is_const<decltype(actual.cbegin().operator->())>()
                == is_const<decltype(expect.cbegin().operator->())>());
            CHECK(is_const<decltype(*actual.cbegin())>()
                == is_const<decltype(*expect.cbegin())>());
            CHECK(is_const<decltype(actual.cend())>() == is_const<decltype(expect.cend())>());
            CHECK(is_const<decltype(actual.cend().operator->())>()
                == is_const<decltype(expect.cend().operator->())>());
            CHECK(is_const<decltype(*actual.cend())>() == is_const<decltype(*expect.cend())>());

            CHECK(is_const<decltype(actual.rbegin())>() == is_const<decltype(expect.rbegin())>());
            CHECK(is_const<decltype(actual.rbegin().operator->())>()
                == is_const<decltype(expect.rbegin().operator->())>());
            CHECK(is_const<decltype(*actual.rbegin())>()
                == is_const<decltype(*expect.rbegin())>());
            CHECK(is_const<decltype(actual.rend())>() == is_const<decltype(expect.rend())>());
            CHECK(is_const<decltype(actual.rend().operator->())>()
                == is_const<decltype(expect.rend().operator->())>());
            CHECK(is_const<decltype(*actual.rend())>() == is_const<decltype(*expect.rend())>());

            CHECK(is_const<decltype(actual.crbegin())>()
                == is_const<decltype(expect.crbegin())>());
            CHECK(is_const<decltype(actual.crbegin().operator->())>()
                == is_const<decltype(expect.crbegin().operator->())>());
            CHECK(is_const<decltype(*actual.crbegin())>()
                == is_const<decltype(*expect.crbegin())>());
            CHECK(is_const<decltype(actual.crend())>() == is_const<decltype(expect.crend())>());
            CHECK(is_const<decltype(actual.crend().operator->())>()
                == is_const<decltype(expect.crend().operator->())>());
            CHECK(is_const<decltype(*actual.crend())>() == is_const<decltype(*expect.crend())>());

            CHECK(is_const<decltype(actual.rbegin().base())>()
                == is_const<decltype(expect.rbegin().base())>());
            CHECK(is_const<decltype(actual.rbegin().base().operator->())>()
                == is_const<decltype(expect.rbegin().base().operator->())>());
            CHECK(is_const<decltype(*actual.rbegin().base())>()
                == is_const<decltype(*expect.rbegin().base())>());
            CHECK(is_const<decltype(actual.rend().base())>()
                == is_const<decltype(expect.rend().base())>());
            CHECK(is_const<decltype(actual.rend().base().operator->())>()
                == is_const<decltype(expect.rend().base().operator->())>());
            CHECK(is_const<decltype(*actual.rend().base())>()
                == is_const<decltype(*expect.rend().base())>());

            CHECK(is_const<decltype(actual.crbegin().base())>()
                == is_const<decltype(expect.crbegin().base())>());
            CHECK(is_const<decltype(actual.crbegin().base().operator->())>()
                == is_const<decltype(expect.crbegin().base().operator->())>());
            CHECK(is_const<decltype(actual.crend().base())>()
                == is_const<decltype(expect.crend().base())>());
            CHECK(is_const<decltype(*actual.crbegin().base())>()
                == is_const<decltype(*expect.crbegin().base())>());
            CHECK(is_const<decltype(*actual.crbegin().base().operator->())>()
                == is_const<decltype(*expect.crbegin().base().operator->())>());
            CHECK(is_const<decltype(*actual.crend().base())>()
                == is_const<decltype(*expect.crend().base())>());
        }

        SECTION("find")
        {
            XorLinkedList<int> li;
            CHECK_FALSE(is_const<decltype(li.find(1))>());
        }
    }

    SECTION("references")
    {
        SECTION("non-const")
        {
            XorLinkedList<int> actual;
            std::list<int> expect;

            CHECK(is_const<decltype(actual.front())>() == is_const<decltype(expect.front())>());
            CHECK(is_const<decltype(actual.back())>() == is_const<decltype(expect.back())>());
        }

        SECTION("const")
        {
            XorLinkedList<int> const actual;
            std::list<int> const expect;

            CHECK(is_const<decltype(actual.front())>() == is_const<decltype(expect.front())>());
            CHECK(is_const<decltype(actual.back())>() == is_const<decltype(expect.back())>());
        }
    }
}

TEST_CASE("list funcs")
{
    auto getRandomVector = ([]()
    {
        // init
        vector<int> vec(RandomSize);
        size_t i = 0 - 1;
        while (++i < RandomSize)
            vec.at(i) = static_cast<int>(i);

        // randomize
        i = 0 - 1;
        while (++i < RandomSize)
        {
            auto r = rand() % vec.size();
            auto temp = vec.at(i);
            vec.at(i) = vec.at(r);
            vec.at(r) = temp;
        }

        return vec;
    });

    auto copyRandom = ([](std::vector<int> const &vec)
    {
        XorLinkedList<int> xlist;
        for_each(vec.begin(), vec.end(), [&](int v)
        {
            xlist.push_back(v);
        });

        return xlist;
    });

    SECTION("[size/empty] rely on [push/pop]")
    {
        XorLinkedList<int> xlist;
        CHECK(xlist.empty());
        CHECK(xlist.size() == 0);
        xlist.clear();
        CHECK(xlist.empty());
        CHECK(xlist.size() == 0);

        SECTION("random actions")
        {
            auto vec = getRandomVector();

            XorLinkedList<int> xlist;
            int expectSize = 0;

            for_each(vec.begin(), vec.end(), [&](int v)
            {
                if (!(rand() % 3))                            // times: let pop be more
                {
                    if (rand() % 2)
                        xlist.push_back(v);
                    else
                        xlist.push_front(v);
                    ++expectSize;
                }
                else
                {
                    if (rand() % 2)
                    {
                        if (expectSize == 0)
                            CHECK_THROWS(xlist.pop_back());
                        else
                        {
                            CHECK_NOTHROW(xlist.pop_back());
                            --expectSize;
                        }
                    }
                    else
                    {
                        if (expectSize == 0)
                            CHECK_THROWS(xlist.pop_front());
                        else
                        {
                            CHECK_NOTHROW(xlist.pop_front());
                            --expectSize;
                        }
                    }
                }
                CHECK(xlist.size() == expectSize);
                CHECK((expectSize ^ xlist.empty()));
            });
        }
    }

    SECTION("[clear] rely on [push_back]")
    {
        SECTION("while empty")
        {
            XorLinkedList<int> xlist;
            xlist.clear();
        }

        SECTION("after actions")
        {
            XorLinkedList<int> xlist;
            xlist.push_back(1);
            xlist.push_back(2);
            xlist.clear();
            xlist.push_back(3);
        }

        SECTION("before destruct")
        {
            XorLinkedList<int> xlist;
            xlist.push_back(1);
            xlist.push_back(2);
            xlist.push_back(3);
            xlist.clear();
        }

        SECTION("while destruct")
        {
            XorLinkedList<int> xlist;
            xlist.push_back(1);
            xlist.push_back(2);
            xlist.push_back(3);
        }
    }

    SECTION("front/back rely on [push]")
    {
        SECTION("while empty")
        {
            XorLinkedList<int> xlist;
            CHECK_THROWS(xlist.back());
            CHECK_THROWS(xlist.front());
        }

        SECTION("one node")
        {
            XorLinkedList<int> xlist;
            xlist.push_back(1);
            CHECK(xlist.front() == 1);
            CHECK(xlist.back() == 1);
        }

        SECTION("two nodes")
        {
            XorLinkedList<int> xlist;
            xlist.push_back(1);
            xlist.push_back(2);
            CHECK(xlist.front() == 1);
            CHECK(xlist.back() == 2);
            xlist.push_front(3);
            CHECK(xlist.front() == 3);
            CHECK(xlist.back() == 2);
        }
    }

    SECTION("[push/pop] rely on [clear/begin/end/front/back]")
    {
        SECTION("push]")
        {
            SECTION("push front")
            {
                XorLinkedList<int> xlist;
                xlist.push_front(111);
                CHECK(xlist.front() == 111);
                CHECK(xlist.back() == 111);
                CHECK(*xlist.begin() == 111);
                CHECK(*--xlist.end() == 111);

                xlist.push_front(222);
                CHECK(xlist.front() == 222);
                CHECK(xlist.back() == 111);
                CHECK(*xlist.begin() == 222);
                CHECK(*++xlist.begin() == 111);
                CHECK(*--xlist.end() == 111);
                CHECK(*---- xlist.end() == 222);

                xlist.push_front(333);
                CHECK(xlist.front() == 333);
                CHECK(xlist.back() == 111);
                CHECK(*xlist.begin() == 333);
                CHECK(*++xlist.begin() == 222);
                CHECK(*++++ xlist.begin() == 111);
                CHECK(*--xlist.end() == 111);
                CHECK(*---- xlist.end() == 222);
                CHECK(*------ xlist.end() == 333);
            }

            SECTION("push back")
            {
                XorLinkedList<int> xlist;
                xlist.push_back(111);
                CHECK(xlist.front() == 111);
                CHECK(xlist.back() == 111);
                CHECK(*xlist.begin() == 111);
                CHECK(*--xlist.end() == 111);

                xlist.push_back(222);
                CHECK(xlist.front() == 111);
                CHECK(xlist.back() == 222);
                CHECK(*xlist.begin() == 111);
                CHECK(*++xlist.begin() == 222);
                CHECK(*--xlist.end() == 222);
                CHECK(*---- xlist.end() == 111);

                xlist.push_back(333);
                CHECK(xlist.front() == 111);
                CHECK(xlist.back() == 333);
                CHECK(*xlist.begin() == 111);
                CHECK(*++xlist.begin() == 222);
                CHECK(*++++ xlist.begin() == 333);
                CHECK(*--xlist.end() == 333);
                CHECK(*---- xlist.end() == 222);
                CHECK(*------ xlist.end() == 111);
            }

            SECTION("random push")
            {
                auto vec = getRandomVector();

                XorLinkedList<int> xlist;
                list<int> actualList;
                for_each(vec.begin(), vec.end(), [&](int v)
                {
                    if (rand() % 2)
                    {
                        xlist.push_back(v);
                        actualList.push_back(v);
                    }
                    else
                    {
                        xlist.push_front(v);
                        actualList.push_front(v);
                    }

                    CHECK(xlist.front() == actualList.front());
                    CHECK(xlist.back() == actualList.back());
                });
            }
        }

        SECTION("pop rely on [push_back/front/back]")
        {
            SECTION("pop_front")
            {}

            SECTION("pop_back")
            {
                XorLinkedList<int> xlist;
                CHECK_THROWS(xlist.pop_back());

                xlist.push_back(111);
                CHECK_NOTHROW(xlist.pop_back());
                CHECK_THROWS(xlist.front());
                CHECK_THROWS(xlist.back());

                xlist.push_back(111);
                xlist.push_back(222);
                CHECK_NOTHROW(xlist.pop_back());
                CHECK_NOTHROW(xlist.pop_back());
                CHECK_THROWS(xlist.front());
                CHECK_THROWS(xlist.back());

                xlist.push_back(111);
                xlist.push_back(222);
                xlist.push_back(333);
                CHECK_NOTHROW(xlist.pop_back());
                CHECK_NOTHROW(xlist.pop_back());
                CHECK_NOTHROW(xlist.pop_back());
                CHECK_THROWS(xlist.front());
                CHECK_THROWS(xlist.back());
            }

            SECTION("random pop")
            {
                auto vec = getRandomVector();

                XorLinkedList<int> xlist;
                list<int> actualList;
                for_each(vec.begin(), vec.end(), [&](int v)
                {
                    xlist.push_back(v);
                    actualList.push_back(v);
                });

                while (!actualList.empty())
                {
                    CHECK(xlist.front() == actualList.front());
                    CHECK(xlist.back() == actualList.back());
                    if (rand() % 2)
                    {
                        xlist.pop_back();
                        actualList.pop_back();
                    }
                    else
                    {
                        xlist.pop_front();
                        actualList.pop_front();
                    }
                }
            }
        }

        SECTION("random push/pop rely on[front/back]")
        {
            SECTION("push times is larger than")
            {
                auto vec = getRandomVector();

                XorLinkedList<int> xlist;
                list<int> actualList;
                for_each(vec.begin(), vec.end(), [&](int v)
                {
                    if (rand() % 3)
                    {
                        if (rand() % 2)
                        {
                            xlist.push_back(v);
                            actualList.push_back(v);
                        }
                        else
                        {
                            xlist.push_front(v);
                            actualList.push_front(v);
                        }
                    }
                    else
                    {
                        if (rand() % 2)
                        {
                            if (actualList.empty())
                                CHECK_THROWS(xlist.pop_back());
                            else
                            {
                                CHECK_NOTHROW(xlist.pop_back());
                                actualList.pop_back();
                            }
                        }
                        else
                        {
                            if (actualList.empty())
                                CHECK_THROWS(xlist.pop_front());
                            else
                            {
                                CHECK_NOTHROW(xlist.pop_front());
                                actualList.pop_front();
                            }
                        }
                    }
                    if (!actualList.empty())
                    {
                        CHECK(xlist.front() == actualList.front());
                        CHECK(xlist.back() == actualList.back());
                    }
                });
            }

            SECTION("pop times is larger than")
            {
                auto vec = getRandomVector();

                XorLinkedList<int> xlist;
                list<int> actualList;
                for_each(vec.begin(), vec.end(), [&](int v)
                {
                    if (!(rand() % 3))
                    {
                        if (rand() % 2)
                        {
                            xlist.push_back(v);
                            actualList.push_back(v);
                        }
                        else
                        {
                            xlist.push_front(v);
                            actualList.push_front(v);
                        }
                    }
                    else
                    {
                        if (rand() % 2)
                        {
                            if (actualList.empty())
                                CHECK_THROWS(xlist.pop_back());
                            else
                            {
                                CHECK_NOTHROW(xlist.pop_back());
                                actualList.pop_back();
                            }
                        }
                        else
                        {
                            if (actualList.empty())
                                CHECK_THROWS(xlist.pop_front());
                            else
                            {
                                CHECK_NOTHROW(xlist.pop_front());
                                actualList.pop_front();
                            }
                        }
                    }
                    if (!actualList.empty())
                    {
                        CHECK(xlist.front() == actualList.front());
                        CHECK(xlist.back() == actualList.back());
                    }
                });
            }
        }
    }

    SECTION("begin/rbegin/end/rend rely on [push_back]")
    {
        SECTION("random move (op++ more than op--) rely on [push_back]")
        {
            SECTION("iterator")
            {
                SECTION("++i/--i")
                {
                    auto vec = getRandomVector();
                    auto xlist = copyRandom(vec);

                    auto actualIt = xlist.begin();
                    auto expectIt = vec.begin();
                    while (expectIt < vec.end())
                    {
                        if (expectIt < vec.begin())
                        {
                            ++expectIt;
                            ++actualIt;
                        }

                        if (expectIt > --vec.begin() && expectIt < vec.end())
                            CHECK(*actualIt == *expectIt);

                        if (rand() % 3) // times: ++ > --
                        {
                            auto temp = expectIt;
                            if (++temp < vec.end())    // is not lastest
                                CHECK(*(++actualIt) == *(++expectIt));
                            else
                            {
                                ++actualIt;
                                ++expectIt;
                                break;
                            }
                        }
                        else if (expectIt > vec.begin())
                            CHECK(*(--actualIt) == *(--expectIt));

                        if (expectIt > --vec.begin() && expectIt < vec.end())
                            CHECK(*actualIt == *expectIt);
                    }
                }

                SECTION("i++/i--")
                {
                    auto vec = getRandomVector();

                    XorLinkedList<int> xlist;
                    for_each(vec.begin(), vec.end(), [&](int v)
                    {
                        xlist.push_back(v);
                    });

                    auto actualIt = xlist.begin();
                    auto expectIt = vec.begin();
                    while (expectIt < vec.end())
                    {
                        if (expectIt < vec.begin())
                        {
                            ++expectIt;
                            ++actualIt;
                        }

                        if (expectIt > --vec.begin() && expectIt < vec.end())
                            CHECK(*actualIt == *expectIt);

                        if (rand() % 3) // times: ++ > --
                            CHECK(*(actualIt++) == *(expectIt++));
                        else if (expectIt > vec.begin())
                            CHECK(*(actualIt--) == *(expectIt--));

                        if (expectIt > --vec.begin() && expectIt < vec.end())
                            CHECK(*actualIt == *expectIt);
                    }
                }
            }

            SECTION("reverse iterator")
            {
                SECTION("++i/--i")
                {
                    auto vec = getRandomVector();
                    auto xlist = copyRandom(vec);

                    auto actualIt = xlist.rbegin();
                    auto expectIt = vec.rbegin();
                    while (expectIt < vec.rend())
                    {
                        if (expectIt < vec.rbegin())
                        {
                            ++expectIt;
                            ++actualIt;
                        }

                        if (expectIt > --vec.rbegin() && expectIt < vec.rend())
                            CHECK(*actualIt == *expectIt);

                        if (rand() % 3) // times: ++ > --
                        {
                            auto temp = expectIt;
                            if (++temp < vec.rend())   // is not lastest
                                CHECK(*(++actualIt) == *(++expectIt));
                            else
                            {
                                ++actualIt;
                                ++expectIt;
                                break;
                            }
                        }
                        else if (expectIt > vec.rbegin())
                            CHECK(*(--actualIt) == *(--expectIt));

                        if (expectIt > --vec.rbegin() && expectIt < vec.rend())
                            CHECK(*actualIt == *expectIt);
                    }
                }

                SECTION("i++/i--")
                {
                    auto vec = getRandomVector();
                    auto xlist = copyRandom(vec);

                    auto actualIt = xlist.rbegin();
                    auto expectIt = vec.rbegin();
                    while (expectIt < vec.rend())
                    {
                        if (expectIt < vec.rbegin())
                        {
                            ++expectIt;
                            ++actualIt;
                        }

                        if (expectIt > --vec.rbegin() && expectIt < vec.rend())
                            CHECK(*actualIt == *expectIt);

                        if (rand() % 3) // times: ++ > --
                            CHECK(*(actualIt++) == *(expectIt++));
                        else if (expectIt > vec.rbegin())
                            CHECK(*(actualIt--) == *(expectIt--));

                        if (expectIt > --vec.rbegin() && expectIt < vec.rend())
                            CHECK(*actualIt == *expectIt);
                    }
                }
            }
        }

        SECTION("random move (op-- more than op++) rely on [push_back]")
        {
            SECTION("iterator")
            {
                SECTION("++i/--i rely on [push_back]")
                {
                    auto vec = getRandomVector();
                    auto xlist = copyRandom(vec);

                    auto actualIt = --xlist.end();
                    auto expectIt = --vec.end();
                    while (expectIt > vec.begin())
                    {
                        if (expectIt >= vec.end())
                        {
                            --expectIt;
                            --actualIt;
                        }

                        if (expectIt > --vec.begin() && expectIt < vec.end())
                            CHECK(*actualIt == *expectIt);

                        if (!(rand() % 3)) // times: ++ < --
                        {
                            auto temp = expectIt;
                            if (++temp < vec.end())
                                CHECK(*(++actualIt) == *(++expectIt));
                            else
                            {
                                ++actualIt;
                                ++expectIt;
                                break;
                            }
                        }
                        else if (expectIt > vec.begin())
                            CHECK(*(--actualIt) == *(--expectIt));

                        if (expectIt > --vec.begin() && expectIt < vec.end())
                            CHECK(*actualIt == *expectIt);
                    }
                }

                SECTION("i++/i-- rely on [push_back]")
                {
                    auto vec = getRandomVector();
                    auto xlist = copyRandom(vec);

                    auto actualIt = --xlist.end();
                    auto expectIt = --vec.end();
                    while (expectIt > vec.begin())
                    {
                        if (expectIt >= vec.end())
                        {
                            --expectIt;
                            --actualIt;
                        }

                        if (expectIt > --vec.begin() && expectIt < vec.end())
                            CHECK(*actualIt == *expectIt);

                        if (!(rand() % 3)) // times: ++ < --
                            CHECK(*actualIt++ == *expectIt++);
                        else if (expectIt > vec.begin())
                            CHECK(*actualIt-- == *expectIt--);

                        if (expectIt > --vec.begin() && expectIt < vec.end())
                            CHECK(*actualIt == *expectIt);
                    }
                }
            }

            SECTION("reverse iterator")
            {
                SECTION("++i/--i rely on [push_back]")
                {
                    auto vec = getRandomVector();
                    auto xlist = copyRandom(vec);

                    auto actualIt = xlist.rbegin();
                    auto expectIt = vec.rbegin();
                    while (expectIt > vec.rbegin())
                    {
                        if (expectIt >= vec.rend())
                        {
                            --expectIt;
                            --actualIt;
                        }
                        if (expectIt > --vec.rbegin() && expectIt < vec.rend())
                            CHECK(*actualIt == *expectIt);

                        if (!(rand() % 3)) // times: ++ < --
                        {
                            auto temp = expectIt;
                            if (++temp < vec.rend())
                                CHECK(*(++actualIt) == *(++expectIt));
                            else
                            {
                                ++actualIt;
                                ++expectIt;
                                break;
                            }
                        }
                        else if (expectIt > vec.rbegin())
                            CHECK(*(--actualIt) == *(--expectIt));

                        if (expectIt > --vec.rbegin() && expectIt < vec.rend())
                            CHECK(*actualIt == *expectIt);
                    }
                }

                SECTION("i++/i-- rely on [push_back]")
                {
                    auto vec = getRandomVector();
                    auto xlist = copyRandom(vec);

                    auto actualIt = xlist.rbegin();
                    auto expectIt = vec.rbegin();
                    while (expectIt > vec.rbegin())
                    {
                        if (expectIt >= vec.rend())
                        {
                            --expectIt;
                            --actualIt;
                        }

                        if (expectIt > --vec.rbegin() && expectIt < vec.rend())
                            CHECK(*actualIt == *expectIt);

                        if (!(rand() % 3)) // times: ++ < --
                            CHECK(*(actualIt++) == *(expectIt++));
                        else if (expectIt > vec.rbegin())
                            CHECK(*(actualIt--) == *(expectIt--));

                        if (expectIt > --vec.rbegin() && expectIt < vec.rend())
                            CHECK(*actualIt == *expectIt);
                    }
                }
            }
        }

        SECTION("[reverse iterator: base] rely on [++/--]")
        {
            auto vec = getRandomVector();
            XorLinkedList<int> xlist = copyRandom(vec);
            vector<int>::reverse_iterator vrb(vec.begin());
            XorLinkedList<int>::const_reverse_iterator xrb(xlist.begin());
            auto vb = vrb.base();
            auto xb = xrb.base();

            while (vb != vec.end())
            {
                CHECK(*vb == *xb);
                ++vb;
                ++xb;
            }
        }
    }

    SECTION("[reverse]")
    {
        SECTION("empty")
        {
            XorLinkedList<int> xlist;
            CHECK(xlist.empty());
            CHECK(xlist.size() == 0);
            CHECK(xlist.begin() == xlist.end());

            xlist.reverse();
            CHECK(xlist.empty());
            CHECK(xlist.size() == 0);
            CHECK(xlist.begin() == xlist.end());
        }

        SECTION("one nodes")
        {
            XorLinkedList<int> xlist;
            xlist.push_back(1);
            CHECK(xlist.front() == 1);
            CHECK(xlist.back() == 1);
            CHECK(xlist.size() == 1);
            CHECK_FALSE(xlist.empty());

            xlist.reverse();
            CHECK(xlist.front() == 1);
            CHECK(xlist.back() == 1);
            CHECK(xlist.size() == 1);
            CHECK_FALSE(xlist.empty());

            xlist.pop_back();
            CHECK_THROWS(xlist.front());
            CHECK_THROWS(xlist.back());
            CHECK(xlist.size() == 0);
            CHECK(xlist.empty());
        }

        SECTION("two nodes")
        {
            XorLinkedList<int> xlist;
            xlist.push_back(1);
            xlist.push_back(2);
            CHECK(xlist.front() == 1);
            CHECK(xlist.back() == 2);
            CHECK(xlist.size() == 2);
            CHECK_FALSE(xlist.empty());

            xlist.reverse();
            CHECK(xlist.front() == 2);
            CHECK(xlist.back() == 1);
            CHECK(xlist.size() == 2);
            CHECK_FALSE(xlist.empty());

            xlist.pop_back();
            CHECK(xlist.front() == 2);
            CHECK(xlist.back() == 2);
            CHECK(xlist.size() == 1);
            CHECK_FALSE(xlist.empty());

            xlist.pop_back();
            CHECK_THROWS(xlist.front());
            CHECK_THROWS(xlist.back());
            CHECK(xlist.size() == 0);
            CHECK(xlist.empty());
        }

        SECTION("three nodes")
        {
            XorLinkedList<int> xlist;
            xlist.push_back(1);
            xlist.push_back(2);
            xlist.push_back(3);
            CHECK(xlist.front() == 1);
            CHECK(xlist.back() == 3);
            CHECK(xlist.size() == 3);
            CHECK_FALSE(xlist.empty());

            xlist.reverse();
            CHECK(xlist.front() == 3);
            CHECK(xlist.back() == 1);
            CHECK(xlist.size() == 3);
            CHECK_FALSE(xlist.empty());

            xlist.pop_back();
            CHECK(xlist.front() == 3);
            CHECK(xlist.back() == 2);
            CHECK(xlist.size() == 2);
            CHECK_FALSE(xlist.empty());

            xlist.pop_back();
            CHECK(xlist.front() == 3);
            CHECK(xlist.back() == 3);
            CHECK(xlist.size() == 1);
            CHECK_FALSE(xlist.empty());

            xlist.pop_back();
            CHECK_THROWS(xlist.front());
            CHECK_THROWS(xlist.back());
            CHECK(xlist.size() == 0);
            CHECK(xlist.empty());
        }

        SECTION("random nodes")
        {
            auto vec = getRandomVector();

            XorLinkedList<int> xlist;
            list<int> expectList;
            while (!vec.empty())
            {
                auto v = vec.back();
                if (rand() % 2)
                {
                    if (rand() % 2)
                    {
                        xlist.push_back(v);
                        expectList.push_back(v);
                    }
                    else
                    {
                        xlist.push_front(v);
                        expectList.push_front(v);
                    }
                }
                else
                {
                    if (rand() % 2)
                    {
                        if (!expectList.empty())
                        {
                            xlist.pop_back();
                            expectList.pop_back();
                        }
                    }
                    else if (!expectList.empty())
                    {
                        xlist.pop_front();
                        expectList.pop_front();
                    }
                }
                if (!expectList.empty())
                {
                    xlist.reverse();
                    reverse(xlist.begin(), xlist.end());
                    xlist.reverse();
                    reverse(xlist.begin(), xlist.end());
                    xlist.reverse();
                    reverse(expectList.begin(), expectList.end());
                }
                CHECK(xlist.size() == expectList.size());
                CHECK((expectList.size() ^ xlist.empty()));
                if (!expectList.empty())
                {
                    CHECK(expectList.front() == xlist.front());
                    CHECK(expectList.back() == xlist.back());
                }
                vec.pop_back();
            }
        }
    }

    SECTION("empty list")
    {
        XorLinkedList<int> xlist;
        xlist.clear();

        CHECK_THROWS(xlist.front());
        CHECK_THROWS(xlist.back());
        CHECK_THROWS(xlist.pop_front());
        CHECK_THROWS(xlist.pop_back());
        CHECK(xlist.size() == 0);
        CHECK(xlist.empty());
    }

    SECTION("random nodes")
    {
        // todo: test more functions insert/find/unique/sort/erase

        auto vec = getRandomVector();

        XorLinkedList<int> xlist;
        int expectSize = 1;
        list<int> expectList;
        expectList.push_front(vec.front());
        xlist.push_front(vec.front());
        for_each(++vec.begin(), vec.end(), [&](int v)
        {
            if (rand() % 2)
            {
                if (rand() % 2)
                {
                    xlist.push_back(v);
                    expectList.push_back(v);
                }
                else
                {
                    xlist.push_front(v);
                    expectList.push_front(v);
                }
                ++expectSize;
            }
            else
            {
                if (rand() % 2)
                {
                    if (expectSize == 0)
                        CHECK_THROWS(xlist.pop_back());
                    else
                    {
                        CHECK_NOTHROW(xlist.pop_back());
                        CHECK_NOTHROW(expectList.pop_back());
                        --expectSize;
                    }
                }
                else
                {
                    if (expectSize == 0)
                        CHECK_THROWS(xlist.pop_front());
                    else
                    {
                        CHECK_NOTHROW(xlist.pop_front());
                        CHECK_NOTHROW(expectList.pop_front());
                        --expectSize;
                    }
                }
            }
            CHECK(xlist.size() == expectSize);
            CHECK((expectSize ^ xlist.empty()));
            if (!expectList.empty())
            {
                CHECK(expectList.front() == xlist.front());
                CHECK(expectList.back() == xlist.back());
            }
        });
    }

    SECTION("efficiency")
    {
        // todo
    }
}

#endif // XOR_LINKED_LIST_TEST_CPP
