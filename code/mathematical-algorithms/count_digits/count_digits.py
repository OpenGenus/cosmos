# Part of Cosmos by OpenGenus Foundation
def count_digits(n):
    if n == 0:
        return 1;
    count = 0;
    while n != 0:
        count += 1;
        n /= 10;
    return count;

if __name__ == 'main':
    print(count_digits(25))
