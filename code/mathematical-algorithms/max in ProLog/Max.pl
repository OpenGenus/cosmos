max(X,Y,X):-X>=Y.
max(X,Y,Y):-X<Y.
maxL([X],X).
maxL([X|L],Y):-maxL(L,N),max(X,N,Y).

ajout(X,L,[X|L]):-not(member(X,L)).
