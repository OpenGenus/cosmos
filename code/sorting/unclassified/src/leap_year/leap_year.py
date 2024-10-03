# This program takes two inputs (years)
# and returns all leap years between them
# using normal for...in loop and List Comprehension loop

year_1 = int(input("Enter the first year: "))
year_2 = int(input("Enter the second year: "))

print("Normal way -----------------------------------")
leaps = []

for y in range(year_1, year_2):
    if (y % 4 == 0 and y % 100 != 0) or (y % 400 == 0):
        leaps.append(y)

print(leaps)
# List Comprehension
# [expression for item in interable if condition]

print("List Comprehension way ---------------------------------------")

leaps2 = [
    y for y in range(year_1, year_2) if (y % 4 == 0 and y % 100 != 0) or (y % 400 == 0)
]

print(leaps2)
