/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * test lists for std::list-like
 */

#define CATCH_CONFIG_MAIN
#ifndef XOR_LINKED_LIST_TEST_CPP
#define XOR_LINKED_LIST_TEST_CPP

#include "../../../../test/c++/catch.hpp"
#include "../../src/list/xor_linked_list/xor_linked_list.cpp"
#include <iostream>
#include <list>
#include <vector>

using vectorContainer = std::vector<int>;
using expectListContainer = std::list<int>;
using actualListContainer = XorLinkedList<int>;
static size_t RandomSize;
static size_t SmallRandomSize;

TEST_CASE("init")
{
    srand(static_cast<unsigned int>(clock()));

    RandomSize = 100000 + rand() % 2;
    SmallRandomSize = RandomSize / rand() % 100 + 50;
}

vectorContainer getRandomValueContainer(size_t sz = RandomSize)
{
    // init
    vectorContainer container(sz);
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
}

actualListContainer copyContainerToList(const vectorContainer &container)
{
    actualListContainer actual;
    std::for_each(container.begin(), container.end(), [&](int v)
    {
        actual.push_back(v);
    });

    return actual;
}

void copyRandomPartContainerToLists(const vectorContainer &container,
                                    expectListContainer &expect,
                                    actualListContainer &actual)
{
    std::for_each(container.begin(), container.end(), [&](int v)
    {
        if (rand() % 2)
        {
            expect.push_back(v);
            actual.push_back(v);
        }
    });
    auto begin = container.begin();
    while (expect.size() < 10)
    {
        expect.push_back(*begin);
        actual.push_back(*begin++);
    }
}

void isSame(expectListContainer expect, actualListContainer actual)
{
    CHECK(expect.size() == actual.size());
    CHECK(expect.empty() == actual.empty());

    auto expectIt = expect.begin();
    auto actualIt = actual.begin();

    while (expectIt != expect.end())
        CHECK(*expectIt++ == *actualIt++);
}

TEST_CASE("-ctors converts and its types")
{
    expectListContainer expect;
    actualListContainer actual;
    const expectListContainer cExpect;
    const actualListContainer cActual;

    SECTION("iterator")
    {
        SECTION("begin")
        {
            expectListContainer::iterator expectIt1(expect.begin());
            expectListContainer::const_iterator expectIt2(expect.begin());
            expectListContainer::reverse_iterator expectIt3(expect.begin());
            expectListContainer::const_reverse_iterator expectIt4(expect.begin());

            expectListContainer::const_iterator expectCIt2(expect.cbegin());
            expectListContainer::const_reverse_iterator expectCIt4(expect.cbegin());

            expectListContainer::reverse_iterator expectRIt3(expect.rbegin());
            expectListContainer::const_reverse_iterator expectRIt4(expect.rbegin());

            expectListContainer::const_reverse_iterator expectCRIt4(expect.crbegin());

            actualListContainer::iterator actualIt1(actual.begin());
            actualListContainer::const_iterator actualIt2(actual.begin());
            actualListContainer::reverse_iterator actualIt3(actual.begin());
            actualListContainer::const_reverse_iterator actualIt4(actual.begin());

            actualListContainer::const_iterator actualCIt2(actual.cbegin());
            actualListContainer::const_reverse_iterator actualCIt4(actual.cbegin());

            actualListContainer::reverse_iterator actualRIt3(actual.rbegin());
            actualListContainer::const_reverse_iterator actualRIt4(actual.rbegin());

            actualListContainer::const_reverse_iterator actualCRIt4(actual.crbegin());
        }

        SECTION("begin errors")
        {
            // expectListContainer::iterator expectCIt1(expect.cbegin());
            // expectListContainer::reverse_iterator expectCIt3(expect.cbegin());
            //
            // expectListContainer::iterator expectRIt1(expect.rbegin());
            // expectListContainer::const_iterator expectRIt2(expect.rbegin());
            //
            // expectListContainer::iterator expectCRIt1(expect.crbegin());
            // expectListContainer::const_iterator expectCRIt2(expect.crbegin());
            // expectListContainer::reverse_iterator expectCRIt3(expect.crbegin());

            // actualListContainer::iterator actualCIt1(actual.cbegin());
            // actualListContainer::reverse_iterator actualCIt3(actual.cbegin());

            // actualListContainer::iterator actualRIt1(actual.rbegin());
            // actualListContainer::const_iterator actualRIt2(actual.rbegin());

            // actualListContainer::iterator actualCRIt1(actual.crbegin());
            // actualListContainer::const_iterator actualCRIt2(actual.crbegin());
            // actualListContainer::reverse_iterator actualCRIt3(actual.crbegin());
        }

        SECTION("end")
        {
            expectListContainer::iterator expectIt1(expect.end());
            expectListContainer::const_iterator expectIt2(expect.end());
            expectListContainer::reverse_iterator expectIt3(expect.end());
            expectListContainer::const_reverse_iterator expectIt4(expect.end());

            expectListContainer::const_iterator expectCIt2(expect.cend());
            expectListContainer::const_reverse_iterator expectCIt4(expect.cend());

            expectListContainer::reverse_iterator expectRIt3(expect.rend());
            expectListContainer::const_reverse_iterator expectRIt4(expect.rend());

            expectListContainer::const_reverse_iterator expectCRIt4(expect.crend());

            actualListContainer::iterator actualIt1(actual.end());
            actualListContainer::const_iterator actualIt2(actual.end());
            actualListContainer::reverse_iterator actualIt3(actual.end());
            actualListContainer::const_reverse_iterator actualIt4(actual.end());

            actualListContainer::const_iterator actualCIt2(actual.cend());
            actualListContainer::const_reverse_iterator actualCIt4(actual.cend());

            actualListContainer::reverse_iterator actualRIt3(actual.rend());
            actualListContainer::const_reverse_iterator actualRIt4(actual.rend());

            actualListContainer::const_reverse_iterator actualCRIt4(actual.crend());
        }

        SECTION("end error")
        {
            // expectListContainer::iterator expectCIt1(expect.cend());
            // expectListContainer::reverse_iterator expectCIt3(expect.cend());
            //
            // expectListContainer::iterator expectRIt1(expect.rend());
            // expectListContainer::const_iterator expectRIt2(expect.rend());
            //
            // expectListContainer::iterator expectCRIt1(expect.crend());
            // expectListContainer::const_iterator expectCRIt2(expect.crend());
            // expectListContainer::reverse_iterator expectCRIt3(expect.crend());

            // actualListContainer::iterator actualCIt1(actual.cend());
            // actualListContainer::reverse_iterator actualCIt3(actual.cend());
            //
            // actualListContainer::iterator actualRIt1(actual.rend());
            // actualListContainer::const_iterator actualRIt2(actual.rend());
            //
            // actualListContainer::iterator actualCRIt1(actual.crend());
            // actualListContainer::const_iterator actualCRIt2(actual.crend());
            // actualListContainer::reverse_iterator actualCRIt3(actual.crend());
        }

        SECTION("const begin")
        {
            const expectListContainer::const_iterator expectIt2(cExpect.begin());
            const expectListContainer::const_reverse_iterator expectIt4(cExpect.begin());

            const expectListContainer::const_iterator expectCIt2(cExpect.cbegin());
            const expectListContainer::const_reverse_iterator expectCIt4(cExpect.cbegin());

            const expectListContainer::const_reverse_iterator expectRIt4(cExpect.rbegin());

            const expectListContainer::const_reverse_iterator expectCRIt4(cExpect.crbegin());

            const actualListContainer::const_iterator actualIt2(cActual.begin());
            const actualListContainer::const_reverse_iterator actualIt4(cActual.begin());

            const actualListContainer::const_iterator actualCIt2(cActual.cbegin());
            const actualListContainer::const_reverse_iterator actualCIt4(cActual.cbegin());

            const actualListContainer::const_reverse_iterator actualRIt4(cActual.rbegin());

            const actualListContainer::const_reverse_iterator actualCRIt4(cActual.crbegin());
        }

        SECTION("const begin errors")
        {
            // const expectListContainer::iterator expectIt1(cExpect.begin());
            // const expectListContainer::reverse_iterator expectIt3(cExpect.begin());
            //
            // const expectListContainer::iterator expectCIt1(cExpect.cbegin());
            // const expectListContainer::reverse_iterator expectCIt3(cExpect.cbegin());
            //
            // const expectListContainer::iterator expectRIt1(cExpect.rbegin());
            // const expectListContainer::const_iterator expectRIt2(cExpect.rbegin());
            // const expectListContainer::reverse_iterator expectRIt3(cExpect.rbegin());
            //
            // const expectListContainer::iterator expectCRIt1(cExpect.crbegin());
            // const expectListContainer::const_iterator expectCRIt2(cExpect.crbegin());
            // const expectListContainer::reverse_iterator expectCRIt3(cExpect.crbegin());

            // const actualListContainer::iterator actualIt1(cActual.begin());
            // const actualListContainer::reverse_iterator actualIt3(cActual.begin());
            //
            // const actualListContainer::iterator actualCIt1(cActual.cbegin());
            // const actualListContainer::reverse_iterator actualCIt3(cActual.cbegin());
            //
            // const actualListContainer::iterator actualRIt1(cActual.rbegin());
            // const actualListContainer::const_iterator actualRIt2(cActual.rbegin());
            // const actualListContainer::reverse_iterator actualRIt3(cActual.rbegin());
            //
            // const actualListContainer::iterator actualCRIt1(cActual.crbegin());
            // const actualListContainer::const_iterator actualCRIt2(cActual.crbegin());
            // const actualListContainer::reverse_iterator actualCRIt3(cActual.crbegin());
        }

        SECTION("const end")
        {
            const expectListContainer::const_iterator expectIt2(cExpect.end());
            const expectListContainer::const_reverse_iterator expectIt4(cExpect.end());

            const expectListContainer::const_iterator expectCIt2(cExpect.cend());
            const expectListContainer::const_reverse_iterator expectCIt4(cExpect.cend());

            const expectListContainer::const_reverse_iterator expectRIt4(cExpect.rend());

            const expectListContainer::const_reverse_iterator expectCRIt4(cExpect.crend());

            const actualListContainer::const_iterator actualIt2(cActual.end());
            const actualListContainer::const_reverse_iterator actualIt4(cActual.end());

            const actualListContainer::const_iterator actualCIt2(cActual.cend());
            const actualListContainer::const_reverse_iterator actualCIt4(cActual.cend());

            const actualListContainer::const_reverse_iterator actualRIt4(cActual.rend());

            const actualListContainer::const_reverse_iterator actualCRIt4(cActual.crend());
        }

        SECTION("const end error")
        {
            // const expectListContainer::iterator expectIt1(cExpect.end());
            // const expectListContainer::reverse_iterator expectIt3(cExpect.end());
            //
            // const expectListContainer::iterator expectCIt1(cExpect.cend());
            // const expectListContainer::reverse_iterator expectCIt3(cExpect.cend());
            //
            // const expectListContainer::iterator expectRIt1(cExpect.rend());
            // const expectListContainer::const_iterator expectRIt2(cExpect.rend());
            // const expectListContainer::reverse_iterator expectRIt3(cExpect.rend());
            //
            // const expectListContainer::iterator expectCRIt1(cExpect.crend());
            // const expectListContainer::const_iterator expectCRIt2(cExpect.crend());
            // const expectListContainer::reverse_iterator expectCRIt3(cExpect.crend());

            // const actualListContainer::iterator actualIt1(cActual.end());
            // const actualListContainer::reverse_iterator actualIt3(cActual.end());
            //
            // const actualListContainer::iterator actualCIt1(cActual.cend());
            // const actualListContainer::reverse_iterator actualCIt3(cActual.cend());
            //
            // const actualListContainer::iterator actualRIt1(cActual.rend());
            // const actualListContainer::const_iterator actualRIt2(cActual.rend());
            // const actualListContainer::reverse_iterator actualRIt3(cActual.rend());
            //
            // const actualListContainer::iterator actualCRIt1(cActual.crend());
            // const actualListContainer::const_iterator actualCRIt2(cActual.crend());
            // const actualListContainer::reverse_iterator actualCRIt3(cActual.crend());
        }
    }

    SECTION("container")
    {
        expectListContainer expect1;
        expectListContainer expect2(expect1);
        expectListContainer expect3{1, 2, 3};

        actualListContainer actual1;
        actualListContainer actual2(actual1);
        actualListContainer actual3{1, 2, 3};
    }
}

TEST_CASE("const semantic")
{
    expectListContainer expect;
    actualListContainer actual;

    const expectListContainer cExpect;
    const actualListContainer cActual;

    using std::is_const;
    SECTION("iterators")
    {
        SECTION("non-const")
        {
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
            CHECK(is_const<decltype(cActual.begin())>() == is_const<decltype(cExpect.begin())>());
            CHECK(is_const<decltype(cActual.begin().operator->())>()
                  == is_const<decltype(cExpect.begin().operator->())>());
            CHECK(is_const<decltype(*cActual.begin())>() == is_const<decltype(*cExpect.begin())>());
            CHECK(is_const<decltype(cActual.end())>() == is_const<decltype(cExpect.end())>());
            CHECK(is_const<decltype(cActual.end().operator->())>()
                  == is_const<decltype(cExpect.end().operator->())>());
            CHECK(is_const<decltype(*cActual.end())>() == is_const<decltype(*cExpect.end())>());

            CHECK(is_const<decltype(cActual.cbegin())>() == is_const<decltype(cExpect.cbegin())>());
            CHECK(is_const<decltype(cActual.cbegin().operator->())>()
                  == is_const<decltype(cExpect.cbegin().operator->())>());
            CHECK(is_const<decltype(*cActual.cbegin())>()
                  == is_const<decltype(*cExpect.cbegin())>());
            CHECK(is_const<decltype(cActual.cend())>() == is_const<decltype(cExpect.cend())>());
            CHECK(is_const<decltype(cActual.cend().operator->())>()
                  == is_const<decltype(cExpect.cend().operator->())>());
            CHECK(is_const<decltype(*cActual.cend())>() == is_const<decltype(*cExpect.cend())>());

            CHECK(is_const<decltype(cActual.rbegin())>() == is_const<decltype(cExpect.rbegin())>());
            CHECK(is_const<decltype(cActual.rbegin().operator->())>()
                  == is_const<decltype(cExpect.rbegin().operator->())>());
            CHECK(is_const<decltype(*cActual.rbegin())>()
                  == is_const<decltype(*cExpect.rbegin())>());
            CHECK(is_const<decltype(cActual.rend())>() == is_const<decltype(cExpect.rend())>());
            CHECK(is_const<decltype(cActual.rend().operator->())>()
                  == is_const<decltype(cExpect.rend().operator->())>());
            CHECK(is_const<decltype(*cActual.rend())>() == is_const<decltype(*cExpect.rend())>());

            CHECK(is_const<decltype(cActual.crbegin())>()
                  == is_const<decltype(cExpect.crbegin())>());
            CHECK(is_const<decltype(cActual.crbegin().operator->())>()
                  == is_const<decltype(cExpect.crbegin().operator->())>());
            CHECK(is_const<decltype(*cActual.crbegin())>()
                  == is_const<decltype(*cExpect.crbegin())>());
            CHECK(is_const<decltype(cActual.crend())>() == is_const<decltype(cExpect.crend())>());
            CHECK(is_const<decltype(cActual.crend().operator->())>()
                  == is_const<decltype(cExpect.crend().operator->())>());
            CHECK(is_const<decltype(*cActual.crend())>() == is_const<decltype(*cExpect.crend())>());

            CHECK(is_const<decltype(cActual.rbegin().base())>()
                  == is_const<decltype(cExpect.rbegin().base())>());
            CHECK(is_const<decltype(cActual.rbegin().base().operator->())>()
                  == is_const<decltype(cExpect.rbegin().base().operator->())>());
            CHECK(is_const<decltype(*cActual.rbegin().base())>()
                  == is_const<decltype(*cExpect.rbegin().base())>());
            CHECK(is_const<decltype(cActual.rend().base())>()
                  == is_const<decltype(cExpect.rend().base())>());
            CHECK(is_const<decltype(cActual.rend().base().operator->())>()
                  == is_const<decltype(cExpect.rend().base().operator->())>());
            CHECK(is_const<decltype(*cActual.rend().base())>()
                  == is_const<decltype(*cExpect.rend().base())>());

            CHECK(is_const<decltype(cActual.crbegin().base())>()
                  == is_const<decltype(cExpect.crbegin().base())>());
            CHECK(is_const<decltype(cActual.crbegin().base().operator->())>()
                  == is_const<decltype(cExpect.crbegin().base().operator->())>());
            CHECK(is_const<decltype(cActual.crend().base())>()
                  == is_const<decltype(cExpect.crend().base())>());
            CHECK(is_const<decltype(*cActual.crbegin().base())>()
                  == is_const<decltype(*cExpect.crbegin().base())>());
            CHECK(is_const<decltype(*cActual.crbegin().base().operator->())>()
                  == is_const<decltype(*cExpect.crbegin().base().operator->())>());
            CHECK(is_const<decltype(*cActual.crend().base())>()
                  == is_const<decltype(*cExpect.crend().base())>());
        }
    }

    SECTION("element access")
    {
        SECTION("non-const")
        {
            CHECK(is_const<decltype(actual.front())>() == is_const<decltype(expect.front())>());
            CHECK(is_const<decltype(actual.back())>() == is_const<decltype(expect.back())>());
        }

        SECTION("const")
        {
            CHECK(is_const<decltype(cActual.front())>() == is_const<decltype(cExpect.front())>());
            CHECK(is_const<decltype(cActual.back())>() == is_const<decltype(cExpect.back())>());
        }
    }
}

TEST_CASE("element access rely on [push]")
{
    actualListContainer actual;

    SECTION("push one node")
    {
        actual.push_back(1);
        CHECK(actual.front() == 1);
        CHECK(actual.back() == 1);
    }

    SECTION("push two nodes")
    {
        actual.push_back(1);
        actual.push_back(2);
        CHECK(actual.front() == 1);
        CHECK(actual.back() == 2);
        actual.push_front(3);
        CHECK(actual.front() == 3);
        CHECK(actual.back() == 2);
    }
}

TEST_CASE("modifiers")
{
    auto randomContainer = getRandomValueContainer();
    auto randomSmallContainer = getRandomValueContainer(SmallRandomSize);
    std::initializer_list<int> randomIlist{rand(), rand(), rand(), rand(), rand()};
    expectListContainer expect;
    actualListContainer actual;
    expectListContainer::iterator expectReturnPos;
    actualListContainer::iterator actualReturnPos;
    int randomValue{};
    size_t sz{};

    SECTION("empty list")
    {
        CHECK_THROWS_AS(actual.front(), std::out_of_range);
        CHECK_THROWS_AS(actual.back(), std::out_of_range);
        CHECK(actual.size() == 0);
        CHECK(actual.empty());
    }

    SECTION("[clear] rely on [push_back]")
    {
        SECTION("while empty")
        {
            actual.clear();
        }

        SECTION("after actions")
        {
            actual.push_back(1);
            actual.push_back(2);
            actual.clear();
            actual.push_back(3);
        }

        SECTION("before destruct")
        {
            actual.push_back(1);
            actual.push_back(2);
            actual.push_back(3);
            actual.clear();
        }

        SECTION("while destruct")
        {
            actual.push_back(1);
            actual.push_back(2);
            actual.push_back(3);
        }
    }

    SECTION("[erase] rely on [push_back/begin/end/op/size]")
    {
        SECTION("erase(const_iterator)")
        {
            SECTION("from empty")
            {
                /*
                 * erase(end()) is undefined, refer to:
                 * http://en.cppreference.com/w/cpp/container/list/erase
                 */
            }

            SECTION("first one")
            {
                SECTION("size is 1")
                {
                    randomValue = rand();
                    expect.push_back(randomValue);
                    actual.push_back(randomValue);

                    expectReturnPos = expect.erase(expect.begin());
                    actualReturnPos = actual.erase(actual.begin());

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }

                SECTION("random size")
                {
                    copyRandomPartContainerToLists(randomContainer, expect, actual);

                    expectReturnPos = expect.erase(expect.begin());
                    actualReturnPos = actual.erase(actual.begin());

                    CHECK(expectReturnPos == expect.begin());
                    CHECK(actualReturnPos == actual.begin());
                    isSame(expect, actual);
                }
            }

            SECTION("last one")
            {
                SECTION("size is 1")
                {
                    randomValue = rand();
                    expect.push_back(randomValue);
                    actual.push_back(randomValue);

                    expectReturnPos = expect.erase(expect.begin());
                    actualReturnPos = actual.erase(actual.begin());

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }

                SECTION("random size")
                {
                    copyRandomPartContainerToLists(randomContainer, expect, actual);

                    expectReturnPos = expect.erase(--expect.end());
                    actualReturnPos = actual.erase(--actual.end());

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }
            }

            SECTION("between of begin and end")
            {
                copyRandomPartContainerToLists(randomContainer, expect, actual);

                expectReturnPos = expect.erase(---- expect.end());
                actualReturnPos = actual.erase(---- actual.end());

                CHECK(expectReturnPos == --expect.end());
                CHECK(actualReturnPos == --actual.end());
                isSame(expect, actual);
            }
        }

        SECTION("erase(const_iterator, const_iterator)")
        {
            SECTION("from empty")
            {
                /*
                 * erase(end(), end()) is undefined, refer to:
                 * http://en.cppreference.com/w/cpp/container/list/erase
                 */
            }

            SECTION("size is 1")
            {
                randomValue = rand();
                expect.push_back(randomValue);
                actual.push_back(randomValue);

                expectReturnPos = expect.erase(expect.begin(), expect.end());
                actualReturnPos = actual.erase(actual.begin(), actual.end());

                CHECK(expectReturnPos == expect.end());
                CHECK(actualReturnPos == actual.end());
                isSame(expect, actual);
            }

            SECTION("random size")
            {
                copyRandomPartContainerToLists(randomContainer, expect, actual);

                SECTION("[begin : end)")
                {
                    expectReturnPos = expect.erase(expect.begin(), ++++++ expect.begin());
                    actualReturnPos = actual.erase(actual.begin(), ++++++ actual.begin());

                    CHECK(expectReturnPos == expect.begin());
                    CHECK(actualReturnPos == actual.begin());
                    isSame(expect, actual);
                }

                SECTION("(begin : end)")
                {
                    expectReturnPos = expect.erase(++++++ expect.begin(), ------ expect.end());
                    actualReturnPos = actual.erase(++++++ actual.begin(), ------ actual.end());

                    CHECK(expectReturnPos == ------ expect.end());
                    CHECK(actualReturnPos == ------ actual.end());
                    isSame(expect, actual);
                }

                SECTION("(begin : end]")
                {
                    expectReturnPos = expect.erase(++++++ expect.begin(), expect.end());
                    actualReturnPos = actual.erase(++++++ actual.begin(), actual.end());

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }
            }
        }
    }

    SECTION("[insert] rely on [op/begin/end/size/push_back/clear]")
    {
        SECTION("insert(const_iterator, const value_type &)")
        {
            SECTION("to empty")
            {
                randomValue = rand();

                expectReturnPos = expect.insert(expect.end(), randomValue);
                actualReturnPos = actual.insert(actual.end(), randomValue);

                CHECK(expectReturnPos == expect.begin());
                CHECK(actualReturnPos == actual.begin());
                isSame(expect, actual);
            }

            SECTION("before begin")
            {
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
                randomValue = rand();

                expectReturnPos = expect.insert(expect.end(), std::move(randomValue));
                actualReturnPos = actual.insert(actual.end(), std::move(randomValue));

                CHECK(expectReturnPos == expect.begin());
                CHECK(actualReturnPos == actual.begin());
                isSame(expect, actual);
            }

            SECTION("before begin")
            {
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
                SECTION("size is 0")
                {
                    randomValue = rand();
                    sz = 0;

                    auto expectReturnPos = expect.insert(expect.end(), sz, randomValue);
                    actualReturnPos = actual.insert(actual.end(), sz, randomValue);

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }

                SECTION("size is non-zero")
                {
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
            }

            SECTION("before begin")
            {
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

                SECTION("size is non-zero")
                {
                    randomValue = rand();
                    sz = rand() % 10 + SmallRandomSize;

                    expectReturnPos = expect.insert(expect.begin(), sz, randomValue);
                    actualReturnPos = actual.insert(actual.begin(), sz, randomValue);

                    CHECK(expectReturnPos == expect.begin());
                    CHECK(actualReturnPos == actual.begin());
                    isSame(expect, actual);
                }
            }

            SECTION("before end")
            {
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

                SECTION("size is non-zero")
                {
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
            }

            SECTION("between of begin and end")
            {
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

                SECTION("size is non-zero")
                {
                    randomValue = rand();
                    sz = rand() % 10 + SmallRandomSize;

                    expectReturnPos = expect.insert(++expect.begin(), sz, randomValue);
                    actualReturnPos = actual.insert(++actual.begin(), sz, randomValue);

                    CHECK(expectReturnPos == ++expect.begin());
                    CHECK(actualReturnPos == ++actual.begin());
                    isSame(expect, actual);
                }
            }

            SECTION("size is 1")
            {
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
            randomValue = rand();
            expect.push_back(randomValue);
            actual.push_back(randomValue);
            randomValue = rand();
            expect.push_back(randomValue);
            actual.push_back(randomValue);

            SECTION("to empty")
            {
                expect.clear();
                actual.clear();
                SECTION("initializer_list is empty")
                {
                    randomIlist = {};

                    expectReturnPos = expect.insert(expect.end(), randomIlist);
                    actualReturnPos = actual.insert(actual.end(), randomIlist);

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }

                SECTION("initializer_list is non-empty")
                {
                    expectReturnPos = expect.insert(expect.end(), randomIlist);
                    actualReturnPos = actual.insert(actual.end(), randomIlist);

                    CHECK(expectReturnPos == expect.begin());
                    CHECK(actualReturnPos == actual.begin());
                    isSame(expect, actual);
                }
            }

            SECTION("before begin")
            {
                SECTION("initializer_list is empty")
                {
                    randomIlist = {};

                    expectReturnPos = expect.insert(expect.begin(), randomIlist);
                    actualReturnPos = actual.insert(actual.begin(), randomIlist);

                    CHECK(expectReturnPos == expect.begin());
                    CHECK(actualReturnPos == actual.begin());
                    isSame(expect, actual);
                }

                SECTION("initializer_list is non-empty")
                {
                    expectReturnPos = expect.insert(expect.begin(), randomIlist);
                    actualReturnPos = actual.insert(actual.begin(), randomIlist);

                    CHECK(expectReturnPos == expect.begin());
                    CHECK(actualReturnPos == actual.begin());
                    isSame(expect, actual);
                }
            }

            SECTION("before end")
            {
                SECTION("initializer_list is empty")
                {
                    randomIlist = {};

                    expectReturnPos = expect.insert(expect.end(), randomIlist);
                    actualReturnPos = actual.insert(actual.end(), randomIlist);

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }

                SECTION("initializer_list is non-empty")
                {
                    expectReturnPos = expect.insert(expect.end(), randomIlist);
                    actualReturnPos = actual.insert(actual.end(), randomIlist);

                    CHECK(expectReturnPos == ++++ expect.begin());
                    CHECK(actualReturnPos == ++++ actual.begin());
                    isSame(expect, actual);
                }
            }

            SECTION("between of begin and end")
            {
                SECTION("initializer_list is empty")
                {
                    randomIlist = {};

                    expectReturnPos = expect.insert(++expect.begin(), randomIlist);
                    actualReturnPos = actual.insert(++actual.begin(), randomIlist);

                    CHECK(expectReturnPos == ++expect.begin());
                    CHECK(actualReturnPos == ++actual.begin());
                    isSame(expect, actual);
                }

                SECTION("initializer_list is non-empty")
                {
                    expectReturnPos = expect.insert(++expect.begin(), randomIlist);
                    actualReturnPos = actual.insert(++actual.begin(), randomIlist);

                    CHECK(expectReturnPos == ++expect.begin());
                    CHECK(actualReturnPos == ++actual.begin());
                    isSame(expect, actual);
                }
            }

            SECTION("size of initializer is 1")
            {
                randomIlist = {rand()};

                expectReturnPos = expect.insert(++expect.begin(), randomIlist);
                actualReturnPos = actual.insert(++actual.begin(), randomIlist);

                CHECK(expectReturnPos == ++expect.begin());
                CHECK(actualReturnPos == ++actual.begin());
                isSame(expect, actual);
            }
        }

        SECTION("insert(const_iterator, iterator, iterator)")
        {
            randomValue = rand();
            expect.push_back(randomValue);
            actual.push_back(randomValue);
            randomValue = rand();
            expect.push_back(randomValue);
            actual.push_back(randomValue);

            SECTION("to empty")
            {
                expect.clear();
                actual.clear();

                SECTION("container is empty")
                {
                    randomSmallContainer = {};

                    expectReturnPos = expect.insert(expect.end(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());
                    actualReturnPos = actual.insert(actual.end(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }

                SECTION("container is non-empty")
                {
                    expectReturnPos = expect.insert(expect.end(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());
                    actualReturnPos = actual.insert(actual.end(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());

                    CHECK(expectReturnPos == expect.begin());
                    CHECK(actualReturnPos == actual.begin());
                    isSame(expect, actual);
                }
            }

            SECTION("before begin")
            {
                SECTION("container is empty")
                {
                    randomSmallContainer = {};

                    expectReturnPos = expect.insert(expect.begin(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());
                    actualReturnPos = actual.insert(actual.begin(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());

                    CHECK(expectReturnPos == expect.begin());
                    CHECK(actualReturnPos == actual.begin());
                    isSame(expect, actual);
                }

                SECTION("container is non-empty")
                {
                    expectReturnPos = expect.insert(expect.begin(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());
                    actualReturnPos = actual.insert(actual.begin(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());

                    CHECK(expectReturnPos == expect.begin());
                    CHECK(actualReturnPos == actual.begin());
                    isSame(expect, actual);
                }
            }

            SECTION("before end")
            {
                SECTION("container is empty")
                {
                    randomSmallContainer = {};

                    expectReturnPos = expect.insert(expect.end(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());
                    actualReturnPos = actual.insert(actual.end(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }

                SECTION("container is non-empty")
                {
                    expectReturnPos = expect.insert(expect.end(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());
                    actualReturnPos = actual.insert(actual.end(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());

                    CHECK(expectReturnPos == ++++ expect.begin());
                    CHECK(actualReturnPos == ++++ actual.begin());
                    isSame(expect, actual);
                }
            }

            SECTION("between of begin and end")
            {
                SECTION("container is empty")
                {
                    randomSmallContainer = {};

                    expectReturnPos = expect.insert(++expect.begin(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());
                    actualReturnPos = actual.insert(++actual.begin(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());

                    CHECK(expectReturnPos == ++expect.begin());
                    CHECK(actualReturnPos == ++actual.begin());
                    isSame(expect, actual);
                }

                SECTION("container is non-empty")
                {
                    expectReturnPos = expect.insert(++expect.begin(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());
                    actualReturnPos = actual.insert(++actual.begin(),
                                                    randomSmallContainer.begin(),
                                                    randomSmallContainer.end());

                    CHECK(expectReturnPos == ++expect.begin());
                    CHECK(actualReturnPos == ++actual.begin());
                    isSame(expect, actual);
                }
            }

            SECTION("size of iterator is 1")
            {
                randomSmallContainer = {rand()};

                expectReturnPos = expect.insert(++expect.begin(),
                                                randomSmallContainer.begin(),
                                                randomSmallContainer.end());
                actualReturnPos = actual.insert(++actual.begin(),
                                                randomSmallContainer.begin(),
                                                randomSmallContainer.end());

                CHECK(expectReturnPos == ++expect.begin());
                CHECK(actualReturnPos == ++actual.begin());
                isSame(expect, actual);
            }
        }
    }

    SECTION("pop rely on [push_back/front/back]")
    {
        // std not throws exception while invoke pop on empty list

        SECTION("pop_front")
        {
            actual.push_back(111);
            CHECK_NOTHROW(actual.pop_front());
            CHECK_THROWS_AS(actual.front(), std::out_of_range);
            CHECK_THROWS_AS(actual.back(), std::out_of_range);

            actual.push_back(111);
            actual.push_back(222);
            CHECK_NOTHROW(actual.pop_front());
            CHECK_NOTHROW(actual.pop_front());
            CHECK_THROWS_AS(actual.front(), std::out_of_range);
            CHECK_THROWS_AS(actual.back(), std::out_of_range);

            actual.push_back(111);
            actual.push_back(222);
            actual.push_back(333);
            CHECK_NOTHROW(actual.pop_front());
            CHECK_NOTHROW(actual.pop_front());
            CHECK_NOTHROW(actual.pop_front());
            CHECK_THROWS_AS(actual.front(), std::out_of_range);
            CHECK_THROWS_AS(actual.back(), std::out_of_range);
        }

        SECTION("pop_back")
        {
            actual.push_back(111);
            CHECK_NOTHROW(actual.pop_back());
            CHECK_THROWS_AS(actual.front(), std::out_of_range);
            CHECK_THROWS_AS(actual.back(), std::out_of_range);

            actual.push_back(111);
            actual.push_back(222);
            CHECK_NOTHROW(actual.pop_back());
            CHECK_NOTHROW(actual.pop_back());
            CHECK_THROWS_AS(actual.front(), std::out_of_range);
            CHECK_THROWS_AS(actual.back(), std::out_of_range);

            actual.push_back(111);
            actual.push_back(222);
            actual.push_back(333);
            CHECK_NOTHROW(actual.pop_back());
            CHECK_NOTHROW(actual.pop_back());
            CHECK_NOTHROW(actual.pop_back());
            CHECK_THROWS_AS(actual.front(), std::out_of_range);
            CHECK_THROWS_AS(actual.back(), std::out_of_range);
        }

        SECTION("random pop")
        {
            copyRandomPartContainerToLists(randomContainer, expect, actual);

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

    SECTION("[push] rely on [clear/begin/end/front/back]")
    {
        SECTION("push front")
        {
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
            std::for_each(randomContainer.begin(), randomContainer.end(), [&](int v)
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

    SECTION("random push/pop rely on [front/back]")
    {
        SECTION("push is more than pop")
        {
            std::for_each(randomContainer.begin(), randomContainer.end(), [&](int v)
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
                        if (!expect.empty())
                        {
                            CHECK_NOTHROW(actual.pop_back());
                            expect.pop_back();
                        }
                    }
                    else if (!expect.empty())
                    {
                        CHECK_NOTHROW(actual.pop_front());
                        expect.pop_front();
                    }
                }
                if (!expect.empty())
                {
                    CHECK(actual.front() == expect.front());
                    CHECK(actual.back() == expect.back());
                }
            });
        }

        SECTION("pop is more than push")
        {
            std::for_each(randomContainer.begin(), randomContainer.end(), [&](int v)
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
                        if (!expect.empty())
                        {
                            CHECK_NOTHROW(actual.pop_back());
                            expect.pop_back();
                        }
                    }
                    else if (!expect.empty())
                    {
                        CHECK_NOTHROW(actual.pop_front());
                        expect.pop_front();
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

TEST_CASE("capcity rely on [push/pop]")
{
    auto randomContainer = getRandomValueContainer();
    actualListContainer actual;
    CHECK(actual.empty());
    CHECK(actual.size() == 0);
    CHECK(actual.max_size() >= actual.size());

    SECTION("random actions")
    {
        int expectSize = 0;

        std::for_each(randomContainer.begin(), randomContainer.end(), [&](int v)
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
                    if (expectSize != 0)
                    {
                        CHECK_NOTHROW(actual.pop_back());
                        --expectSize;
                    }
                }
                else if (expectSize != 0)
                {
                    CHECK_NOTHROW(actual.pop_front());
                    --expectSize;
                }
            }
            CHECK(actual.size() == expectSize);
            CHECK(actual.max_size() >= expectSize);
            CHECK((expectSize ^ actual.empty()));
        });
    }
}

TEST_CASE("iterator rely on [push_back]")
{
    auto expectRandomContainer = getRandomValueContainer();
    auto actual = copyContainerToList(expectRandomContainer);

    SECTION("random move (i++ more than i--) rely on [push_back]")
    {
        SECTION("iterator")
        {
            auto actualIt = actual.begin();
            auto expectIt = expectRandomContainer.begin();

            SECTION("++i/--i")
            {
                while (expectIt < expectRandomContainer.end())
                {
                    if (expectIt < expectRandomContainer.begin())
                    {
                        ++expectIt;
                        ++actualIt;
                    }

                    if (expectIt > --expectRandomContainer.begin() && expectIt
                        < expectRandomContainer.end())
                        CHECK(*actualIt == *expectIt);

                    if (rand() % 3) // times: ++ > --
                    {
                        auto temp = expectIt;
                        if (++temp < expectRandomContainer.end())    // is not lastest
                            CHECK(*(++actualIt) == *(++expectIt));
                        else
                        {
                            ++actualIt;
                            ++expectIt;
                            break;
                        }
                    }
                    else if (expectIt > expectRandomContainer.begin())
                        CHECK(*(--actualIt) == *(--expectIt));

                    if (expectIt > --expectRandomContainer.begin() && expectIt
                        < expectRandomContainer.end())
                        CHECK(*actualIt == *expectIt);
                }
            }

            SECTION("i++/i--")
            {
                while (expectIt < expectRandomContainer.end())
                {
                    if (expectIt < expectRandomContainer.begin())
                    {
                        ++expectIt;
                        ++actualIt;
                    }

                    if (expectIt > --expectRandomContainer.begin() && expectIt
                        < expectRandomContainer.end())
                        CHECK(*actualIt == *expectIt);

                    if (rand() % 3) // times: ++ > --
                        CHECK(*(actualIt++) == *(expectIt++));
                    else if (expectIt > expectRandomContainer.begin())
                        CHECK(*(actualIt--) == *(expectIt--));

                    if (expectIt > --expectRandomContainer.begin() && expectIt
                        < expectRandomContainer.end())
                        CHECK(*actualIt == *expectIt);
                }
            }
        }

        SECTION("reverse iterator")
        {
            auto actualIt = actual.rbegin();
            auto expectIt = expectRandomContainer.rbegin();

            SECTION("++i/--i")
            {
                while (expectIt < expectRandomContainer.rend())
                {
                    if (expectIt < expectRandomContainer.rbegin())
                    {
                        ++expectIt;
                        ++actualIt;
                    }

                    if (expectIt > --expectRandomContainer.rbegin() && expectIt
                        < expectRandomContainer.rend())
                        CHECK(*actualIt == *expectIt);

                    if (rand() % 3) // times: ++ > --
                    {
                        auto temp = expectIt;
                        if (++temp < expectRandomContainer.rend())   // is not lastest
                            CHECK(*(++actualIt) == *(++expectIt));
                        else
                        {
                            ++actualIt;
                            ++expectIt;
                            break;
                        }
                    }
                    else if (expectIt > expectRandomContainer.rbegin())
                        CHECK(*(--actualIt) == *(--expectIt));

                    if (expectIt > --expectRandomContainer.rbegin() && expectIt
                        < expectRandomContainer.rend())
                        CHECK(*actualIt == *expectIt);
                }
            }

            SECTION("i++/i--")
            {
                while (expectIt < expectRandomContainer.rend())
                {
                    if (expectIt < expectRandomContainer.rbegin())
                    {
                        ++expectIt;
                        ++actualIt;
                    }

                    if (expectIt > --expectRandomContainer.rbegin() && expectIt
                        < expectRandomContainer.rend())
                        CHECK(*actualIt == *expectIt);

                    if (rand() % 3) // times: ++ > --
                        CHECK(*(actualIt++) == *(expectIt++));
                    else if (expectIt > expectRandomContainer.rbegin())
                        CHECK(*(actualIt--) == *(expectIt--));

                    if (expectIt > --expectRandomContainer.rbegin() && expectIt
                        < expectRandomContainer.rend())
                        CHECK(*actualIt == *expectIt);
                }
            }
        }
    }

    SECTION("random move (i-- more than i++) rely on [push_back]")
    {
        SECTION("iterator")
        {
            auto actualIt = --actual.end();
            auto expectIt = --expectRandomContainer.end();

            SECTION("++i/--i rely on [push_back]")
            {
                while (expectIt > expectRandomContainer.begin())
                {
                    if (expectIt >= expectRandomContainer.end())
                    {
                        --expectIt;
                        --actualIt;
                    }

                    if (expectIt > --expectRandomContainer.begin() && expectIt
                        < expectRandomContainer.end())
                        CHECK(*actualIt == *expectIt);

                    if (!(rand() % 3)) // times: ++ < --
                    {
                        auto temp = expectIt;
                        if (++temp < expectRandomContainer.end())
                            CHECK(*(++actualIt) == *(++expectIt));
                        else
                        {
                            ++actualIt;
                            ++expectIt;
                            break;
                        }
                    }
                    else if (expectIt > expectRandomContainer.begin())
                        CHECK(*(--actualIt) == *(--expectIt));

                    if (expectIt > --expectRandomContainer.begin() && expectIt
                        < expectRandomContainer.end())
                        CHECK(*actualIt == *expectIt);
                }
            }

            SECTION("i++/i-- rely on [push_back]")
            {
                while (expectIt > expectRandomContainer.begin())
                {
                    if (expectIt >= expectRandomContainer.end())
                    {
                        --expectIt;
                        --actualIt;
                    }

                    if (expectIt > --expectRandomContainer.begin() && expectIt
                        < expectRandomContainer.end())
                        CHECK(*actualIt == *expectIt);

                    if (!(rand() % 3)) // times: ++ < --
                        CHECK(*actualIt++ == *expectIt++);
                    else if (expectIt > expectRandomContainer.begin())
                        CHECK(*actualIt-- == *expectIt--);

                    if (expectIt > --expectRandomContainer.begin() && expectIt
                        < expectRandomContainer.end())
                        CHECK(*actualIt == *expectIt);
                }
            }
        }

        SECTION("reverse iterator")
        {
            auto actualIt = actual.rbegin();
            auto expectIt = expectRandomContainer.rbegin();

            SECTION("++i/--i rely on [push_back]")
            {
                while (expectIt > expectRandomContainer.rbegin())
                {
                    if (expectIt >= expectRandomContainer.rend())
                    {
                        --expectIt;
                        --actualIt;
                    }
                    if (expectIt > --expectRandomContainer.rbegin() && expectIt
                        < expectRandomContainer.rend())
                        CHECK(*actualIt == *expectIt);

                    if (!(rand() % 3)) // times: ++ < --
                    {
                        auto expectItTemp = expectIt;
                        if (++expectItTemp < expectRandomContainer.rend())
                            CHECK(*(++actualIt) == *(++expectIt));
                        else
                        {
                            ++actualIt;
                            ++expectIt;
                            break;
                        }
                    }
                    else if (expectIt > expectRandomContainer.rbegin())
                        CHECK(*(--actualIt) == *(--expectIt));

                    if (expectIt > --expectRandomContainer.rbegin() && expectIt
                        < expectRandomContainer.rend())
                        CHECK(*actualIt == *expectIt);
                }
            }

            SECTION("i++/i-- rely on [push_back]")
            {
                while (expectIt > expectRandomContainer.rbegin())
                {
                    if (expectIt >= expectRandomContainer.rend())
                    {
                        --expectIt;
                        --actualIt;
                    }

                    if (expectIt > --expectRandomContainer.rbegin() && expectIt
                        < expectRandomContainer.rend())
                        CHECK(*actualIt == *expectIt);

                    if (!(rand() % 3)) // times: ++ < --
                        CHECK(*(actualIt++) == *(expectIt++));
                    else if (expectIt > expectRandomContainer.rbegin())
                        CHECK(*(actualIt--) == *(expectIt--));

                    if (expectIt > --expectRandomContainer.rbegin() && expectIt
                        < expectRandomContainer.rend())
                        CHECK(*actualIt == *expectIt);
                }
            }
        }
    }

    SECTION("[reverse iterator: base] rely on [++/--]")
    {
        auto expectRandomContainer = getRandomValueContainer();
        actualListContainer actual = copyContainerToList(expectRandomContainer);
        vectorContainer::reverse_iterator expectReverseBegin(expectRandomContainer.begin());
        actualListContainer::const_reverse_iterator actualReverseBegin(actual.begin());
        auto expectBaseBegin = expectReverseBegin.base();
        auto actualBaseBegin = actualReverseBegin.base();

        while (expectBaseBegin != expectRandomContainer.end())
        {
            CHECK(*expectBaseBegin == *actualBaseBegin);
            ++expectBaseBegin;
            ++actualBaseBegin;
        }
    }
}

TEST_CASE("operations")
{
    auto randomContainer = getRandomValueContainer();
    expectListContainer expect;
    actualListContainer actual;

    SECTION("[reverse] rely on [empty/size/begin/end/front/back/push_back/push_front]")
    {
        SECTION("empty")
        {
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
            CHECK_THROWS_AS(actual.front(), std::out_of_range);
            CHECK_THROWS_AS(actual.back(), std::out_of_range);
            CHECK(actual.size() == 0);
            CHECK(actual.empty());
        }

        SECTION("two nodes")
        {
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
            CHECK_THROWS_AS(actual.front(), std::out_of_range);
            CHECK_THROWS_AS(actual.back(), std::out_of_range);
            CHECK(actual.size() == 0);
            CHECK(actual.empty());
        }

        SECTION("three nodes")
        {
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
            CHECK_THROWS_AS(actual.front(), std::out_of_range);
            CHECK_THROWS_AS(actual.back(), std::out_of_range);
            CHECK(actual.size() == 0);
            CHECK(actual.empty());
        }

        SECTION("random nodes")
        {
            while (!randomContainer.empty())
            {
                auto v = randomContainer.back();
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
                randomContainer.pop_back();
            }
        }
    }
}

TEST_CASE("stl algorithm-compatible")
{
    vectorContainer randomContainer = getRandomValueContainer();
    expectListContainer expect;
    actualListContainer actual;
    expectListContainer::iterator expectPos;
    actualListContainer::iterator actualPos;
    int randomValue;
    size_t sz;
    auto randomSmallContainer = getRandomValueContainer(SmallRandomSize);
    copyRandomPartContainerToLists(randomContainer, expect, actual);

    SECTION("std::for_each")
    {
        expectPos = expect.begin();
        std::for_each(actual.begin(), actual.end(), [&](int v)
        {
            CHECK(v == *expectPos++);
        });
    }

    SECTION("std::find")
    {
        CHECK(*actual.begin() == *std::find(actual.begin(), actual.end(), *expect.begin()));
        CHECK(*++actual.begin() == *std::find(actual.begin(), actual.end(), *++expect.begin()));
        CHECK(*--actual.end() == *std::find(actual.begin(), actual.end(), *--expect.end()));
    }

    SECTION("std::equal")
    {
        CHECK(std::equal(expect.begin(), expect.end(), actual.begin()));
    }
}

TEST_CASE("others")
{
    SECTION("random nodes")
    {
        // todo: test more functions insert/find/unique/sort/erase

        auto randomContainer = getRandomValueContainer();

        actualListContainer actual;
        int expectSize = 1;
        expectListContainer expect;
        expect.push_front(randomContainer.front());

        actual.push_front(randomContainer.front());
        std::for_each(++randomContainer.begin(), randomContainer.end(), [&](int v)
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
                    if (expectSize != 0)
                    {
                        CHECK_NOTHROW(actual.pop_back());
                        CHECK_NOTHROW(expect.pop_back());
                        --expectSize;
                    }
                }
                else if (expectSize != 0)
                {
                    CHECK_NOTHROW(actual.pop_front());
                    CHECK_NOTHROW(expect.pop_front());
                    --expectSize;
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
