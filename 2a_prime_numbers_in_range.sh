#!/bin/bash
echo "Enter start : "
read low
echo "Enter end : "
read high
echo "the prime between  $low and $high is"
for (( i=low;i<=high;i++ ))
do
for (( j=2;j<$i/2;j++ ))
do
if [ $((i%j)) == 0 ]
then
flag=1
break
fi
done
if [ $flag == 0 ]
then
echo  -ne " $i "
fi
flag=0
done