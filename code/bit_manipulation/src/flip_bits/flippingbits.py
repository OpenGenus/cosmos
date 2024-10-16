#! /usr/bin/env python3
# Part of Cosmos by OpenGenus Foundation
def main():
    count = int(input("How many flips? "))

    while count > 0:
        to_flip = int(input("To flip: "))
        flipped = ~to_flip
        print("Flipped:", flipped)
        count -= 1


if __name__ == "__main__":
    main()
