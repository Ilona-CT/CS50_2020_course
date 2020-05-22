from sys import argv, exit
from csv import reader
import csv
import sqlite3

# Accept name of the house as command-line argument, exit if missing
if len(argv) != 2:
    print("Missing command-line argument")
    exit(1)

# Create connection with existing database
conn = sqlite3.connect("students.db")

# After connection is established connect create cursor to perform SQL commands
db = conn.cursor()

# Execute command from
db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first;", [argv[1]])

# Print row by with house name, omit middle name if None
for row in db:
    if row[1] != None:
        print(row[0], row[1], row[2], end=',')
    else:
        print(row[0], row[2], end=',')
    print(" born", row[3])

# Close the connection
conn.close()