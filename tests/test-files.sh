#!/bin/bash -eu

# Create two files and swap them
echo "Hello" > a
echo "Goodbye" > b
../swap a b

declare A_CONTENT=$(cat a)
[[ "$A_CONTENT" = "Goodbye" ]]

declare B_CONTENT=$(cat b)
[[ "$B_CONTENT" = "Hello" ]]

rm -rf ./a ./b

echo "Test successful"
