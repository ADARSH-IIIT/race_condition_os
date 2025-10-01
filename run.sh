#!/bin/bash

# Step 1: Print current number
if [[ -f "./test.txt" ]]; then
    echo "Current number in test.txt: $(cat ./test.txt)"
else
    echo "Error: test.txt not found!"
    exit 1
fi


# Step 2: Launch both executables simultaneously
./p1 &
PID1=$!

./p2 &
PID2=$!

# Step 3: Wait for both to finish
wait $PID1
wait $PID2


# Step 4: Print updated number
if [[ -f "./test.txt" ]]; then
    echo "Updated number in test.txt: $(cat ./test.txt)"
else
    echo "Error: test.txt not found after execution!"
    exit 1
fi
