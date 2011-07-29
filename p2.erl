-module(p2).

-export([
sum/1
]).

try_even(A) when (A rem 2 == 0) -> A;
try_even(_) -> 0.

sum(N, _, A, Acc) when A > N -> Acc;
sum(N, A, B, Acc) -> io:format("Element: ~p~n", [A+B]), sum(N, B, A+B, try_even(B) + Acc).

sum(N) ->
	sum(N, 1, 1, 0).



