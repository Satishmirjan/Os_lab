#!/bin/bash
x=()
y=()
z=()
declare -A x
declare -A y
declare -A z

echo "row size :"
read r;
echo "col size :"
read c;

echo "Enter element of a1"
for (( i=0;i<r;i++ ))
do
for (( j=0;j<c;j++ ))
do
read x[$i,$j]
done 
done

echo "Enter element of a2"
for (( i=0;i<r;i++ ))
do
for (( j=0;j<c;j++ ))
do
read y[$i,$j]
done 
done

echo "element of a1"
for (( i=0;i<r;i++ ))
do
for (( j=0;j<c;j++ ))
do
echo  -ne " ${x[$i,$j]} " 12 2 3 5 6 7 8 9 
 done 
echo
done

echo "element of a2"
for (( i=0;i<r;i++ ))
do
for (( j=0;j<c;j++ ))
do
echo  -ne " ${y[$i,$j]} "
done 
echo
done

echo "Result is : "
for (( i=0;i<r;i++ ))
do
for (( j=0;j<c;j++ ))
do
z[$i,$j]=$((x[$i,$j]+y[$i,$j]))  
echo  -ne " ${z[$i,$j]} "
done 
echo
done