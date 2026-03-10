#!/bin/bash
while true
do
    echo "---------------------------------------------"
    echo "        UNIX COMMANDS MENU"
    echo "---------------------------------------------"
    echo "1) Show current date and time (date)"
    echo "2) List files in current directory (ls -l)"
    echo "3) Show current working directory (pwd)"
    echo "4) Display contents of a file (cat)"
    echo "5) Show first 10 lines of a file (head)"
    echo "6) Show last 10 lines of a file (tail)"
    echo "7) Search for a pattern in a file (grep)"
    echo "8) Show currently logged in users (who)"
    echo "9) Show current processes (ps)"
    echo "10) Send a message to all users (wall)"
    echo "11) Exit"
    echo "---------------------------------------------"
    read -p "Enter your choice: " ch

    case "$ch" in
        1)
            echo "Current date and time:"
            [cite_start]date [cite: 3]
            ;;
        2)
            echo "Listing files (long format):"
            [cite_start]ls -l [cite: 4]
            ;;
        3)
            echo "Current working directory:"
            [cite_start]pwd [cite: 5]
            ;;
        4)
            read -p "Enter file name: " file
            [cite_start]if [ -f "$file" ]; then [cite: 6, 7]
                echo "Contents of $file:"
                cat "$file"
            else
                echo "File does not exist."
            [cite_start]fi [cite: 8]
            ;;
        5)
            read -p "Enter file name: " file
            [cite_start]if [ -f "$file" ]; then [cite: 9, 10]
                echo "First 10 lines of $file:"
                head "$file"
            else
                echo "File does not exist."
            [cite_start]fi [cite: 11]
            ;;
        6)
            read -p "Enter file name: " file
            [cite_start]if [ -f "$file" ]; then [cite: 12, 13]
                echo "Last 10 lines of $file:"
                tail "$file"
            else
                echo "File does not exist."
            [cite_start]fi [cite: 14]
            ;;
        7)
            read -p "Enter file name: " file
            [cite_start]if [ -f "$file" ]; then [cite: 15, 16]
                read -p "Enter pattern to search: " pattern
                echo "Lines containing '$pattern' in $file:"
                grep "$pattern" "$file"
            else
                echo "File does not exist."
            [cite_start]fi [cite: 17]
            ;;
        8)
            echo "Users currently logged in:"
            [cite_start]who [cite: 18]
            ;;
        9)
            echo "Current processes:"
            [cite_start]ps [cite: 19]
            ;;
        10)
            read -p "Enter message to broadcast: " msg
            [cite_start]echo "$msg" | wall [cite: 20, 21]
            ;;
        11)
            echo "Exiting..."
            [cite_start]exit 0 [cite: 22]
            ;;
        *)
            [cite_start]echo "Invalid choice. Please try again." [cite: 23]
            ;;
    esac
    echo
done
