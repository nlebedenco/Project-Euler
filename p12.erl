-module(p12).

-export([
calc/1,
firstdiv/1,
divcount/1
]).


calc(N)->
	w(N).

	
w(L) -> w(L, 1, 1, 1).

w(1, _, _, _) -> 1;
w(L, K, I, D) when D > L -> 
	%io:format("~p ~p ~p~n", [K, I, D]),
	{K, D};
w(L, K, I, D) ->
	%io:format("~p ~p ~p~n", [K, I, D]),
	w(L, K+I+1, I+1, divcount(K+I+1)).



divcount(K) -> divcount(K, firstdiv(K)).

divcount(1, 1) -> 1; 
divcount(K, K) -> 2; 
divcount(K, D) -> divcount(K, math:sqrt(K), D, 2).

divcount(K, L, I, Acc) when I < L, K rem I == 0 ->
	divcount(K, L, I+1, Acc+2);
divcount(K, L, I, Acc) when I == L, K rem I == 0 ->
	divcount(K, L, I+1, Acc+1);
divcount(K, L, I, Acc) when I =< L ->
	divcount(K, L, I+1, Acc);
divcount(_K, _L, _I, Acc) -> Acc.

firstdiv(K) -> firstdiv(K, math:sqrt(K), 2).

firstdiv(1, _L, _) -> 1;
firstdiv(K, L, 2) when K rem 2 > 0 -> firstdiv(K, L, 3);
firstdiv(K, L, I) when I =< L, K rem I == 0 -> I;
firstdiv(K, L, I) when I =< L -> firstdiv(K, L, I+2);
firstdiv(K, _L, _I) -> K.



