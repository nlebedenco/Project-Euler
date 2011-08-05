-module(p10).

-export([
calc/1
]).


calc(N) ->
	{L, P} = primes(N),
	{L, lists:sum(L)-P}.

primes(N) ->
	primes([2], 2, 2+1, N).
	
primes(L, P, _, N) when P >= N -> {L, P};
primes(L, P, C, N) ->
	case is_prime(L, C) of
		true -> primes(L++[C], C, C+2, N);
		_ -> primes(L, P, C+2, N)
	end.	


is_prime([], _) -> true;
is_prime([H|_], C) when ((H*H) > C) -> true;
is_prime([H|_], C) when (C rem H == 0) -> false;
is_prime([_H|T], C) -> is_prime(T, C).
	