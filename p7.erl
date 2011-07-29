-module(p7).

-export([
calc/1
]).


calc(N) ->
	calc([2], 2, 1, 2+1, N).
	
calc(L, P, N, _, N) -> {L, P};
calc(L, P, K, C, N) ->
	case is_prime(L, C) of
		true -> calc(L++[C], C, K+1, C+2, N);
		_ -> calc(L, P, K, C+2, N)
	end.	


is_prime([], _) -> true;
is_prime([H|_], C) when ((H*H) > C) -> true;
is_prime([H|_], C) when (C rem H == 0) -> false;
is_prime([_H|T], C) -> is_prime(T, C).
	