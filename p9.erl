-module(p9).

-export([
calc/0
]).

calc() -> calc(1000, 1000, 1000).

calc(A, B, C) when ((A*A) + (B*B) == (C*C)), (A+B+C) == 1000, A < B, B < C -> A * B * C;
calc(1, 1, 1) -> undefined;
calc(1, 1, C) -> calc(C-1, C-1, C-1);
calc(1, B, C) -> calc(B-1, B-1, C);
calc(A, B, C) -> calc(A-1, B, C).

