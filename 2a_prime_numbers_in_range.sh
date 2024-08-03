#!/bin/bash


echo "Enter the start: "
read low
echo "Enter the end: "
read high


echo "Prime numbers between $low and $high :"
for ((n=low; n<=high; n++)); do
    # if [ "$n" -le 1 ]; then
    #     continue
    # fi
   # these above lines are optional ,to handle numbers which are less than 2


    is_prime=true
    for ((i=2; i*i<=n; i++)); do
        if [ $((n % i)) -eq 0 ]; then
            is_prime=false
            break
        fi
    done
    if $is_prime; then
        echo "$n"
    fi
done
