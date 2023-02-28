#!bin/bash

rm -rf result.txt

i=0
while [ $i -ne 100 ]
do
        i=$(($i+1))
		input_file="input.txt"

		python3 input.py > $input_file

		cat $input_file >> result.txt
		input_value=$(cat $input_file)

		./push_swap $input_value | ./checker_Mac $input_value >> result.txt
done

grep -B 1 'KO' result.txt

rm -rf input_file
rm -rf input.txt