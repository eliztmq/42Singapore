#!/bin/bash

make re
make clean

# Define the length of each sequence
sequence_lengths=(5)

# Specify the directory to store files
output_directory="test_results"

# Define the path to your push_swap program
push_swap_executable="./push_swap"

# Define the path to your checker program
checker_executable="./checker_linux"

bonus_executable="./checker"

# Check if the output directory exists
if [ -d "$output_directory" ]; then
    # Remove the existing output directory and its contents
    rm -rf "$output_directory"
fi

# Create the output directory
mkdir -p "$output_directory"

for sequence_length in "${sequence_lengths[@]}"; do
    # Define the number of sequences you want to generate
    num_sequences=100

    echo -e "\n"

    # Output file for recording results
    results_file="$output_directory/$sequence_length-results.txt"

    sequences_file="$output_directory/$sequence_length-sequences.txt"

    checks_file="$output_directory/$sequence_length-checks.txt"

    # Check if sequences.txt exists, and if not, create it
    if [ ! -e "$sequences_file" ]; then
        touch "$sequences_file"
    fi

    # Check if the results file exists, and if not, create it
    if [ ! -e "$results_file" ]; then
        touch "$results_file"
    fi

    # Check if the checks file exists, and if not, create it
    if [ ! -e "$checks_file" ]; then
        touch "$checks_file"
    fi

    echo "Sequence length: $sequence_length"
    echo "------------------------"

    # Loop to generate sequences and test push_swap
    for ((i=1; i<=num_sequences; i++)); do
        # Generate a sequence of unique random numbers using shuf and seq
        sequence=$(seq 1 $sequence_length | shuf)

        echo $sequence >> $sequences_file


        # Run push_swap with the generated sequence and record the result
        result=$($push_swap_executable $sequence | wc -l)
        echo $result >> $results_file

        OKKO=$($push_swap_executable $sequence | $checker_executable $sequence)
        KOOK=$($push_swap_executable $sequence | $bonus_executable $sequence)
        echo $OKKO >> $checks_file
        printf "Test : %3d      Moves : %5d         Sorted : %5s        Bonus : %5s\n" $i $result $OKKO $KOOK

    done

    echo "------------------------"

    if [ -e "$results_file" ]; then
        echo "Sequence Length: $sequence_length"
        echo "Results File: $results_file"
        
        # Calculate average, min, and max
        average=$(awk '{ total += $1 } END { printf("%.2f", total/NR) }' "$results_file")
        min=$(sort -n "$results_file" | head -n 1)
        max=$(sort -n "$results_file" | tail -n 1)
        
        echo -e "\n"
        echo "Average: $average"
        echo "Minimum: $min"
        echo "Maximum: $max"
        echo "------------------------"

        # Count "OK" and "KO" in checks_file
        ok_count=$(grep -c "OK" "$checks_file")
        ko_count=$(grep -c "KO" "$checks_file")
        
        echo "OK Count: $ok_count"
        echo "KO Count: $ko_count"
        echo "------------------------"

    else
        echo "Results file not found for sequence length $sequence_length."
    fi

    sleep 1

done
echo "Generated $num_sequences sequences and recorded results."
