#!/bin/bash

# @ : all index of the array ( print the whole array )
# ${#array[@]} : gives the length of the array 

clear 
# take in size of array from CLA 
read -p "Enter size of array: " n
i=0
# input array from CLA 
echo "Enter array: "
while [ $i -lt $n ]
do 
	read a[$i]
	i=`expr $i + 1`
done 
# read search key from CLA 
read -p "Enter search key: " search
i=0
idx=-1

# loop through array and check if any element matches search key 
for i in "${!a[@]}";
do 
	if [ ${a[$i]} -eq $search ]
	then 
		idx=$i
	fi 
done 

# print result 
if [ $idx -ne -1 ]
then 
	echo "Element $search found at index $idx!"
else 
	echo "Element not present in array. Better luck next time"
fi 