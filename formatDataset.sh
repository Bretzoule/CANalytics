#!/bin/bash

# This script is used to format the dataset for the project
# It will remove all the unnecessary columns and rows
# It will also remove all the rows with missing values

DATASET_PATH="./dataset/*.txt"
for file in $DATASET_PATH; do
    if [ -f "$file" ]; then
        sed -i 's/Timestamp://g' $file
        sed -i 's/ID:/;/g' $file
        sed -i 's/DLC:/;/g' $file
        sed -i 's/[[:blank:]]//g' $file
    fi
done