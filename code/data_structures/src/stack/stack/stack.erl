% Part of Cosmos by OpenGenus Foundation

% Pattern matching
% H -> head
% T -> tail
-module(stack).
-export([new/0, push/2, pop/1, empty/1, peek/1]).

new() -> [].

push(H, T) -> [H, T].

pop([H, T]) -> {H, T}.

empty([]) -> true;
empty(_) -> false.

peek([H, _]) -> H.