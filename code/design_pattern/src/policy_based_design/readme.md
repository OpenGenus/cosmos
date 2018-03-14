# Policy Based Design

Policy-based design, also known as policy-based class design or policy-based
programming, is a computer programming paradigm based on an idiom for C++ known
as policies. It has been described as a compile-time variant of the strategy
pattern, and has connections with C++ template metaprogramming. It was first
popularized by Andrei Alexandrescu with his 2001 book Modern C++ Design and his
column Generic`<Programming>` in the C/C++ Users Journal.
        -Wikipedia(<https://en.wikipedia.org/wiki/Policy-based_design>)

I find this design pattern expecially suitable for writing library for embedded
systems, where a single peripheral may have various modes of operation and the
user may choose between the modes of operation at compile time.