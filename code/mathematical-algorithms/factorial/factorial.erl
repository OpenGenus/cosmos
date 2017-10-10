-module(factorial).
-export([fac/1]).

fac(0) -> 1;
fac(N) -> N * fac(N-1).