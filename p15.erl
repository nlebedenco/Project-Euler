-module(p15).

-export([
calc/1,
calc/2
]).

%% Pascal's triangle line progression
%% vc = v[c-1] * (r-c) / c
%% where vc is the element in line r-1 column c
%% v[0] = 1

calc(N)-> calc(N, N).


calc(R, C) -> calc((R*2), C+1, 1, 1).

calc(_R, C, C, Acc) -> Acc;
calc(R, C, I, Acc) -> calc(R, C, I+1, Acc * (R+1-I) div I).
