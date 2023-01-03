#!/usr/bin/python3
def uppercase(str):
    # Convert the string to uppercase
    uppercase_str = ""
    for ch in str:
        if ord(ch) >= 97 and ord(ch) <= 122:
            uppercase_str += chr(ord(ch) - 32)
        else:
            uppercase_str += ch

    # Print the uppercase string followed by a newline character
    print(uppercase_str, end="\n")
    