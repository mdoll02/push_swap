#!bin/bash

input_file="input.txt"

python3 input.py > $input_file

cat $input_file
input_value=$(cat $input_file)

./push_swap $input_value

