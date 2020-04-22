from cs50 import get_float

while True:
    n = get_float("Change owed: ")
    if n >= 0:
        break

change = round(n * 100)
coin_count = 0

for i in [25, 10, 5, 1]:
    if change < i:
        continue
    else:
        coin_count += int(change / i)
        change = change % i

print(coin_count)