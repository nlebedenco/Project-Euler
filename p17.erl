-module(p17).

-export([
calc/1,
sumup/1
]).


calc(K) -> calc(K, 0).

calc(0, Acc) -> Acc;
calc(K, Acc) -> calc(K-1, Acc + sumup(K)).


sumup(K) -> sumup(K, 0).

sumup(0, Acc) -> Acc;
sumup(1000, _Acc) -> lists:nth(1, algarisms()) + thousand();
sumup(K, _Acc) when K div 100 > 0, K rem 100 > 0 ->
	sumup(K rem 100, lists:nth(K div 100, algarisms()) + hundred() + 3);
sumup(K, _Acc) when K div 100 > 0 ->
	lists:nth(K div 100, algarisms()) + hundred();
sumup(K, Acc) when K < 10 -> 
	Acc + lists:nth(K, algarisms());
sumup(K, Acc) when K div 10 > 1 ->
	sumup(K rem 10, Acc + lists:nth(K div 10, tens()));
sumup(K, Acc) when K div 10 == 1 ->
	Acc + lists:nth((K rem 10)+1, teens()).

algarisms()-> [3, 3, 5, 4, 4, 3, 5, 5, 4].
teens() ->    [3, 6, 6, 8, 8, 7, 7, 9, 8, 8].
tens() ->     [0, 6, 6, 5, 5, 5, 7, 6, 6].
hundred() -> 7.
thousand() -> 8.
