# Part of Cosmos by OpenGenus Foundation
def count_digits(n):
    count=0;
    while n != 0:
        count = count + 1;
        n/=10;
    return count;

if __name__ == 'main':
    print(count_digits(25))