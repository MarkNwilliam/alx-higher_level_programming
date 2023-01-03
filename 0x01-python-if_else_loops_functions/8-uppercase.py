#!/usr/bin/python3
def uppercase(str):
for ch in str:
        # Convert the character to its ASCII value
        ascii_val = ord(ch)
        # If the ASCII value is within the range of lowercase letters, subtract 32 to get the uppercase equivalent
        if ascii_val >= 97 and ascii_val <= 122:
            ascii_val -= 32
        # Convert the ASCII value back to a character and print it
        print(chr(ascii_val), end="")
    # Print a new line after the string has been printed
    print()