-module(p21).

-export([
calc/1,
sumdivs/1
]).

calc(N) -> 
	lists:foldl(fun(E, Acc)-> Acc+E end, 0, gb_sets:to_list(calc(N, 1, gb_sets:new()))).

calc(L, L, S) -> S;
calc(L, A, S) -> 
	B = sumdivs(A),
	K = sumdivs(B),
	if (K == A) andalso (A =/= B) -> calc(L, A+1, gb_sets:add_element(A, gb_sets:add_element(B, S)));
		true -> calc(L, A+1, S)
	end.

sumdivs(K) -> sumdivs(K, firstdiv(K)).

sumdivs(1, 1) -> 1; 
sumdivs(K, K) -> 1; 
sumdivs(K, D) -> sumdivs(K, math:sqrt(K), D, 1).

sumdivs(K, L, I, Acc) when I < L, K rem I == 0 ->
	sumdivs(K, L, I+1, Acc+I+(K div I));
sumdivs(K, L, I, Acc) when I == L, K rem I == 0 ->
	sumdivs(K, L, I+1, Acc+I);
sumdivs(K, L, I, Acc) when I =< L ->
	sumdivs(K, L, I+1, Acc);
sumdivs(_K, _L, _I, Acc) -> 
	Acc.

firstdiv(K) -> firstdiv(K, math:sqrt(K), 2).

firstdiv(1, _L, _) -> 1;
firstdiv(K, L, 2) when K rem 2 > 0 -> firstdiv(K, L, 3);
firstdiv(K, L, I) when I =< L, K rem I == 0 -> I;
firstdiv(K, L, I) when I =< L -> firstdiv(K, L, I+2);
firstdiv(K, _L, _I) -> K.



