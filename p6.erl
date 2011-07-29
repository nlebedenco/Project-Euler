-module(p6).

-export([
calc/1
]).

acc(N, Acc, N, F) -> F(N, Acc);
acc(I, Acc, N, F) -> acc(I+1, F(I, Acc), N, F).

calc(N) ->
	SUM = acc(1, 0, N, fun(I, Acc) -> I+Acc end),
	SQUARED_SUM = SUM*SUM,
	SUM_SQUARES = acc(1, 0, N, fun(I, Acc) -> (I*I)+Acc end),
	SQUARED_SUM - SUM_SQUARES.
	
