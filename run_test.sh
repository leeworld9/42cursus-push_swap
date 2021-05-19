#!/bin/bash

export ARG=$(./push_swap_tester/random_numbers 500 1)
./push_swap $ARG
echo -n "[result] : ";
./push_swap $ARG | wc -l