#!/bin/zsh

echo "PUSHSWAP script:\nTests with wc - l and then checker as follows:"
echo "permutations of 3:"

COMBOS=("1 2 3" "1 3 2" "2 1 3" "2 3 1" "3 1 2" "3 2 1")

for ARG in "$COMBOS[@]"; do
	echo -n "$ARG: "
	./push_swap $ARG | wc -l | tr -d '\n'
	echo -n " : "
	./push_swap $ARG | ./checker_linux $ARG
done

echo "permutations of 5:"

COMBOS2=("1 2 3 4 5" "1 2 3 5 4" "1 2 4 3 5" "1 2 4 5 3" "1 2 5 3 4" "1 2 5 4 3"
"1 3 2 4 5" "1 3 2 5 4" "1 3 4 2 5" "1 3 4 5 2" "1 3 5 2 4" "1 3 5 4 2"
"1 4 2 3 5" "1 4 2 5 3" "1 4 3 2 5" "1 4 3 5 2" "1 4 5 2 3" "1 4 5 3 2"
"1 5 2 3 4" "1 5 2 4 3" "1 5 3 2 4" "1 5 3 4 2" "1 5 4 2 3" "1 5 4 3 2"
"2 1 3 4 5" "2 1 3 5 4" "2 1 4 3 5" "2 1 4 5 3" "2 1 5 3 4" "2 1 5 4 3"
"2 3 1 4 5" "2 3 1 5 4" "2 3 4 1 5" "2 3 4 5 1" "2 3 5 1 4" "2 3 5 4 1"
"2 4 1 3 5" "2 4 1 5 3" "2 4 3 1 5" "2 4 3 5 1" "2 4 5 1 3" "2 4 5 3 1"
"2 5 1 3 4" "2 5 1 4 3" "2 5 3 1 4" "2 5 3 4 1" "2 5 4 1 3" "2 5 4 3 1"
"3 1 2 4 5" "3 1 2 5 4" "3 1 4 2 5" "3 1 4 5 2" "3 1 5 2 4" "3 1 5 4 2"
"3 2 1 4 5" "3 2 1 5 4" "3 2 4 1 5" "3 2 4 5 1" "3 2 5 1 4" "3 2 5 4 1"
"3 4 1 2 5" "3 4 1 5 2" "3 4 2 1 5" "3 4 2 5 1" "3 4 5 1 2" "3 4 5 2 1"
"3 5 1 2 4" "3 5 1 4 2" "3 5 2 1 4" "3 5 2 4 1" "3 5 4 1 2" "3 5 4 2 1"
"4 1 2 3 5" "4 1 2 5 3" "4 1 3 2 5" "4 1 3 5 2" "4 1 5 2 3" "4 1 5 3 2"
"4 2 1 3 5" "4 2 1 5 3" "4 2 3 1 5" "4 2 3 5 1" "4 2 5 1 3" "4 2 5 3 1"
"4 3 1 2 5" "4 3 1 5 2" "4 3 2 1 5" "4 3 2 5 1")

for ARG in "$COMBOS2[@]"; do
	echo -n "$ARG: "
	./push_swap $ARG | wc -l | tr -d '\n'
	echo -n " : "
	./push_swap $ARG | ./checker_linux $ARG
done
