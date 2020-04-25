from cs50 import get_string

text = get_string("Text: ")
n = len(text)
letters = 0
words = 0
sentences = 0

# go through sentence to add up letters, words, sentences
for i in range(n):
    if text[i].isalpha() == True:
        letters += 1
        if words == 0:
            words += 1
    elif text[i].isspace() == True:
        words += 1
    elif text[i] in ['.', '!', '?']:
        sentences += 1

L = (letters / words)*100
S = (sentences / words)*100

# calculate the algorithm
index = 0.0588 * L - 0.296 * S - 15.8

# spell out which grade is it
if index >= 16:
    print("Grade 16+")
elif index < 0:
    print("Before Grade 1")
else:
    print("Grade", + round(index))