-module(p5).

-export([
calc/0
]).

op(L, N, K) when (K == (L+1) )-> N;
op(L, N, K) when (N rem K == 0) ->	op(L, N, K+1);
op(L, N, _K) ->	op(L, N+1, 1).


calc() -> op(20, 1, 1).

