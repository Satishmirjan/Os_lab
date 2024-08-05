#!/bin/bash

# Read three numbers from the user
echo "Enter three numbers:"
read num1
read num2
read num3

# Compare the numbers
if [ "$num1" -gt "$num2" ] && [ "$num1" -gt "$num3" ]; then
    echo "The largest number is $num1"
elif [ "$num2" -gt "$num1" ] && [ "$num2" -gt "$num3" ]; then
    echo "The largest number is $num2"
else
    echo "The largest number is $num3"
fi
