from cs50 import get_int

while True:
    h = get_int("Height: ")
    if 0 < h < 9:
        break
    
for i in range(h):
    for j in range(2 * h + 2):
        if j < h - i - 1 or j == h or j == h + 1:
            print(" ", end="")
        elif j > h + i + 2:
            print("", end="")
        else:
            print("#", end="")
    print()