from sys import argv, exit
import csv
from csv import reader

# Correct number of command-line arguments should equal 2
if len(argv) != 3:
    print("Missing command-line argument")
    exit(1)

# Open the csv file to read the first line,
file = open(argv[1], "r")
# Throw file into reader
file_reader = csv.reader(file)
# Save first row only and count number of STRs, minus one as first argument is name
header = next(file_reader)
STRs_count = len(header) - 1

# Open text file to compare, read it and count letters
sequence = open(argv[2], "r")
text = sequence.read()
text_length = len(text)

# Create list to gather results of STRs repetition
List = []

# Iterate over text from sequence and search for STRs
for i in range(STRs_count):
    n = len(header[i + 1])
    j = 0
    # Count max number of STRs next to each other, zero it after each search
    count = 0
    save_max = 0
    while j <= text_length:
        STR = text[j:j + n]
        # When STR and header matches - look how many times
        if STR == header[i + 1]:
            count += 1
            if count > save_max:
                save_max = count
            j = j + n
        # When STR and header doesn't match start with next letter
        else:
            j += 1
            count = 0
    # Add maximum value to the list we can compare
    List.append(str(save_max))

# Compare each row with the List created
for row in file_reader:
    # assign value from index 0 to name of the person not to lose it
    Person = row[0]
    # remowe value at place 0 in the row to remove name
    row.pop(0)
    if row == List:
        print(Person)
        file.close()
        sequence.close()
        exit(1)

print("No match")
file.close()
sequence.close()