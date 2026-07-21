#!/bin/bash

SOURCE_DIR="./submissions"
BACKUP_DIR="./backup"
REPORT_FILE="./report.txt"
ERROR_FILE="./errors.log"

mkdir -p "$BACKUP_DIR"

total_files=0
duplicate_files=0
backedup_files=0

declare -A hashes

for file in "$SOURCE_DIR"/*
do
    if [ -f "$file" ]; then
        ((total_files++))

        hash=$(md5sum "$file" 2>>"$ERROR_FILE" | awk '{print $1}')

        if [[ -n "${hashes[$hash]}" ]]; then
            ((duplicate_files++))
        else
            hashes[$hash]=1
            cp "$file" "$BACKUP_DIR/" 2>>"$ERROR_FILE"
            ((backedup_files++))
        fi
    fi
done

echo "Files Processed: $total_files" > "$REPORT_FILE"
echo "Duplicate Files: $duplicate_files" >> "$REPORT_FILE"
echo "Backed Up Files: $backedup_files" >> "$REPORT_FILE"

