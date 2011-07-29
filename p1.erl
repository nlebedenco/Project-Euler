-module(p1).
-export([f/2]).

try_3_or_5(A) when (A rem 3 == 0) -> A;
try_3_or_5(A) when (A rem 5 == 0) -> A;	
try_3_or_5(_) -> 0.

f(1000, Acc) -> Acc;
f(I, Acc) -> f(I+1, try_3_or_5(I) + Acc).
	
