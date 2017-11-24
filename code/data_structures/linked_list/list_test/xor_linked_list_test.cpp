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

const size_t RandomSize = 100000 + rand() % 2;
const size_t SmallRandomSize = RandomSize / 100;

auto getRandomValueContainer = ([](size_t sz = RandomSize)
{
    // init
    std::vector<int> container(sz);
    size_t i = 0 - 1;
    while (++i < sz)
        container.at(i) = static_cast<int>(i);

    // randomize
    i = 0 - 1;
    while (++i < sz)
    {
        auto r = rand() % container.size();
        auto temp = container.at(i);
        container.at(i) = container.at(r);
        container.at(r) = temp;
    }

    return container;
});

auto copyContainerToList = ([](const std::vector<int> &container)
{
    XorLinkedList<int> actual;
    for_each(container.begin(), container.end(), [&](int v)
    {
        actual.push_back(v);
    });

    return actual;
});

auto isSame = ([](std::list<int> expect, XorLinkedList<int> actual)
{
    CHECK(expect.size() == actual.size());
    CHECK(expect.empty() == actual.empty());

    auto expectIt = expect.begin();
    auto actualIt = actual.begin();

    while (expectIt != expect.end())
        CHECK(*expectIt++ == *actualIt++);
});

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
            const std::list<int> expect;

            std::list<int>::const_iterator expectIt2(expect.begin());
            std::list<int>::const_reverse_iterator expectIt4(expect.begin());

            std::list<int>::const_iterator expectCIt2(expect.cbegin());
            std::list<int>::const_reverse_iterator expectCIt4(expect.cbegin());

            std::list<int>::const_reverse_iterator expectRIt4(expect.rbegin());

            std::list<int>::const_reverse_iterator expectCRIt4(expect.crbegin());

            const XorLinkedList<int> actual;

            XorLinkedList<int>::const_iterator actualIt2(actual.begin());
            XorLinkedList<int>::const_reverse_iterator actualIt4(actual.begin());

            XorLinkedList<int>::const_iterator actualCIt2(actual.cbegin());
            XorLinkedList<int>::const_reverse_iterator actualCIt4(actual.cbegin());

            XorLinkedList<int>::const_reverse_iterator actualRIt4(actual.rbegin());

            XorLinkedList<int>::const_reverse_iterator actualCRIt4(actual.crbegin());
        }

        SECTION("const begin errors")
        {
            const std::list<int> expect;

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

            const XorLinkedList<int> actual;

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
            const std::list<int> expect;

            std::list<int>::const_iterator expectIt2(expect.end());
            std::list<int>::const_reverse_iterator expectIt4(expect.end());

            std::list<int>::const_iterator expectCIt2(expect.cend());
            std::list<int>::const_reverse_iterator expectCIt4(expect.cend());

            std::list<int>::const_reverse_iterator expectRIt4(expect.rend());

            std::list<int>::const_reverse_iterator expectCRIt4(expect.crend());

            const XorLinkedList<int> actual;

            XorLinkedList<int>::const_iterator actualIt2(actual.end());
            XorLinkedList<int>::const_reverse_iterator actualIt4(actual.end());

            XorLinkedList<int>::const_iterator actualCIt2(actual.cend());
            XorLinkedList<int>::const_reverse_iterator actualCIt4(actual.cend());

            XorLinkedList<int>::const_reverse_iterator actualRIt4(actual.rend());

            XorLinkedList<int>::const_reverse_iterator actualCRIt4(actual.crend());
        }

        SECTION("const end error")
        {
            const std::list<int> expect;

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

            const XorLinkedList<int> actual;

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
        std::list<int> expect1;
        std::list<int> expect2(expect1);
        std::list<int> expect3{1, 2, 3};

        XorLinkedList<int> actual1;
        XorLinkedList<int> actual2(actual1);
        XorLinkedList<int> actual3{1, 2, 3};
    }
}

TEST_CASE("const semantic")
{
    using std::is_const;
    SECTION("iterators")
    {
        SECTION("non-const")
        {
            std::list<int> expect;
            XorLinkedList<int> actual;

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
            const std::list<int> expect;
            const XorLinkedList<int> actual;

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
            XorLinkedList<int> actual;
            CHECK_FALSE(is_const<decltype(actual.find(1))>());
        }
    }

    SECTION("element access")
    {
        SECTION("non-const")
        {
            std::list<int> expect;
            XorLinkedList<int> actual;

            CHECK(is_const<decltype(actual.front())>() == is_const<decltype(expect.front())>());
            CHECK(is_const<decltype(actual.back())>() == is_const<decltype(expect.back())>());
        }

        SECTION("const")
        {
            const std::list<int> expect;
            const XorLinkedList<int> actual;

            CHECK(is_const<decltype(actual.front())>() == is_const<decltype(expect.front())>());
            CHECK(is_const<decltype(actual.back())>() == is_const<decltype(expect.back())>());
        }
    }
}

TEST_CASE("element access rely on [push]")
{
    SECTION("while empty")
    {
        XorLinkedList<int> actual;
        CHECK_THROWS(actual.back());
        CHECK_THROWS(actual.front());
    }

    SECTION("one node")
    {
        XorLinkedList<int> actual;
        actual.push_back(1);
        CHECK(actual.front() == 1);
        CHECK(actual.back() == 1);
    }

    SECTION("two nodes")
    {
        XorLinkedList<int> actual;
        actual.push_back(1);
        actual.push_back(2);
        CHECK(actual.front() == 1);
        CHECK(actual.back() == 2);
        actual.push_front(3);
        CHECK(actual.front() == 3);
        CHECK(actual.back() == 2);
    }
}

TEST_CASE("capcity rely on [push/pop]")
{
    XorLinkedList<int> actual;
    CHECK(actual.empty());
    CHECK(actual.size() == 0);
    actual.clear();
    CHECK(actual.empty());
    CHECK(actual.size() == 0);

    SECTION("random actions")
    {
        auto container = getRandomValueContainer();

        XorLinkedList<int> actual;
        int expectSize = 0;

        for_each(container.begin(), container.end(), [&](int v)
        {
            if (!(rand() % 3))
            {
                if (rand() % 2)
                    actual.push_back(v);
                else
                    actual.push_front(v);
                ++expectSize;
            }
            else
            {
                if (rand() % 2)
                {
                    if (expectSize == 0)
                        CHECK_THROWS(actual.pop_back());
                    else
                    {
                        CHECK_NOTHROW(actual.pop_back());
                        --expectSize;
                    }
                }
                else
                {
                    if (expectSize == 0)
                        CHECK_THROWS(actual.pop_front());
                    else
                    {
                        CHECK_NOTHROW(actual.pop_front());
                        --expectSize;
                    }
                }
            }
            CHECK(actual.size() == expectSize);
            CHECK((expectSize ^ actual.empty()));
        });
    }
}

TEST_CASE("modifiers")
{
    SECTION("[clear] rely on [push_back]")
    {
        SECTION("while empty")
        {
            XorLinkedList<int> actual;
            actual.clear();
        }

        SECTION("after actions")
        {
            XorLinkedList<int> actual;
            actual.push_back(1);
            actual.push_back(2);
            actual.clear();
            actual.push_back(3);
        }

        SECTION("before destruct")
        {
            XorLinkedList<int> actual;
            actual.push_back(1);
            actual.push_back(2);
            actual.push_back(3);
            actual.clear();
        }

        SECTION("while destruct")
        {
            XorLinkedList<int> actual;
            actual.push_back(1);
            actual.push_back(2);
            actual.push_back(3);
        }
    }

    SECTION("[push/pop] rely on [clear/begin/end/front/back]")
    {
        SECTION("push]")
        {
            SECTION("push front")
            {
                XorLinkedList<int> actual;
                actual.push_front(111);
                CHECK(actual.front() == 111);
                CHECK(actual.back() == 111);
                CHECK(*actual.begin() == 111);
                CHECK(*--actual.end() == 111);

                actual.push_front(222);
                CHECK(actual.front() == 222);
                CHECK(actual.back() == 111);
                CHECK(*actual.begin() == 222);
                CHECK(*++actual.begin() == 111);
                CHECK(*--actual.end() == 111);
                CHECK(*---- actual.end() == 222);

                actual.push_front(333);
                CHECK(actual.front() == 333);
                CHECK(actual.back() == 111);
                CHECK(*actual.begin() == 333);
                CHECK(*++actual.begin() == 222);
                CHECK(*++++ actual.begin() == 111);
                CHECK(*--actual.end() == 111);
                CHECK(*---- actual.end() == 222);
                CHECK(*------ actual.end() == 333);
            }

            SECTION("push back")
            {
                XorLinkedList<int> actual;
                actual.push_back(111);
                CHECK(actual.front() == 111);
                CHECK(actual.back() == 111);
                CHECK(*actual.begin() == 111);
                CHECK(*--actual.end() == 111);

                actual.push_back(222);
                CHECK(actual.front() == 111);
                CHECK(actual.back() == 222);
                CHECK(*actual.begin() == 111);
                CHECK(*++actual.begin() == 222);
                CHECK(*--actual.end() == 222);
                CHECK(*---- actual.end() == 111);

                actual.push_back(333);
                CHECK(actual.front() == 111);
                CHECK(actual.back() == 333);
                CHECK(*actual.begin() == 111);
                CHECK(*++actual.begin() == 222);
                CHECK(*++++ actual.begin() == 333);
                CHECK(*--actual.end() == 333);
                CHECK(*---- actual.end() == 222);
                CHECK(*------ actual.end() == 111);
            }

            SECTION("random push")
            {
                auto container = getRandomValueContainer();

                std::list<int> expect;
                XorLinkedList<int> actual;
                for_each(container.begin(), container.end(), [&](int v)
                {
                    if (rand() % 2)
                    {
                        actual.push_back(v);
                        expect.push_back(v);
                    }
                    else
                    {
                        actual.push_front(v);
                        expect.push_front(v);
                    }

                    CHECK(actual.front() == expect.front());
                    CHECK(actual.back() == expect.back());
                });
            }
        }

        SECTION("pop rely on [push_back/front/back]")
        {
            SECTION("pop_front")
            {}

            SECTION("pop_back")
            {
                XorLinkedList<int> actual;
                CHECK_THROWS(actual.pop_back());

                actual.push_back(111);
                CHECK_NOTHROW(actual.pop_back());
                CHECK_THROWS(actual.front());
                CHECK_THROWS(actual.back());

                actual.push_back(111);
                actual.push_back(222);
                CHECK_NOTHROW(actual.pop_back());
                CHECK_NOTHROW(actual.pop_back());
                CHECK_THROWS(actual.front());
                CHECK_THROWS(actual.back());

                actual.push_back(111);
                actual.push_back(222);
                actual.push_back(333);
                CHECK_NOTHROW(actual.pop_back());
                CHECK_NOTHROW(actual.pop_back());
                CHECK_NOTHROW(actual.pop_back());
                CHECK_THROWS(actual.front());
                CHECK_THROWS(actual.back());
            }

            SECTION("random pop")
            {
                auto container = getRandomValueContainer();

                std::list<int> expect;
                XorLinkedList<int> actual;
                for_each(container.begin(), container.end(), [&](int v)
                {
                    actual.push_back(v);
                    expect.push_back(v);
                });

                while (!expect.empty())
                {
                    CHECK(actual.front() == expect.front());
                    CHECK(actual.back() == expect.back());
                    if (rand() % 2)
                    {
                        actual.pop_back();
                        expect.pop_back();
                    }
                    else
                    {
                        actual.pop_front();
                        expect.pop_front();
                    }
                }
            }
        }

        SECTION("random push/pop rely on [front/back]")
        {
            SECTION("push times is larger than")
            {
                auto container = getRandomValueContainer();

                std::list<int> expect;
                XorLinkedList<int> actual;
                for_each(container.begin(), container.end(), [&](int v)
                {
                    if (rand() % 3)
                    {
                        if (rand() % 2)
                        {
                            actual.push_back(v);
                            expect.push_back(v);
                        }
                        else
                        {
                            actual.push_front(v);
                            expect.push_front(v);
                        }
                    }
                    else
                    {
                        if (rand() % 2)
                        {
                            if (expect.empty())
                                CHECK_THROWS(actual.pop_back());
                            else
                            {
                                CHECK_NOTHROW(actual.pop_back());
                                expect.pop_back();
                            }
                        }
                        else
                        {
                            if (expect.empty())
                                CHECK_THROWS(actual.pop_front());
                            else
                            {
                                CHECK_NOTHROW(actual.pop_front());
                                expect.pop_front();
                            }
                        }
                    }
                    if (!expect.empty())
                    {
                        CHECK(actual.front() == expect.front());
                        CHECK(actual.back() == expect.back());
                    }
                });
            }

            SECTION("pop times is larger than")
            {
                auto container = getRandomValueContainer();

                std::list<int> expect;
                XorLinkedList<int> actual;
                for_each(container.begin(), container.end(), [&](int v)
                {
                    if (!(rand() % 3))
                    {
                        if (rand() % 2)
                        {
                            actual.push_back(v);
                            expect.push_back(v);
                        }
                        else
                        {
                            actual.push_front(v);
                            expect.push_front(v);
                        }
                    }
                    else
                    {
                        if (rand() % 2)
                        {
                            if (expect.empty())
                                CHECK_THROWS(actual.pop_back());
                            else
                            {
                                CHECK_NOTHROW(actual.pop_back());
                                expect.pop_back();
                            }
                        }
                        else
                        {
                            if (expect.empty())
                                CHECK_THROWS(actual.pop_front());
                            else
                            {
                                CHECK_NOTHROW(actual.pop_front());
                                expect.pop_front();
                            }
                        }
                    }
                    if (!expect.empty())
                    {
                        CHECK(actual.front() == expect.front());
                        CHECK(actual.back() == expect.back());
                    }
                });
            }
        }
    }

    SECTION("[iterator] rely on [push_back]")
    {
        SECTION("random move (i++ more than i--) rely on [push_back]")
        {
            SECTION("iterator")
            {
                SECTION("++i/--i")
                {
                    auto expect = getRandomValueContainer();
                    auto actual = copyContainerToList(expect);

                    auto actualIt = actual.begin();
                    auto expectIt = expect.begin();
                    while (expectIt < expect.end())
                    {
                        if (expectIt < expect.begin())
                        {
                            ++expectIt;
                            ++actualIt;
                        }

                        if (expectIt > --expect.begin() && expectIt < expect.end())
                            CHECK(*actualIt == *expectIt);

                        if (rand() % 3) // times: ++ > --
                        {
                            auto temp = expectIt;
                            if (++temp < expect.end())    // is not lastest
                                CHECK(*(++actualIt) == *(++expectIt));
                            else
                            {
                                ++actualIt;
                                ++expectIt;
                                break;
                            }
                        }
                        else if (expectIt > expect.begin())
                            CHECK(*(--actualIt) == *(--expectIt));

                        if (expectIt > --expect.begin() && expectIt < expect.end())
                            CHECK(*actualIt == *expectIt);
                    }
                }

                SECTION("i++/i--")
                {
                    auto expect = getRandomValueContainer();

                    XorLinkedList<int> actual;
                    for_each(expect.begin(), expect.end(), [&](int v)
                    {
                        actual.push_back(v);
                    });

                    auto actualIt = actual.begin();
                    auto expectIt = expect.begin();
                    while (expectIt < expect.end())
                    {
                        if (expectIt < expect.begin())
                        {
                            ++expectIt;
                            ++actualIt;
                        }

                        if (expectIt > --expect.begin() && expectIt < expect.end())
                            CHECK(*actualIt == *expectIt);

                        if (rand() % 3) // times: ++ > --
                            CHECK(*(actualIt++) == *(expectIt++));
                        else if (expectIt > expect.begin())
                            CHECK(*(actualIt--) == *(expectIt--));

                        if (expectIt > --expect.begin() && expectIt < expect.end())
                            CHECK(*actualIt == *expectIt);
                    }
                }
            }

            SECTION("reverse iterator")
            {
                SECTION("++i/--i")
                {
                    auto expect = getRandomValueContainer();
                    auto actual = copyContainerToList(expect);

                    auto actualIt = actual.rbegin();
                    auto expectIt = expect.rbegin();
                    while (expectIt < expect.rend())
                    {
                        if (expectIt < expect.rbegin())
                        {
                            ++expectIt;
                            ++actualIt;
                        }

                        if (expectIt > --expect.rbegin() && expectIt < expect.rend())
                            CHECK(*actualIt == *expectIt);

                        if (rand() % 3) // times: ++ > --
                        {
                            auto temp = expectIt;
                            if (++temp < expect.rend())   // is not lastest
                                CHECK(*(++actualIt) == *(++expectIt));
                            else
                            {
                                ++actualIt;
                                ++expectIt;
                                break;
                            }
                        }
                        else if (expectIt > expect.rbegin())
                            CHECK(*(--actualIt) == *(--expectIt));

                        if (expectIt > --expect.rbegin() && expectIt < expect.rend())
                            CHECK(*actualIt == *expectIt);
                    }
                }

                SECTION("i++/i--")
                {
                    auto expect = getRandomValueContainer();
                    auto actual = copyContainerToList(expect);

                    auto actualIt = actual.rbegin();
                    auto expectIt = expect.rbegin();
                    while (expectIt < expect.rend())
                    {
                        if (expectIt < expect.rbegin())
                        {
                            ++expectIt;
                            ++actualIt;
                        }

                        if (expectIt > --expect.rbegin() && expectIt < expect.rend())
                            CHECK(*actualIt == *expectIt);

                        if (rand() % 3) // times: ++ > --
                            CHECK(*(actualIt++) == *(expectIt++));
                        else if (expectIt > expect.rbegin())
                            CHECK(*(actualIt--) == *(expectIt--));

                        if (expectIt > --expect.rbegin() && expectIt < expect.rend())
                            CHECK(*actualIt == *expectIt);
                    }
                }
            }
        }

        SECTION("random move (i-- more than i++) rely on [push_back]")
        {
            SECTION("iterator")
            {
                SECTION("++i/--i rely on [push_back]")
                {
                    auto expect = getRandomValueContainer();
                    auto actual = copyContainerToList(expect);

                    auto actualIt = --actual.end();
                    auto expectIt = --expect.end();
                    while (expectIt > expect.begin())
                    {
                        if (expectIt >= expect.end())
                        {
                            --expectIt;
                            --actualIt;
                        }

                        if (expectIt > --expect.begin() && expectIt < expect.end())
                            CHECK(*actualIt == *expectIt);

                        if (!(rand() % 3)) // times: ++ < --
                        {
                            auto temp = expectIt;
                            if (++temp < expect.end())
                                CHECK(*(++actualIt) == *(++expectIt));
                            else
                            {
                                ++actualIt;
                                ++expectIt;
                                break;
                            }
                        }
                        else if (expectIt > expect.begin())
                            CHECK(*(--actualIt) == *(--expectIt));

                        if (expectIt > --expect.begin() && expectIt < expect.end())
                            CHECK(*actualIt == *expectIt);
                    }
                }

                SECTION("i++/i-- rely on [push_back]")
                {
                    auto expect = getRandomValueContainer();
                    auto actual = copyContainerToList(expect);

                    auto actualIt = --actual.end();
                    auto expectIt = --expect.end();
                    while (expectIt > expect.begin())
                    {
                        if (expectIt >= expect.end())
                        {
                            --expectIt;
                            --actualIt;
                        }

                        if (expectIt > --expect.begin() && expectIt < expect.end())
                            CHECK(*actualIt == *expectIt);

                        if (!(rand() % 3)) // times: ++ < --
                            CHECK(*actualIt++ == *expectIt++);
                        else if (expectIt > expect.begin())
                            CHECK(*actualIt-- == *expectIt--);

                        if (expectIt > --expect.begin() && expectIt < expect.end())
                            CHECK(*actualIt == *expectIt);
                    }
                }
            }

            SECTION("reverse iterator")
            {
                SECTION("++i/--i rely on [push_back]")
                {
                    auto expect = getRandomValueContainer();
                    auto actual = copyContainerToList(expect);

                    auto actualIt = actual.rbegin();
                    auto expectIt = expect.rbegin();
                    while (expectIt > expect.rbegin())
                    {
                        if (expectIt >= expect.rend())
                        {
                            --expectIt;
                            --actualIt;
                        }
                        if (expectIt > --expect.rbegin() && expectIt < expect.rend())
                            CHECK(*actualIt == *expectIt);

                        if (!(rand() % 3)) // times: ++ < --
                        {
                            auto expectItTemp = expectIt;
                            if (++expectItTemp < expect.rend())
                                CHECK(*(++actualIt) == *(++expectIt));
                            else
                            {
                                ++actualIt;
                                ++expectIt;
                                break;
                            }
                        }
                        else if (expectIt > expect.rbegin())
                            CHECK(*(--actualIt) == *(--expectIt));

                        if (expectIt > --expect.rbegin() && expectIt < expect.rend())
                            CHECK(*actualIt == *expectIt);
                    }
                }

                SECTION("i++/i-- rely on [push_back]")
                {
                    auto expect = getRandomValueContainer();
                    auto actual = copyContainerToList(expect);

                    auto actualIt = actual.rbegin();
                    auto expectIt = expect.rbegin();
                    while (expectIt > expect.rbegin())
                    {
                        if (expectIt >= expect.rend())
                        {
                            --expectIt;
                            --actualIt;
                        }

                        if (expectIt > --expect.rbegin() && expectIt < expect.rend())
                            CHECK(*actualIt == *expectIt);

                        if (!(rand() % 3)) // times: ++ < --
                            CHECK(*(actualIt++) == *(expectIt++));
                        else if (expectIt > expect.rbegin())
                            CHECK(*(actualIt--) == *(expectIt--));

                        if (expectIt > --expect.rbegin() && expectIt < expect.rend())
                            CHECK(*actualIt == *expectIt);
                    }
                }
            }
        }

        SECTION("[reverse iterator: base] rely on [++/--]")
        {
            auto expect = getRandomValueContainer();
            XorLinkedList<int> actual = copyContainerToList(expect);
            std::vector<int>::reverse_iterator expectReverseBegin(expect.begin());
            XorLinkedList<int>::const_reverse_iterator actualReverseBegin(actual.begin());
            auto expectBaseBegin = expectReverseBegin.base();
            auto actualBaseBegin = actualReverseBegin.base();

            while (expectBaseBegin != expect.end())
            {
                CHECK(*expectBaseBegin == *actualBaseBegin);
                ++expectBaseBegin;
                ++actualBaseBegin;
            }
        }
    }

    SECTION("empty list")
    {
        XorLinkedList<int> actual;
        actual.clear();

        CHECK_THROWS(actual.front());
        CHECK_THROWS(actual.back());
        CHECK_THROWS(actual.pop_front());
        CHECK_THROWS(actual.pop_back());
        CHECK(actual.size() == 0);
        CHECK(actual.empty());
    }

    SECTION("[insert] rely on [op/begin/end/size/push_back/clear]")
    {
        std::list<int> expect;
        XorLinkedList<int> actual;
        std::list<int>::iterator expectReturnPos;
        XorLinkedList<int>::iterator actualReturnPos;
        int randomValue;
        size_t sz;
        auto ilist = getRandomValueContainer(SmallRandomSize);

        SECTION("insert(const_iterator, const value_type &)")
        {
            SECTION("to empty")
            {
                expect.clear();
                actual.clear();

                randomValue = rand();

                expectReturnPos = expect.insert(expect.end(), randomValue);
                actualReturnPos = actual.insert(actual.end(), randomValue);

                CHECK(expectReturnPos == expect.begin());
                CHECK(actualReturnPos == actual.begin());
                isSame(expect, actual);
            }

            SECTION("before begin")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                randomValue = rand();

                expectReturnPos = expect.insert(expect.begin(), randomValue);
                actualReturnPos = actual.insert(actual.begin(), randomValue);

                CHECK(expectReturnPos == expect.begin());
                CHECK(actualReturnPos == actual.begin());
                isSame(expect, actual);
            }

            SECTION("before end")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                randomValue = rand();

                expectReturnPos = expect.insert(expect.end(), randomValue);
                actualReturnPos = actual.insert(actual.end(), randomValue);

                CHECK(expectReturnPos == --expect.end());
                CHECK(actualReturnPos == --actual.end());
                isSame(expect, actual);
            }

            SECTION("between of begin and end")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                randomValue = rand();

                expectReturnPos = expect.insert(++expect.begin(), randomValue);
                actualReturnPos = actual.insert(++actual.begin(), randomValue);

                CHECK(expectReturnPos == ++expect.begin());
                CHECK(actualReturnPos == ++actual.begin());
                isSame(expect, actual);
            }
        }

        SECTION("insert(const_iterator, value_type &&)")
        {
            SECTION("to empty")
            {
                expect.clear();
                actual.clear();

                randomValue = rand();

                expectReturnPos = expect.insert(expect.end(), std::move(randomValue));
                actualReturnPos = actual.insert(actual.end(), std::move(randomValue));

                CHECK(expectReturnPos == expect.begin());
                CHECK(actualReturnPos == actual.begin());
                isSame(expect, actual);
            }

            SECTION("before begin")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                randomValue = rand();

                expectReturnPos = expect.insert(expect.begin(), std::move(randomValue));
                actualReturnPos = actual.insert(actual.begin(), std::move(randomValue));

                CHECK(expectReturnPos == expect.begin());
                CHECK(actualReturnPos == actual.begin());
                isSame(expect, actual);
            }

            SECTION("before end")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                randomValue = rand();

                expectReturnPos = expect.insert(expect.end(), std::move(randomValue));
                actualReturnPos = actual.insert(actual.end(), std::move(randomValue));

                CHECK(expectReturnPos == --expect.end());
                CHECK(actualReturnPos == --actual.end());
                isSame(expect, actual);
            }

            SECTION("between of begin and end")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                randomValue = rand();

                expectReturnPos = expect.insert(++expect.begin(), std::move(randomValue));
                actualReturnPos = actual.insert(++actual.begin(), std::move(randomValue));

                CHECK(expectReturnPos == ++expect.begin());
                CHECK(actualReturnPos == ++actual.begin());
                isSame(expect, actual);
            }
        }

        SECTION("insert(const_iterator, size_type, const value_type &)")
        {
            SECTION("to empty")
            {
                expect.clear();
                actual.clear();

                SECTION("size is 0")
                {
                    randomValue = rand();
                    sz = 0;

                    expectReturnPos = expect.insert(expect.end(), sz, randomValue);
                    actualReturnPos = actual.insert(actual.end(), sz, randomValue);

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }

                randomValue = rand();
                sz = rand() % 10 + SmallRandomSize;

                expectReturnPos = expect.insert(expect.end(), sz, randomValue);
                actualReturnPos = actual.insert(actual.end(), sz, randomValue);

                auto tempe = expect.end();
                auto tempa = actual.end();
                ++sz;
                while (--sz)
                {
                    --tempe;
                    --tempa;
                }
                CHECK(expectReturnPos == tempe);
                CHECK(actualReturnPos == tempa);
                isSame(expect, actual);
            }

            SECTION("before begin")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                SECTION("size is 0")
                {
                    randomValue = rand();
                    sz = 0;

                    expectReturnPos = expect.insert(expect.begin(), sz, randomValue);
                    actualReturnPos = actual.insert(actual.begin(), sz, randomValue);

                    CHECK(expectReturnPos == expect.begin());
                    CHECK(actualReturnPos == actual.begin());
                    isSame(expect, actual);
                }

                randomValue = rand();
                sz = rand() % 10 + SmallRandomSize;

                expectReturnPos = expect.insert(expect.begin(), sz, randomValue);
                actualReturnPos = actual.insert(actual.begin(), sz, randomValue);

                CHECK(expectReturnPos == expect.begin());
                CHECK(actualReturnPos == actual.begin());
                isSame(expect, actual);
            }

            SECTION("before end")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                SECTION("size is 0")
                {
                    randomValue = rand();
                    sz = 0;

                    expectReturnPos = expect.insert(expect.end(), sz, randomValue);
                    actualReturnPos = actual.insert(actual.end(), sz, randomValue);

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }

                randomValue = rand();
                sz = rand() % 10 + SmallRandomSize;

                expectReturnPos = expect.insert(expect.end(), sz, randomValue);
                actualReturnPos = actual.insert(actual.end(), sz, randomValue);

                auto tempe = expect.end();
                auto tempa = actual.end();
                ++sz;
                while (--sz)
                {
                    --tempe;
                    --tempa;
                }
                CHECK(expectReturnPos == tempe);
                CHECK(actualReturnPos == tempa);
                isSame(expect, actual);
            }

            SECTION("between of begin and end")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                SECTION("size is 0")
                {
                    randomValue = rand();
                    sz = 0;

                    expectReturnPos = expect.insert(++expect.begin(), sz, randomValue);
                    actualReturnPos = actual.insert(++actual.begin(), sz, randomValue);

                    CHECK(expectReturnPos == ++expect.begin());
                    CHECK(actualReturnPos == ++actual.begin());
                    isSame(expect, actual);
                }

                randomValue = rand();
                sz = rand() % 10 + SmallRandomSize;

                expectReturnPos = expect.insert(++expect.begin(), sz, randomValue);
                actualReturnPos = actual.insert(++actual.begin(), sz, randomValue);

                CHECK(expectReturnPos == ++expect.begin());
                CHECK(actualReturnPos == ++actual.begin());
                isSame(expect, actual);
            }

            SECTION("size is 1")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                randomValue = rand();
                sz = 1;

                expectReturnPos = expect.insert(++expect.begin(), sz, randomValue);
                actualReturnPos = actual.insert(++actual.begin(), sz, randomValue);

                CHECK(expectReturnPos == ++expect.begin());
                CHECK(actualReturnPos == ++actual.begin());
                isSame(expect, actual);
            }
        }

        SECTION("insert(const_iterator, initilizer_list)")
        {
            SECTION("to empty")
            {
                expect.clear();
                actual.clear();

                SECTION("initializer_list is empty")
                {
                    std::initializer_list<int> ilist = {};

                    expectReturnPos = expect.insert(expect.end(), ilist);
                    actualReturnPos = actual.insert(actual.end(), ilist);

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }

                auto ilist = {rand(), rand(), rand(), rand(), rand()};

                expectReturnPos = expect.insert(expect.end(), ilist);
                actualReturnPos = actual.insert(actual.end(), ilist);

                CHECK(expectReturnPos == expect.begin());
                CHECK(actualReturnPos == actual.begin());
                isSame(expect, actual);
            }

            SECTION("before begin")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                SECTION("initializer_list is empty")
                {
                    std::initializer_list<int> ilist = {};

                    expectReturnPos = expect.insert(expect.begin(), ilist);
                    actualReturnPos = actual.insert(actual.begin(), ilist);

                    CHECK(expectReturnPos == expect.begin());
                    CHECK(actualReturnPos == actual.begin());
                    isSame(expect, actual);
                }

                auto ilist = {rand(), rand(), rand(), rand(), rand()};

                expectReturnPos = expect.insert(expect.begin(), ilist);
                actualReturnPos = actual.insert(actual.begin(), ilist);

                CHECK(expectReturnPos == expect.begin());
                CHECK(actualReturnPos == actual.begin());
                isSame(expect, actual);
            }

            SECTION("before end")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                SECTION("initializer_list is empty")
                {
                    std::initializer_list<int> ilist = {};

                    expectReturnPos = expect.insert(expect.end(), ilist);
                    actualReturnPos = actual.insert(actual.end(), ilist);

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }

                auto ilist = {rand(), rand(), rand(), rand(), rand()};

                expectReturnPos = expect.insert(expect.end(), ilist);
                actualReturnPos = actual.insert(actual.end(), ilist);

                CHECK(expectReturnPos == ++expect.begin());
                CHECK(actualReturnPos == ++actual.begin());
                isSame(expect, actual);
            }

            SECTION("between of begin and end")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                SECTION("initializer_list is empty")
                {
                    std::initializer_list<int> ilist = {};

                    expectReturnPos = expect.insert(++expect.begin(), ilist);
                    actualReturnPos = actual.insert(++actual.begin(), ilist);

                    CHECK(expectReturnPos == ++expect.begin());
                    CHECK(actualReturnPos == ++actual.begin());
                    isSame(expect, actual);
                }

                auto ilist = {rand(), rand(), rand(), rand(), rand()};

                expectReturnPos = expect.insert(++expect.begin(), ilist);
                actualReturnPos = actual.insert(++actual.begin(), ilist);

                CHECK(expectReturnPos == ++expect.begin());
                CHECK(actualReturnPos == ++actual.begin());
                isSame(expect, actual);
            }

            SECTION("size of initializer is 1")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                auto ilist = {rand()};

                expectReturnPos = expect.insert(++expect.begin(), ilist);
                actualReturnPos = actual.insert(++actual.begin(), ilist);

                CHECK(expectReturnPos == ++expect.begin());
                CHECK(actualReturnPos == ++actual.begin());
                isSame(expect, actual);
            }
        }

        SECTION("insert(const_iterator, iterator, iterator)")
        {
            SECTION("to empty")
            {
                expect.clear();
                actual.clear();

                SECTION("container is empty")
                {
                    std::initializer_list<int> ilist = {};

                    expectReturnPos = expect.insert(expect.end(), ilist);
                    actualReturnPos = actual.insert(actual.end(), ilist);

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }

                ilist = getRandomValueContainer(SmallRandomSize);

                expectReturnPos = expect.insert(expect.end(), ilist.begin(), ilist.end());
                actualReturnPos = actual.insert(actual.end(), ilist.begin(), ilist.end());

                CHECK(expectReturnPos == expect.begin());
                CHECK(actualReturnPos == actual.begin());
                isSame(expect, actual);
            }

            SECTION("before begin")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                SECTION("container is empty")
                {
                    std::initializer_list<int> ilist = {};

                    expectReturnPos = expect.insert(expect.begin(), ilist);
                    actualReturnPos = actual.insert(actual.begin(), ilist);

                    CHECK(expectReturnPos == expect.begin());
                    CHECK(actualReturnPos == actual.begin());
                    isSame(expect, actual);
                }

                ilist = getRandomValueContainer(SmallRandomSize);

                expectReturnPos = expect.insert(expect.begin(), ilist.begin(), ilist.end());
                actualReturnPos = actual.insert(actual.begin(), ilist.begin(), ilist.end());

                CHECK(expectReturnPos == expect.begin());
                CHECK(actualReturnPos == actual.begin());
                isSame(expect, actual);
            }

            SECTION("before end")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                SECTION("container is empty")
                {
                    std::initializer_list<int> ilist = {};

                    expectReturnPos = expect.insert(expect.end(), ilist);
                    actualReturnPos = actual.insert(actual.end(), ilist);

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }

                ilist = getRandomValueContainer(SmallRandomSize);

                expectReturnPos = expect.insert(expect.end(), ilist.begin(), ilist.end());
                actualReturnPos = actual.insert(actual.end(), ilist.begin(), ilist.end());

                CHECK(expectReturnPos == ++expect.begin());
                CHECK(actualReturnPos == ++actual.begin());
                isSame(expect, actual);
            }

            SECTION("between of begin and end")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                SECTION("container is empty")
                {
                    std::initializer_list<int> ilist = {};

                    expectReturnPos = expect.insert(++expect.begin(), ilist);
                    actualReturnPos = actual.insert(++actual.begin(), ilist);

                    CHECK(expectReturnPos == ++expect.begin());
                    CHECK(actualReturnPos == ++actual.end());
                    isSame(expect, actual);
                }

                ilist = getRandomValueContainer(SmallRandomSize);

                expectReturnPos = expect.insert(++expect.begin(), ilist.begin(), ilist.end());
                actualReturnPos = actual.insert(++actual.begin(), ilist.begin(), ilist.end());

                CHECK(expectReturnPos == ++expect.begin());
                CHECK(actualReturnPos == ++actual.begin());
                isSame(expect, actual);
            }

            SECTION("size of iterator is 1")
            {
                expect.clear();
                actual.clear();
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                ilist = {1};

                expectReturnPos = expect.insert(++expect.begin(), ilist.begin(), ilist.end());
                actualReturnPos = actual.insert(++actual.begin(), ilist.begin(), ilist.end());

                CHECK(expectReturnPos == ++expect.begin());
                CHECK(actualReturnPos == ++actual.begin());
                isSame(expect, actual);
            }
        }
    }

    SECTION("[erase] rely on [...]")
    {
        // todo
    }
}

TEST_CASE("operations")
{
    SECTION("[reverse] rely on [empty/size/begin/end/front/back/push_back/push_front]")
    {
        SECTION("empty")
        {
            XorLinkedList<int> actual;
            CHECK(actual.empty());
            CHECK(actual.size() == 0);
            CHECK(actual.begin() == actual.end());

            actual.reverse();
            CHECK(actual.empty());
            CHECK(actual.size() == 0);
            CHECK(actual.begin() == actual.end());
        }

        SECTION("one nodes")
        {
            XorLinkedList<int> actual;
            actual.push_back(1);
            CHECK(actual.front() == 1);
            CHECK(actual.back() == 1);
            CHECK(actual.size() == 1);
            CHECK_FALSE(actual.empty());

            actual.reverse();
            CHECK(actual.front() == 1);
            CHECK(actual.back() == 1);
            CHECK(actual.size() == 1);
            CHECK_FALSE(actual.empty());

            actual.pop_back();
            CHECK_THROWS(actual.front());
            CHECK_THROWS(actual.back());
            CHECK(actual.size() == 0);
            CHECK(actual.empty());
        }

        SECTION("two nodes")
        {
            XorLinkedList<int> actual;
            actual.push_back(1);
            actual.push_back(2);
            CHECK(actual.front() == 1);
            CHECK(actual.back() == 2);
            CHECK(actual.size() == 2);
            CHECK_FALSE(actual.empty());

            actual.reverse();
            CHECK(actual.front() == 2);
            CHECK(actual.back() == 1);
            CHECK(actual.size() == 2);
            CHECK_FALSE(actual.empty());

            actual.pop_back();
            CHECK(actual.front() == 2);
            CHECK(actual.back() == 2);
            CHECK(actual.size() == 1);
            CHECK_FALSE(actual.empty());

            actual.pop_back();
            CHECK_THROWS(actual.front());
            CHECK_THROWS(actual.back());
            CHECK(actual.size() == 0);
            CHECK(actual.empty());
        }

        SECTION("three nodes")
        {
            XorLinkedList<int> actual;
            actual.push_back(1);
            actual.push_back(2);
            actual.push_back(3);
            CHECK(actual.front() == 1);
            CHECK(actual.back() == 3);
            CHECK(actual.size() == 3);
            CHECK_FALSE(actual.empty());

            actual.reverse();
            CHECK(actual.front() == 3);
            CHECK(actual.back() == 1);
            CHECK(actual.size() == 3);
            CHECK_FALSE(actual.empty());

            actual.pop_back();
            CHECK(actual.front() == 3);
            CHECK(actual.back() == 2);
            CHECK(actual.size() == 2);
            CHECK_FALSE(actual.empty());

            actual.pop_back();
            CHECK(actual.front() == 3);
            CHECK(actual.back() == 3);
            CHECK(actual.size() == 1);
            CHECK_FALSE(actual.empty());

            actual.pop_back();
            CHECK_THROWS(actual.front());
            CHECK_THROWS(actual.back());
            CHECK(actual.size() == 0);
            CHECK(actual.empty());
        }

        SECTION("random nodes")
        {
            auto container = getRandomValueContainer();

            std::list<int> expect;
            XorLinkedList<int> actual;
            while (!container.empty())
            {
                auto v = container.back();
                if (rand() % 2)
                {
                    if (rand() % 2)
                    {
                        actual.push_back(v);
                        expect.push_back(v);
                    }
                    else
                    {
                        actual.push_front(v);
                        expect.push_front(v);
                    }
                }
                else
                {
                    if (rand() % 2)
                    {
                        if (!expect.empty())
                        {
                            actual.pop_back();
                            expect.pop_back();
                        }
                    }
                    else if (!expect.empty())
                    {
                        actual.pop_front();
                        expect.pop_front();
                    }
                }
                if (!expect.empty())
                {
                    actual.reverse();
                    reverse(actual.begin(), actual.end());
                    actual.reverse();
                    reverse(actual.begin(), actual.end());
                    actual.reverse();
                    reverse(expect.begin(), expect.end());
                }
                CHECK(actual.size() == expect.size());
                CHECK((expect.size() ^ actual.empty()));
                if (!expect.empty())
                {
                    CHECK(expect.front() == actual.front());
                    CHECK(expect.back() == actual.back());
                }
                container.pop_back();
            }
        }
    }
}

TEST_CASE("others")
{
    SECTION("random nodes")
    {
        // todo: test more functions insert/find/unique/sort/erase

        auto container = getRandomValueContainer();

        XorLinkedList<int> actual;
        int expectSize = 1;
        expectListContainer expect;
        expect.push_front(container.front());
        actual.push_front(container.front());
        for_each(++container.begin(), container.end(), [&](int v)
        {
            if (rand() % 2)
            {
                if (rand() % 2)
                {
                    actual.push_back(v);
                    expect.push_back(v);
                }
                else
                {
                    actual.push_front(v);
                    expect.push_front(v);
                }
                ++expectSize;
            }
            else
            {
                if (rand() % 2)
                {
                    if (expectSize == 0)
                        CHECK_THROWS(actual.pop_back());
                    else
                    {
                        CHECK_NOTHROW(actual.pop_back());
                        CHECK_NOTHROW(expect.pop_back());
                        --expectSize;
                    }
                }
                else
                {
                    if (expectSize == 0)
                        CHECK_THROWS(actual.pop_front());
                    else
                    {
                        CHECK_NOTHROW(actual.pop_front());
                        CHECK_NOTHROW(expect.pop_front());
                        --expectSize;
                    }
                }
            }
            CHECK(actual.size() == expectSize);
            CHECK((expectSize ^ actual.empty()));
            if (!expect.empty())
            {
                CHECK(expect.front() == actual.front());
                CHECK(expect.back() == actual.back());
            }
        });
    }

    SECTION("efficiency")
    {
        // todo
    }
}

#endif // XOR_LINKED_LIST_TEST_CPP
