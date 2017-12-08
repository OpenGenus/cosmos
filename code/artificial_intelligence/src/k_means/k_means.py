from random import random

# sets and datas
sets = [random() for i in range(10)]
data = [random() for i in range(1000)]

parameter = 0.01  # This parameter change the mean changing speed must be Min: 0 Max: 1

for x in data:  # O(data count)
    nearest_k = 0
    mininmum_error = 9999
    # At normal condition it must goes to infinite.
    for k in enumerate(sets):  # O(mean count)
        error = abs(x - k[1])
        if error < mininmum_error:
            mininmum_error = error
            nearest_k = k[0]
        sets[nearest_k] = sets[nearest_k] * (1 - parameter) + x * (parameter)

print(sets)

# Algorithmic Anlayze-->O(data*means)  it means Data count = K and Set count = J  // O(K.J) \\
