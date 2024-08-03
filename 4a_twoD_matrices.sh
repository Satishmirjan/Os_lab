#                             Online Bash Shell.
#                 Code, Compile, Run and Debug Bash script online.
# Write your code in this editor and press "Run" button to execute it.

#!/bin/bash

echo "Enter the number of rows:"
read rows
echo "Enter the number of columns:"
read cols

echo "Enter elements of the first matrix:"
for ((i = 0; i < rows; i++)); do
    for ((j = 0; j < cols; j++)); do
        read a[$((i * cols + j))]
    done
done

echo "Enter elements of the second matrix:"
for ((i = 0; i < rows; i++)); do
    for ((j = 0; j < cols; j++)); do
        read b[$((i * cols + j))]
    done
done

echo "First Matrix:"
for ((i = 0; i < rows; i++)); do
    for ((j = 0; j < cols; j++)); do
        echo -n "${a[$((i * cols + j))]} "
    done
    echo
done

echo "Second Matrix:"
for ((i = 0; i < rows; i++)); do
    for ((j = 0; j < cols; j++)); do
        echo -n "${b[$((i * cols + j))]} "
    done
    echo
done

echo "RResult:"
for ((i = 0; i < rows; i++)); do
    for ((j = 0; j < cols; j++)); do
        sum=$(( ${a[$((i * cols + j))]} + ${b[$((i * cols + j))]} ))
        echo -n "$sum "
    done
    echo
done

