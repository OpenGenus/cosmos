# Problem Link

[MEETUP](https://www.codechef.com/problems/MEETUP)

# Description
  This is an interactive problem. It means that every time you output something, you must finish with a newline character and flush the output. For example, in C++ use the fflush(stdout) function, in Java — call System.out.flush(), in Python — sys.stdout.flush(), and in Pascal — flush(output). Only after flushing the output will you be able to read from the input again.

Alice and Bob are taking a trip to Byteland. The country can be modeled as an undirected graph with n cities and m bidirectional roads. There are at most 1,000 cities, and between 0 and n * (n-1) / 2 roads. The graph is not necessarily connected.

Alice likes visiting cities that are directly connected. She chose ka nodes that form a clique (i.e. every pair of cities has a direct road between them). Bob on the other hand likes to visit cities that are not directly connected. He chose kb nodes that form an independent set of the graph (i.e. no pair of cities has a direct road between them).

Alice and Bob would like to know if their itineraries have any common cities. This seemingly simple task is complicated by the fact that Alice and Bob have maps in different languages.

Alice’s map has the cities with names a1, a2, …, an. Bob’s map has cities with names b1, b2, …, bn. These names are all distinct.

Luckily for you, the judge knows how to translate strings between the languages. Formally, there is a hidden function f that the judge keeps such that for every i there exists a unique j such that f(ai) = bj, and ap, aq have a direct edge if and only if f(ap),f(aq) have a direct edge. We will denote f-1(x) to denote the inverse of the function f. Intuitively, f translates strings from language A to language B, and f-1 translates them from language B to language A.

Translating words takes a lot of effort. You would like to help Alice and Bob by translating as few as words as possible. You can ask the judge what the value of f(ai) is, or what the value of f-1(bj) is. You may only ask the judge at most 10 questions. After asking questions, you must be able to determine if Alice and Bob will visit any common cities. Formally, this means checking whether there exists a city ai that Alice visits and a city bj that Bob visits such that f(ai) = bj.