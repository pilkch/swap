#!/bin/bash -eu

# Create two directories with a file in each and swap them
mkdir c
mkdir d
echo "Good Evening" > c/first
echo "Good Night" > d/second
../swap c d

declare FIRST_CONTENT=$(cat c/second)
[[ "$FIRST_CONTENT" = "Good Night" ]]

declare SECOND_CONTENT=$(cat d/first)
[[ "$SECOND_CONTENT" = "Good Evening" ]]

rm -rf ./c ./d

echo "Test successful"
