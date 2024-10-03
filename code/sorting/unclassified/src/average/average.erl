% Part of Cosmos by OpenGenus Foundation
% Finds the average of an array of numbers.
% Contributed by: Michele Riva (micheleriva)

-module(average).
-export([average/1]).

average(List) ->
    lists:sum(List) / length(List).
