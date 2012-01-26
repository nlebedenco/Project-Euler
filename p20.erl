-module(p20).

-export([
calc/0,
fact/1,
sum/1
]).

calc() -> fact(100).

fact(N) -> fact(N, 1).

fact(1, Acc) -> Acc;
fact(N, Acc) -> fact(N-1, N * Acc).

sum(N) -> sum(N, 0).

sum(0, Acc) -> Acc;
sum(N, Acc) -> sum(N div 10, Acc + N rem 10).
