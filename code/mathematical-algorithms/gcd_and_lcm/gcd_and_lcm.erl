% Part of Cosmos by OpenGenus Foundation
-module(gcd_and_lcm).
-export([gcd/2, lcm/2]).

gcd(X, 0) -> X;
gcd(X, Y) -> gcd(Y, X rem Y).

lcm(X, Y) -> X * Y / gcd(X, Y).
