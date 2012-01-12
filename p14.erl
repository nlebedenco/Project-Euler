-module(p14).

-export([
calc/1,
count/1
]).

calc(L)-> traverse(L).

traverse(L) -> traverse(L, 1, {0, 0}).

traverse(L, I, Acc) when I > (L-1) -> Acc;
traverse(L, I, Acc={_,C}) ->
	NC = count(I),
	if (C < NC) -> traverse(L, I+1, {I, NC});
		true -> traverse(L, I+1, Acc) 
	end.

count(K) -> count(K, 0).

count(K, 0) when K rem 2 == 0 -> count(K div 2, 1);
count(K, 0) -> count(3*K+1, 1);
count(1, Acc) -> Acc+1;
count(K, Acc) when K rem 2 == 0 -> count(K div 2, Acc+1);
count(K, Acc) -> count(3*K+1, Acc+1).

