/*
 Part of Cosmos by OpenGenus Foundation

 xor linked list test
 Created by Ernest on 19/11/2017.
 */

#ifndef XOR_LINKED_LIST_TEST_CPP
#define XOR_LINKED_LIST_TEST_CPP

#include "catch.hpp"
#include "xor_linked_list.cpp"
#include <string>
#include <iostream>
#include <stack>
#include <deque>

TEST_CASE("test xor linked list")
{
    std::srand(static_cast<unsigned int>(clock()));

    auto getRandomVector = [] ()
                           {
                               const size_t sz = 10000 + rand() % 5000;

                               // init
                               std::vector<int> vec(sz);
                               size_t i = 0 - 1;
                               while (++i < sz)
                                   vec.at(i) = static_cast<int>(i);

                               // randomize
                               i = 0 - 1;
                               while (++i < sz)
                               {
                                   auto r = rand() % vec.size();
                                   auto temp = vec.at(i);
                                   vec.at(i) = vec.at(r);
                                   vec.at(r) = temp;
                               }

                               return vec;
                           };

    SECTION("push/pop functions")
    {
        SECTION("single push")
        {
            XorLinkedList<int> xlist;
            CHECK_NOTHROW(xlist.push_front(111));
            CHECK(xlist.front() == 111);
            CHECK(xlist.back() == 111);

            xlist.clear();
            CHECK_NOTHROW(xlist.push_back(111));
            CHECK(xlist.front() == 111);
            CHECK(xlist.back() == 111);
        }

        SECTION("multiple push")
        {
            XorLinkedList<int> xlist;
            CHECK_NOTHROW(xlist.push_front(111));
            CHECK(xlist.front() == 111);
            CHECK(xlist.back() == 111);
            CHECK_NOTHROW(xlist.push_front(222));
            CHECK(xlist.front() == 222);
            CHECK(xlist.back() == 111);
            CHECK_NOTHROW(xlist.push_front(333));
            CHECK(xlist.front() == 333);
            CHECK(xlist.back() == 111);

            xlist.clear();
            CHECK_NOTHROW(xlist.push_back(111));
            CHECK(xlist.front() == 111);
            CHECK(xlist.back() == 111);
            CHECK_NOTHROW(xlist.push_back(222));
            CHECK(xlist.front() == 111);
            CHECK(xlist.back() == 222);
            CHECK_NOTHROW(xlist.push_back(333));
            CHECK(xlist.front() == 111);
            CHECK(xlist.back() == 333);
        }

        SECTION("interlaced push")
        {
            SECTION("start with push_back")
            {
                XorLinkedList<int> xlist;
                xlist.clear();
                CHECK_NOTHROW(xlist.push_back(111));
                CHECK(xlist.front() == 111);
                CHECK(xlist.back() == 111);
                CHECK_NOTHROW(xlist.push_front(222));
                CHECK(xlist.front() == 222);
                CHECK(xlist.back() == 111);
                CHECK_NOTHROW(xlist.push_back(333));
                CHECK(xlist.front() == 222);
                CHECK(xlist.back() == 333);
                CHECK_NOTHROW(xlist.push_front(444));
                CHECK(xlist.front() == 444);
                CHECK(xlist.back() == 333);
            }

            SECTION("start with push_front")
            {
                XorLinkedList<int> xlist;
                xlist.clear();
                CHECK_NOTHROW(xlist.push_front(111));
                CHECK(xlist.front() == 111);
                CHECK(xlist.back() == 111);
                CHECK_NOTHROW(xlist.push_back(222));
                CHECK(xlist.front() == 111);
                CHECK(xlist.back() == 222);
                CHECK_NOTHROW(xlist.push_front(333));
                CHECK(xlist.front() == 333);
                CHECK(xlist.back() == 222);
                CHECK_NOTHROW(xlist.push_back(444));
                CHECK(xlist.front() == 333);
                CHECK(xlist.back() == 444);
            }
        }

        SECTION("empty pop")
        {
            XorLinkedList<int> xlist;

            CHECK_THROWS(xlist.pop_front());
            CHECK_THROWS(xlist.pop_back());

            xlist.clear();
            CHECK_THROWS(xlist.pop_back());
            CHECK_THROWS(xlist.pop_front());
        }

        SECTION("single pop")
        {
            SECTION("push_front pop_front")
            {
                XorLinkedList<int> xlist;
                xlist.clear();
                xlist.push_front(1);
                CHECK_NOTHROW(xlist.pop_front());
            }

            SECTION("push_front pop_back")
            {
                XorLinkedList<int> xlist;
                xlist.clear();
                xlist.push_front(1);
                CHECK_NOTHROW(xlist.pop_back());
            }

            SECTION("push_back pop_front")
            {
                XorLinkedList<int> xlist;
                xlist.clear();
                xlist.push_back(1);
                CHECK_NOTHROW(xlist.pop_front());
            }

            SECTION("push_back pop_back")
            {
                XorLinkedList<int> xlist;
                xlist.clear();
                xlist.push_back(1);
                CHECK_NOTHROW(xlist.pop_back());
            }
        }

        SECTION("multiple pop")
        {
            SECTION("push_front pop_front")
            {
                XorLinkedList<int> xlist;
                xlist.clear();
                xlist.push_front(1);
                xlist.push_front(1);
                xlist.push_front(1);
                xlist.push_front(1);
                CHECK_NOTHROW(xlist.pop_front());
                CHECK_NOTHROW(xlist.pop_front());
                CHECK_NOTHROW(xlist.pop_front());
                CHECK_NOTHROW(xlist.pop_front());
            }

            SECTION("push_front pop_back")
            {
                XorLinkedList<int> xlist;
                xlist.clear();
                xlist.push_front(1);
                xlist.push_front(1);
                xlist.push_front(1);
                xlist.push_front(1);
                CHECK_NOTHROW(xlist.pop_back());
                CHECK_NOTHROW(xlist.pop_back());
                CHECK_NOTHROW(xlist.pop_back());
                CHECK_NOTHROW(xlist.pop_back());
            }

            SECTION("push_back pop_front")
            {
                XorLinkedList<int> xlist;
                xlist.clear();
                xlist.push_back(1);
                xlist.push_back(1);
                xlist.push_back(1);
                xlist.push_back(1);
                CHECK_NOTHROW(xlist.pop_front());
                CHECK_NOTHROW(xlist.pop_front());
                CHECK_NOTHROW(xlist.pop_front());
                CHECK_NOTHROW(xlist.pop_front());
            }

            SECTION("push_back pop_back")
            {
                XorLinkedList<int> xlist;
                xlist.clear();
                xlist.push_back(1);
                xlist.push_back(1);
                xlist.push_back(1);
                xlist.push_back(1);
                CHECK_NOTHROW(xlist.pop_back());
                CHECK_NOTHROW(xlist.pop_back());
                CHECK_NOTHROW(xlist.pop_back());
                CHECK_NOTHROW(xlist.pop_back());
            }
        }

        SECTION("interlaced pop")
        {
            SECTION("with push_front")
            {
                SECTION("start with pop_front")
                {
                    XorLinkedList<int> xlist;
                    xlist.clear();
                    xlist.push_front(1);
                    xlist.push_front(1);
                    xlist.push_front(1);
                    xlist.push_front(1);
                    CHECK_NOTHROW(xlist.pop_front());
                    CHECK_NOTHROW(xlist.pop_back());
                    CHECK_NOTHROW(xlist.pop_front());
                    CHECK_NOTHROW(xlist.pop_back());
                }

                SECTION("start with pop_back")
                {
                    XorLinkedList<int> xlist;
                    xlist.clear();
                    xlist.push_front(1);
                    xlist.push_front(1);
                    xlist.push_front(1);
                    xlist.push_front(1);
                    CHECK_NOTHROW(xlist.pop_back());
                    CHECK_NOTHROW(xlist.pop_front());
                    CHECK_NOTHROW(xlist.pop_back());
                    CHECK_NOTHROW(xlist.pop_front());
                }
            }

            SECTION("with push_back")
            {
                SECTION("start with pop_front")
                {
                    XorLinkedList<int> xlist;
                    xlist.clear();
                    xlist.push_back(1);
                    xlist.push_back(1);
                    xlist.push_back(1);
                    xlist.push_back(1);
                    CHECK_NOTHROW(xlist.pop_front());
                    CHECK_NOTHROW(xlist.pop_back());
                    CHECK_NOTHROW(xlist.pop_front());
                    CHECK_NOTHROW(xlist.pop_back());
                }

                SECTION("start with pop_back")
                {
                    XorLinkedList<int> xlist;
                    xlist.clear();
                    xlist.push_back(1);
                    xlist.push_back(1);
                    xlist.push_back(1);
                    xlist.push_back(1);
                    CHECK_NOTHROW(xlist.pop_back());
                    CHECK_NOTHROW(xlist.pop_front());
                    CHECK_NOTHROW(xlist.pop_back());
                    CHECK_NOTHROW(xlist.pop_front());
                }
            }
        }
    }

    SECTION("size/empty functions")
    {
        XorLinkedList<int> xlist;
        CHECK(xlist.empty());
        CHECK(xlist.size() == 0);
        xlist.clear();
        CHECK(xlist.empty());
        CHECK(xlist.size() == 0);

        SECTION("few action")
        {
            XorLinkedList<int> xlist;

            xlist.push_front(1);
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 1);
            xlist.pop_front();
            CHECK(xlist.empty());
            CHECK(xlist.size() == 0);

            xlist.clear();
            xlist.push_front(1);
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 1);
            xlist.pop_back();
            CHECK(xlist.empty());
            CHECK(xlist.size() == 0);

            xlist.clear();
            xlist.push_back(1);
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 1);
            xlist.pop_front();
            CHECK(xlist.empty());
            CHECK(xlist.size() == 0);

            xlist.clear();
            xlist.push_back(1);
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 1);
            xlist.pop_back();
            CHECK(xlist.empty());
            CHECK(xlist.size() == 0);

            xlist.clear();
            xlist.push_front(1);
            xlist.push_front(1);
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 2);
            xlist.pop_front();
            xlist.pop_front();
            CHECK(xlist.empty());
            CHECK(xlist.size() == 0);

            xlist.clear();
            xlist.push_front(1);
            xlist.push_front(1);
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 2);
            xlist.pop_back();
            xlist.pop_back();
            CHECK(xlist.empty());
            CHECK(xlist.size() == 0);

            xlist.clear();
            xlist.push_back(1);
            xlist.push_back(1);
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 2);
            xlist.pop_front();
            xlist.pop_front();
            CHECK(xlist.empty());
            CHECK(xlist.size() == 0);

            xlist.clear();
            xlist.push_back(1);
            xlist.push_back(1);
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 2);
            xlist.pop_back();
            xlist.pop_back();
            CHECK(xlist.empty());
            CHECK(xlist.size() == 0);
        }

        SECTION("interlaced action")
        {
            XorLinkedList<int> xlist;

            xlist.push_back(1);
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 1);

            xlist.push_back(1);
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 2);

            xlist.push_front(1);
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 3);

            xlist.push_front(1);
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 4);

            xlist.push_back(1);
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 5);

            xlist.push_front(1);
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 6);

            xlist.pop_front();
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 5);

            xlist.pop_front();
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 4);

            xlist.pop_back();
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 3);

            xlist.pop_back();
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 2);

            xlist.pop_front();
            CHECK_FALSE(xlist.empty());
            CHECK(xlist.size() == 1);

            xlist.pop_back();
            CHECK(xlist.empty());
            CHECK(xlist.size() == 0);
        }

        SECTION("random action")
        {
            auto vec = getRandomVector();

            XorLinkedList<int> xlist;
            int expectSize = 0;
            std::for_each(vec.begin(), vec.end(), [&] (int v)
            {
                if (rand() % 2)
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

    SECTION("randomize")
    {
        // todo: test more functions insert/find/unique/sort/erase

        auto vec = getRandomVector();

        XorLinkedList<int> xlist;
        int expectSize = 1;
        std::deque<int> expectList;
        expectList.push_front(vec.front());
        xlist.push_front(vec.front());
        std::for_each(++vec.begin(), vec.end(), [&] (int v)
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
