-module(p3).

-export([
calc/1
]).

try_div(1, I) -> I;
try_div(N, I) when (N rem I == 0) -> try_div(N div I, I);
try_div(N, I) -> try_div(N, I+1).

calc(N) ->
	try_div(N, 2).
