for i in 1 2 3 4 5; do
	ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
	echo -n "$i: For 100  numbers: "
	./push_swap $ARG | wc -l | tr -d '\n'
	echo -n " : "
	./push_swap $ARG | ./checker_linux $ARG
done

for i in 1 2 3 4 5; do
	ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
	echo -n "$i: For 500 numbers: "
	./push_swap $ARG | wc -l | tr -d '\n'
	echo -n " : "
	./push_swap $ARG | ./checker_linux $ARG
done	
