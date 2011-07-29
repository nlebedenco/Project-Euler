-module(p4).

-export([
calc/1
]).


op(900, _) -> 
	0;
op(A, 900) -> 
	op(A-1, A-1);
op(A, B) when ((A*B) div 1000) == (((A*B) rem 10) * 100 + (((A*B) rem 100) div 10) * 10 + ((A*B) rem 1000) div 100) -> 
	io:format("~p * ~p = ~p~n", [A, B, A*B]), 
	A*B;
op(A, B) -> 
	io:format("~p * ~p = ~p~n", [A, B, A*B]), 
	op(A, B-1).

calc(N) -> op(N, N).

