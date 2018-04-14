# Policy Based Design

Policy-based design, also known as policy-based class design or policy-based
programming, is a computer programming paradigm based on an idiom for C++ known
as policies.

## Explanation

Wikipedia(<https://en.wikipedia.org/wiki/Policy-based_design>) says:

>Policy-based design has been described as a compile-time variant of the strategy
pattern, and has connections with C++ template metaprogramming. It was first
popularized by Andrei Alexandrescu with his 2001 book Modern C++ Design and his
column Generic`<Programming>` in the C/C++ Users Journal.


This design pattern is expecially suitable for writing library for embedded
systems, where a single peripheral may have various modes of operation and the
user may choose between the modes of operation at compile time.

## Algorithm

Well, a design pattern is not an algorithm, but just a solution to certain
problems. In the same way, policy based design a one of the best method to
implement strategy pattern at compile time(i.e. choose between the
implementations at the compile time).

## Complexity

Implementing Policy Based Design increases the number of classes in the program,
so it may be hard to handle since the program will become larger. But this
design pattern does not add runtime overhead while choosing the implementation.
So, this design pattern reduces the timing overhead. If a compiler with a very
good optimizer is used, the space consumed by the final program is also reduced.

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---