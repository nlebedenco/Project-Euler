-module(p19).

-export([
calc/0
]).


calc() -> calc(0, 1, 1900, 12, 2000, 0) - 2. %% subtract the number of sundays 1st from 1900

calc(6, M, Y, M, Y, Acc) -> Acc+1;
calc(_, M, Y, M, Y, Acc) -> Acc;
calc(W, 13, Y, LM, LY, Acc) -> calc(W, 1, Y+1, LM, LY, Acc);
calc(W, M, Y, LM, LY, Acc) -> 
	io:format("last: ~p | ~p,~p | day: ~p ~n", [weekday(W), M, Y, mdays(M, Y)]),
	case W of
		6 -> calc(((mdays(M, Y) rem 7) + W) rem 7, M+1, Y, LM, LY, Acc+1);
		_ -> calc(((mdays(M, Y) rem 7) + W) rem 7, M+1, Y, LM, LY, Acc)
	end.



mdays(2, Y) when ((Y rem 100 > 0) andalso (Y rem 4 == 0)); ((Y rem 100 == 0) andalso (Y rem 400 == 0)) -> 29;
mdays(1, _) -> 31;
mdays(2, _) -> 28;
mdays(3, _) -> 31;
mdays(4, _) -> 30;
mdays(5, _) -> 31;
mdays(6, _) -> 30;
mdays(7, _) -> 31;
mdays(8, _) -> 31;
mdays(9, _) -> 30;
mdays(10, _) -> 31;
mdays(11, _) -> 30;
mdays(12, _) -> 31.

weekday(0) -> sunday;
weekday(1) -> monday;
weekday(2) -> tuesday;
weekday(3) -> wednesday;
weekday(4) -> thursday;
weekday(5) -> friday;
weekday(6) -> saturday.



