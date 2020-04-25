from cs50 import get_int
from sys import exit


while True:
    cc = get_int("Number: ")
    cc = str(cc)
    n = len(cc)
    if n in [13, 15, 16]:
        break
    else:
        print("INVALID")
        exit(1)

# create array to be multiplied by 2 (starting with second digit counting from the end)
j = n - 2
arr = []

while j >= 0:
    arr.append(cc[j])
    j -= 2

# multiply digits by 2 and add the resulting digits together
x = len(arr)
sum_of_digits = 0

for i in range(x):
    j = int(arr[i]) * 2
    if j > 9:
        for digit in str(j):
            sum_of_digits += int(digit)
    else:
        sum_of_digits += j

# create array to be added up as latter (starting with last digit)
j = n - 1
arr.clear()

while j >= 0:
    arr.append(cc[j])
    j -= 2

# add digits together + sum1
x = len(arr)
for i in range(x):
    sum_of_digits += int(arr[i])

if sum_of_digits % 10 != 0:
    print("INVALID")
else:
    if int(cc[0]) == 4:
        print("VISA")
    elif int(cc[0]) == 3 and int(cc[1]) in [4, 7]:
        print("AMEX")
    elif int(cc[0]) == 5 and int(cc[1]) in [1, 2, 3, 4, 5]:
        print("MASTERCARD")