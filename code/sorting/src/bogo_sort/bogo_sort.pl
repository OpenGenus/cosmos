/* Part of Cosmos by OpenGenus Foundation */
/*
* Implementation of bogo_sort in prolog by arvchristos
* using random_permutation predicate
* usage: bogo_sort(List_unsorted, List_sorted).
* true when List_sorted is a sorted permutation of List List_unsorted
*
* Predicate ...
*/

ordered([_]).

ordered([H|[H1|T]]) :-
    H =< H1,
    ordered([H1|T]).

bogo_sort(X,Y):-
    random_permutation(X,Y1),
    ( ordered(Y1) -> Y = Y1 ; bogo_sort(X,Y) ).
