-module(p16).

-export([
calc/1
]).

calc(N)-> sumup(1 bsl N).

sumup(K) -> sumup(K, 0).

sumup(0, Acc) -> Acc;
sumup(K, Acc) -> 
	sumup(K div 10, Acc + K rem 10).
	