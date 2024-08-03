#!/bin/bash
echo "Enter the number of elements"
read n
numbers=()
echo "Enter the numbers:"
for ((i=0; i<n; i++)); do
    read num
    numbers+=($num)
done
largest=${numbers[0]}
for ((i=1; i<n; i++)); do
    if [ "${numbers[i]}" -gt "$largest" ]; then
        largest=${numbers[i]}
    fi
done
echo "The largest number is $largest"
