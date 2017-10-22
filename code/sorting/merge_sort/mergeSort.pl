%National University from Colombia
%Author:Andres Vargas, Jaime
%Gitub: https://github.com/jaavargasar
%webpage: https://jaavargasar.github.io/
%Language: Prolog

% Merge Sort

llist([],0).
llist([_|T],N):- llist(T,NT),N is NT +1.


divHalf(List,A,B) :- llsplit(List,List,A,B).
llsplit(S,[],[],S).
llsplit(S,[_],[],S).
llsplit([H|T],[_,_|T2],[H|A],S) :-llsplit(T,T2,A,S).

merge([], H, H).
merge(H, [], H).
merge([H|T], [Y|K], [H|S]) :- H =< Y, merge(T, [Y|K], S).
merge([H|T], [Y|K], [Y|S]) :-  Y =< H, merge([H|T], K, S).

mergesort( [],[] ).
mergesort([H], [H]).
mergesort([H|T], S) :-
    llist(T,LEN),
    LEN > 0,
    divHalf([H|T], Y, Z),
    mergesort(Y, L1),
    mergesort(Z, L2),
    merge(L1, L2, S).
