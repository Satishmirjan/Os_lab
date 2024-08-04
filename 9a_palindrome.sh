#https://www.onlinegdb.com/online_bash_shell
#use the above link to run shell srcipt 

#!/bin/bash

#read the number 
echo "Enter a number: "
read number

# Reverse the number 
reversed=$(echo "$number" | rev)

# Check it is palindrome or not
if [ "$number" -eq "$reversed" ]; then
    echo "$number is a palindrome."
else
    echo "$number is not a palindrome."
fi