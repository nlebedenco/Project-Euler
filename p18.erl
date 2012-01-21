-module(p18).

-export([
calc/0
]).

calc() -> 
	A = makearraylist(p()),
	traverse(1, 1, A, 0).

traverse(I, _, {array, S, _, _,_}, Acc) when I > S -> 
	Acc;
traverse(1, 1, A, _Acc) ->
	X = get(1, 1, A),
	traverse(2, 1, set(1, 1, {X, X}, A), X);
traverse(I, 1, A, Acc) ->
	{_, V} = get(I-1, 1, A),
	X = get(I, 1, A),
	SUM = V + X,
	traverse(I, 2, set(I, 1, {X, SUM}, A), max(SUM, Acc));
traverse(I, I, A, Acc) ->
	{_, V} = get(I-1, I-1, A),
	X = get(I, I, A),
	SUM = V + X,
	traverse(I+1, 1, set(I, I, {X, SUM}, A), max(SUM, Acc));
traverse(I, J, A, Acc) ->
	{_, V0} = get(I-1, J-1, A),
	{_, V1} = get(I-1, J, A),
	X = get(I, J, A),
	SUM = max(V0 + X, V1 + X),
	traverse(I, J+1, set(I, J, {X, SUM}, A), max(SUM, Acc)).

get(I, J, A) ->
	array:get(J-1, array:get(I-1, A)).

set(I, J, V, A) ->
	K = array:set(J-1, V, array:get(I-1, A)),
	array:set(I-1, K, A).

makearraylist(M) -> array:from_list(makearraylist(1, length(M), M, [])).

makearraylist(I, N, _M, L) when I == N+1 -> L;
makearraylist(I, N, M, L)-> 
	A = array:from_list(lists:nth(I, M)),
	makearraylist(I+1, N, M, lists:append(L, [A])).

m() ->
	[
		[3],
		[7,4],
		[2,4,6],
		[8,5,9,3]
	].

p() ->
[
[75],
[95, 64],
[17, 47, 82],
[18, 35, 87, 10],
[20, 04, 82, 47, 65],
[19, 01, 23, 75, 03, 34],
[88, 02, 77, 73, 07, 63, 67],
[99, 65, 04, 28, 06, 16, 70, 92],
[41, 41, 26, 56, 83, 40, 80, 70, 33],
[41, 48, 72, 33, 47, 32, 37, 16, 94, 29],
[53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14],
[70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57],
[91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48],
[63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31],
[04, 62, 98, 27, 23, 09, 70, 98, 73, 93, 38, 53, 60, 04, 23]
].
