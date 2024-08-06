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



or
#3a. Finding largest of N numbers (storing numbers in an array)
#!/bin/bash
# Program to find the largest of the given array of numbers
echo "Enter the size of the array: "
read n
declare -A arr
echo "Enter the elements of the array: "
for ((i=0; i<n; i++))
do
read arr["$i"]
done
max=${arr[$i]}
for ((i=1; i<n; i++))
do
if [[ $max < ${arr[$i]} ]]
then
max=${arr[$i]}
fi
done
echo "The largest of the given numbers is $ma
