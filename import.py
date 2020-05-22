from sys import argv, exit
from csv import reader
import csv
import sqlite3

# Correct number of command-line arguments should equal 2
if len(argv) != 2:
    print("Missing command-line argument")
    exit(1)

# Create connection with existing database
conn = sqlite3.connect("students.db")

# After connection is established connect create cursor to perform SQL commands
db = conn.cursor()

# Create a table within database
db.execute("CREATE TABLE students (first VARCHAR[255], middle VARCHAR[255], last VARCHAR[255], house VARCHAR[10], birth INT)")

# Open CSV file
with open(argv[1], "r") as characters:

    # Create reader
    reader = csv.DictReader(characters)

    # Iterate over reader to put into database
    for row in reader:

        # Add first, middle and last name
        list = row["name"].split()
        if row["name"].count(" ") == 1:
            db.execute("INSERT INTO students (first, last, house, birth) VALUES (?, ?, ?, ?)", [list[0], list[1], row["house"], row["birth"]])
        else:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", [list[0], list[1], list[2], row["house"], row["birth"]])

# Save (comit) changes
conn.commit()

# Close the connection after changes are saved
conn.close()