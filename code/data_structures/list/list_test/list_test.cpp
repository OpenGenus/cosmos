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

using vectorContainer = std::vector<int>;
using expectListContainer = std::list<int>;
using actualListContainer = XorLinkedList<int>;
const size_t RandomSize = 100000 + rand() % 2;
const size_t SmallRandomSize = RandomSize / 100;

auto getRandomValueContainer = ([](size_t sz = RandomSize)
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
});

auto copyContainerToList = ([](const vectorContainer &container)
{
    actualListContainer actual;
    std::for_each(container.begin(), container.end(), [&](int v)
    {
        actual.push_back(v);
    });

    return actual;
});

auto copyRandomPartContainerToExpectAndActualList = ([](const vectorContainer &container,
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
});

auto isSame = ([](expectListContainer expect, actualListContainer actual)
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
            expectListContainer expect;
            expectListContainer::iterator expectIt1(expect.begin());
            expectListContainer::const_iterator expectIt2(expect.begin());
            expectListContainer::reverse_iterator expectIt3(expect.begin());
            expectListContainer::const_reverse_iterator expectIt4(expect.begin());

            expectListContainer::const_iterator expectCIt2(expect.cbegin());
            expectListContainer::const_reverse_iterator expectCIt4(expect.cbegin());

            expectListContainer::reverse_iterator expectRIt3(expect.rbegin());
            expectListContainer::const_reverse_iterator expectRIt4(expect.rbegin());

            expectListContainer::const_reverse_iterator expectCRIt4(expect.crbegin());

            actualListContainer actual;
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
            expectListContainer expect;

            // expectListContainer::iterator expectCIt1(expect.cbegin());
            // expectListContainer::reverse_iterator expectCIt3(expect.cbegin());
            //
            // expectListContainer::iterator expectRIt1(expect.rbegin());
            // expectListContainer::const_iterator expectRIt2(expect.rbegin());
            //
            // expectListContainer::iterator expectCRIt1(expect.crbegin());
            // expectListContainer::const_iterator expectCRIt2(expect.crbegin());
            // expectListContainer::reverse_iterator expectCRIt3(expect.crbegin());

            actualListContainer actual;

            // testListContainer::iterator actualCIt1(actual.cbegin());
            // testListContainer::reverse_iterator actualCIt3(actual.cbegin());

            // testListContainer::iterator actualRIt1(actual.rbegin());
            // testListContainer::const_iterator actualRIt2(actual.rbegin());

            // testListContainer::iterator actualCRIt1(actual.crbegin());
            // testListContainer::const_iterator actualCRIt2(actual.crbegin());
            // testListContainer::reverse_iterator actualCRIt3(actual.crbegin());
        }

        SECTION("end")
        {
            expectListContainer expect;
            expectListContainer::iterator expectIt1(expect.end());
            expectListContainer::const_iterator expectIt2(expect.end());
            expectListContainer::reverse_iterator expectIt3(expect.end());
            expectListContainer::const_reverse_iterator expectIt4(expect.end());

            expectListContainer::const_iterator expectCIt2(expect.cend());
            expectListContainer::const_reverse_iterator expectCIt4(expect.cend());

            expectListContainer::reverse_iterator expectRIt3(expect.rend());
            expectListContainer::const_reverse_iterator expectRIt4(expect.rend());

            expectListContainer::const_reverse_iterator expectCRIt4(expect.crend());

            actualListContainer actual;
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
            expectListContainer expect;

            // expectListContainer::iterator expectCIt1(expect.cend());
            // expectListContainer::reverse_iterator expectCIt3(expect.cend());
            //
            // expectListContainer::iterator expectRIt1(expect.rend());
            // expectListContainer::const_iterator expectRIt2(expect.rend());
            //
            // expectListContainer::iterator expectCRIt1(expect.crend());
            // expectListContainer::const_iterator expectCRIt2(expect.crend());
            // expectListContainer::reverse_iterator expectCRIt3(expect.crend());

            actualListContainer actual;

            // testListContainer::iterator actualCIt1(actual.cend());
            // testListContainer::reverse_iterator actualCIt3(actual.cend());
            //
            // testListContainer::iterator actualRIt1(actual.rend());
            // testListContainer::const_iterator actualRIt2(actual.rend());
            //
            // testListContainer::iterator actualCRIt1(actual.crend());
            // testListContainer::const_iterator actualCRIt2(actual.crend());
            // testListContainer::reverse_iterator actualCRIt3(actual.crend());
        }

        SECTION("const begin")
        {
            const expectListContainer expect;

            expectListContainer::const_iterator expectIt2(expect.begin());
            expectListContainer::const_reverse_iterator expectIt4(expect.begin());

            expectListContainer::const_iterator expectCIt2(expect.cbegin());
            expectListContainer::const_reverse_iterator expectCIt4(expect.cbegin());

            expectListContainer::const_reverse_iterator expectRIt4(expect.rbegin());

            expectListContainer::const_reverse_iterator expectCRIt4(expect.crbegin());

            const actualListContainer actual;

            actualListContainer::const_iterator actualIt2(actual.begin());
            actualListContainer::const_reverse_iterator actualIt4(actual.begin());

            actualListContainer::const_iterator actualCIt2(actual.cbegin());
            actualListContainer::const_reverse_iterator actualCIt4(actual.cbegin());

            actualListContainer::const_reverse_iterator actualRIt4(actual.rbegin());

            actualListContainer::const_reverse_iterator actualCRIt4(actual.crbegin());
        }

        SECTION("const begin errors")
        {
            const expectListContainer expect;

            // expectListContainer::iterator expectIt1(expect.begin());
            // expectListContainer::reverse_iterator expectIt3(expect.begin());
            //
            // expectListContainer::iterator expectCIt1(expect.cbegin());
            // expectListContainer::reverse_iterator expectCIt3(expect.cbegin());
            //
            // expectListContainer::iterator expectRIt1(expect.rbegin());
            // expectListContainer::const_iterator expectRIt2(expect.rbegin());
            // expectListContainer::reverse_iterator expectRIt3(expect.rbegin());
            //
            // expectListContainer::iterator expectCRIt1(expect.crbegin());
            // expectListContainer::const_iterator expectCRIt2(expect.crbegin());
            // expectListContainer::reverse_iterator expectCRIt3(expect.crbegin());

            const actualListContainer actual;

            // testListContainer::iterator actualIt1(actual.begin());
            // testListContainer::reverse_iterator actualIt3(actual.begin());
            //
            // testListContainer::iterator actualCIt1(actual.cbegin());
            // testListContainer::reverse_iterator actualCIt3(actual.cbegin());
            //
            // testListContainer::iterator actualRIt1(actual.rbegin());
            // testListContainer::const_iterator actualRIt2(actual.rbegin());
            // testListContainer::reverse_iterator actualRIt3(actual.rbegin());
            //
            // testListContainer::iterator actualCRIt1(actual.crbegin());
            // testListContainer::const_iterator actualCRIt2(actual.crbegin());
            // testListContainer::reverse_iterator actualCRIt3(actual.crbegin());
        }

        SECTION("const end")
        {
            const expectListContainer expect;

            expectListContainer::const_iterator expectIt2(expect.end());
            expectListContainer::const_reverse_iterator expectIt4(expect.end());

            expectListContainer::const_iterator expectCIt2(expect.cend());
            expectListContainer::const_reverse_iterator expectCIt4(expect.cend());

            expectListContainer::const_reverse_iterator expectRIt4(expect.rend());

            expectListContainer::const_reverse_iterator expectCRIt4(expect.crend());

            const actualListContainer actual;

            actualListContainer::const_iterator actualIt2(actual.end());
            actualListContainer::const_reverse_iterator actualIt4(actual.end());

            actualListContainer::const_iterator actualCIt2(actual.cend());
            actualListContainer::const_reverse_iterator actualCIt4(actual.cend());

            actualListContainer::const_reverse_iterator actualRIt4(actual.rend());

            actualListContainer::const_reverse_iterator actualCRIt4(actual.crend());
        }

        SECTION("const end error")
        {
            const expectListContainer expect;

            // expectListContainer::iterator expectIt1(expect.end());
            // expectListContainer::reverse_iterator expectIt3(expect.end());
            //
            // expectListContainer::iterator expectCIt1(expect.cend());
            // expectListContainer::reverse_iterator expectCIt3(expect.cend());
            //
            // expectListContainer::iterator expectRIt1(expect.rend());
            // expectListContainer::const_iterator expectRIt2(expect.rend());
            // expectListContainer::reverse_iterator expectRIt3(expect.rend());
            //
            // expectListContainer::iterator expectCRIt1(expect.crend());
            // expectListContainer::const_iterator expectCRIt2(expect.crend());
            // expectListContainer::reverse_iterator expectCRIt3(expect.crend());

            const actualListContainer actual;

            // testListContainer::iterator actualIt1(actual.end());
            // testListContainer::reverse_iterator actualIt3(actual.end());
            //
            // testListContainer::iterator actualCIt1(actual.cend());
            // testListContainer::reverse_iterator actualCIt3(actual.cend());
            //
            // testListContainer::iterator actualRIt1(actual.rend());
            // testListContainer::const_iterator actualRIt2(actual.rend());
            // testListContainer::reverse_iterator actualRIt3(actual.rend());
            //
            // testListContainer::iterator actualCRIt1(actual.crend());
            // testListContainer::const_iterator actualCRIt2(actual.crend());
            // testListContainer::reverse_iterator actualCRIt3(actual.crend());
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
    using std::is_const;
    SECTION("iterators")
    {
        SECTION("non-const")
        {
            expectListContainer expect;
            actualListContainer actual;

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
            const expectListContainer expect;
            const actualListContainer actual;

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
    }

    SECTION("element access")
    {
        SECTION("non-const")
        {
            expectListContainer expect;
            actualListContainer actual;

            CHECK(is_const<decltype(actual.front())>() == is_const<decltype(expect.front())>());
            CHECK(is_const<decltype(actual.back())>() == is_const<decltype(expect.back())>());
        }

        SECTION("const")
        {
            const expectListContainer expect;
            const actualListContainer actual;

            CHECK(is_const<decltype(actual.front())>() == is_const<decltype(expect.front())>());
            CHECK(is_const<decltype(actual.back())>() == is_const<decltype(expect.back())>());
        }
    }
}

TEST_CASE("element access rely on [push]")
{
    SECTION("push one node")
    {
        actualListContainer actual;
        actual.push_back(1);
        CHECK(actual.front() == 1);
        CHECK(actual.back() == 1);
    }

    SECTION("push two nodes")
    {
        actualListContainer actual;
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
    SECTION("empty list")
    {
        actualListContainer actual;
        actual.clear();

        CHECK_THROWS_AS(actual.front(), std::out_of_range);
        CHECK_THROWS_AS(actual.back(), std::out_of_range);
        CHECK(actual.size() == 0);
        CHECK(actual.empty());
    }

    SECTION("[clear] rely on [push_back]")
    {
        SECTION("while empty")
        {
            actualListContainer actual;
            actual.clear();
        }

        SECTION("after actions")
        {
            actualListContainer actual;
            actual.push_back(1);
            actual.push_back(2);
            actual.clear();
            actual.push_back(3);
        }

        SECTION("before destruct")
        {
            actualListContainer actual;
            actual.push_back(1);
            actual.push_back(2);
            actual.push_back(3);
            actual.clear();
        }

        SECTION("while destruct")
        {
            actualListContainer actual;
            actual.push_back(1);
            actual.push_back(2);
            actual.push_back(3);
        }
    }

    SECTION("[erase] rely on [push_back/begin/end/op/size]")
    {
        vectorContainer container = getRandomValueContainer();
        expectListContainer expect;
        actualListContainer actual;
        expectListContainer::iterator expectReturnPos;
        actualListContainer::iterator actualReturnPos;
        int randomValue;
        size_t sz;
        auto ilist = getRandomValueContainer(SmallRandomSize);

        SECTION("erase(const_iterator)")
        {
            SECTION("from empty")
            {
                /*
                 erase(end()) is undefined, refer to:
                 http://en.cppreference.com/w/cpp/container/list/erase
                 */
            }

            SECTION("first one")
            {
                SECTION("size is 1")
                {
                    expect.clear();
                    actual.clear();
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
                    expect.clear();
                    actual.clear();
                    copyRandomPartContainerToExpectAndActualList(container, expect, actual);

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
                    expect.clear();
                    actual.clear();
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
                    expect.clear();
                    actual.clear();
                    copyRandomPartContainerToExpectAndActualList(container, expect, actual);

                    expectReturnPos = expect.erase(--expect.end());
                    actualReturnPos = actual.erase(--actual.end());

                    CHECK(expectReturnPos == expect.end());
                    CHECK(actualReturnPos == actual.end());
                    isSame(expect, actual);
                }
            }

            SECTION("between of begin and end")
            {
                expect.clear();
                actual.clear();
                copyRandomPartContainerToExpectAndActualList(container, expect, actual);

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
                 erase(end(), end()) is undefined, refer to:
                 http://en.cppreference.com/w/cpp/container/list/erase
                 */
            }

            SECTION("size is 1")
            {
                expect.clear();
                actual.clear();
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
                SECTION("[begin : end)")
                {
                    expect.clear();
                    actual.clear();
                    copyRandomPartContainerToExpectAndActualList(container, expect, actual);

                    expectReturnPos = expect.erase(expect.begin(), ++++++ expect.begin());
                    actualReturnPos = actual.erase(actual.begin(), ++++++ actual.begin());

                    CHECK(expectReturnPos == expect.begin());
                    CHECK(actualReturnPos == actual.begin());
                    isSame(expect, actual);
                }

                SECTION("(begin : end)")
                {
                    expect.clear();
                    actual.clear();
                    copyRandomPartContainerToExpectAndActualList(container, expect, actual);

                    expectReturnPos = expect.erase(++++++ expect.begin(), ------ expect.end());
                    actualReturnPos = actual.erase(++++++ actual.begin(), ------ actual.end());

                    CHECK(expectReturnPos == ------ expect.end());
                    CHECK(actualReturnPos == ------ actual.end());
                    isSame(expect, actual);
                }

                SECTION("(begin : end]")
                {
                    expect.clear();
                    actual.clear();
                    copyRandomPartContainerToExpectAndActualList(container, expect, actual);

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
        expectListContainer expect;
        actualListContainer actual;
        expectListContainer::iterator expectReturnPos;
        actualListContainer::iterator actualReturnPos;
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
                    CHECK(actualReturnPos == ++actual.begin());
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

    SECTION("pop rely on [push_back/front/back]")
    {
        SECTION("pop_front")
        {
            actualListContainer actual;

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
            actualListContainer actual;

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
            auto container = getRandomValueContainer();

            expectListContainer expect;
            actualListContainer actual;
            std::for_each(container.begin(), container.end(), [&](int v)
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

    SECTION("[push] rely on [clear/begin/end/front/back]")
    {
        SECTION("push front")
        {
            actualListContainer actual;
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
            actualListContainer actual;
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

            expectListContainer expect;
            actualListContainer actual;
            std::for_each(container.begin(), container.end(), [&](int v)
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
        SECTION("push times is larger than")
        {
            auto container = getRandomValueContainer();

            expectListContainer expect;
            actualListContainer actual;
            std::for_each(container.begin(), container.end(), [&](int v)
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

        SECTION("pop times is larger than")
        {
            auto container = getRandomValueContainer();

            expectListContainer expect;
            actualListContainer actual;
            std::for_each(container.begin(), container.end(), [&](int v)
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
    actualListContainer actual;
    CHECK(actual.empty());
    CHECK(actual.size() == 0);
    actual.clear();
    CHECK(actual.empty());
    CHECK(actual.size() == 0);

    SECTION("random actions")
    {
        auto container = getRandomValueContainer();

        actualListContainer actual;
        int expectSize = 0;

        std::for_each(container.begin(), container.end(), [&](int v)
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
            CHECK((expectSize ^ actual.empty()));
        });
    }
}

TEST_CASE("iterator rely on [push_back]")
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

                actualListContainer actual;
                std::for_each(expect.begin(), expect.end(), [&](int v)
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
        actualListContainer actual = copyContainerToList(expect);
        vectorContainer::reverse_iterator expectReverseBegin(expect.begin());
        actualListContainer::const_reverse_iterator actualReverseBegin(actual.begin());
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

TEST_CASE("operations")
{
    SECTION("[reverse] rely on [empty/size/begin/end/front/back/push_back/push_front]")
    {
        SECTION("empty")
        {
            actualListContainer actual;
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
            actualListContainer actual;
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
            actualListContainer actual;
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
            actualListContainer actual;
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
            auto container = getRandomValueContainer();

            expectListContainer expect;
            actualListContainer actual;
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

TEST_CASE("stl compatible")
{
    vectorContainer container = getRandomValueContainer();
    expectListContainer expect;
    actualListContainer actual;
    expectListContainer::iterator expectPos;
    actualListContainer::iterator actualPos;
    int randomValue;
    size_t sz;
    auto ilist = getRandomValueContainer(SmallRandomSize);

    SECTION("std::for_each")
    {
        copyRandomPartContainerToExpectAndActualList(container, expect, actual);
        expectPos = expect.begin();
        std::for_each(actual.begin(), actual.end(), [&](int v)
        {
            CHECK(v == *expectPos++);
        });
    }

    SECTION("std::find")
    {
        copyRandomPartContainerToExpectAndActualList(container, expect, actual);
        CHECK(*actual.begin() == *std::find(actual.begin(), actual.end(), *expect.begin()));
        CHECK(*++actual.begin() == *std::find(actual.begin(), actual.end(), *++expect.begin()));
        CHECK(*--actual.end() == *std::find(actual.begin(), actual.end(), *--expect.end()));
    }

    SECTION("std::equal")
    {
        copyRandomPartContainerToExpectAndActualList(container, expect, actual);
        CHECK(std::equal(expect.begin(), expect.end(), actual.begin()));
    }
}

TEST_CASE("others")
{
    SECTION("random nodes")
    {
        // todo: test more functions insert/find/unique/sort/erase

        auto container = getRandomValueContainer();

        actualListContainer actual;
        int expectSize = 1;
        expectListContainer expect;
        expect.push_front(container.front());

        actual.push_front(container.front());
        std::for_each(++container.begin(), container.end(), [&](int v)
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
