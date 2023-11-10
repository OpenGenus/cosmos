import numpy as np
from collections import defaultdict


def count_words(features, output):
    my_set = []

    d = defaultdict(float)
    for i in range(0, len(features)):
        for j in range(0, len(features[0])):

            d[features[i][j]] = 0

    for i in range(0, len(output)):
        d[output[i]] = 0

    for i in range(0, len(features)):
        for j in range(0, len(features[0])):
            d[features[i][j]] = d[features[i][j]] + 1

    for i in range(0, len(output)):
        d[output[i]] = d[output[i]] + 1

    for i, j in enumerate(set(output)):
        for k in range(0, len(features)):
            for p, q in enumerate(set(features[k])):
                d[q + "/" + j] = 0

    for i, j in enumerate(output):
        for k in range(len(features)):
            d[features[k][i] + "/" + j] = d[features[k][i] + "/" + j] + 1

    return d


def calculate_probabilities(d, features, output):
    x = defaultdict(float)
    sumi = sum([d[j] for j in set(output)])
    for i in output:
        x[i] = (d[i] * 1.0) / (sumi)

    for i, j in enumerate(set(output)):
        for k in range(0, len(features)):
            for p, q in enumerate(set(features[k])):
                x[q + "/" + j] = d[q + "/" + j] / d[j]

    return x


def final_prediction(x, features, output_set):
    predict_array = []
    predict_array_prob = []
    for i in range(0, len(features[0])):
        predict_array.append(0)
        predict_array_prob.append(0)

    for k in output_set:
        for i in range(0, len(features[0])):
            temp = 1.0
            for j in range(0, len(features)):
                temp = temp * x[features[j][i] + "/" + k]
            if predict_array_prob[i] < temp * x[k]:
                predict_array[i] = k
                predict_array_prob[i] = temp * x[k]

    return predict_array


Weather = [
    "sunny",
    "rainy",
    "sunny",
    "sunny",
    "sunny",
    "rainy",
    "rainy",
    "sunny",
    "sunny",
    "rainy",
]
Car = [
    "working",
    "broken",
    "working",
    "working",
    "working",
    "broken",
    "broken",
    "working",
    "broken",
    "broken",
]
Class = [
    "go-out",
    "go-out",
    "go-out",
    "go-out",
    "go-out",
    "stay-home",
    "stay-home",
    "stay-home",
    "stay-home",
    "stay-home",
]

d = count_words([Weather, Car], Class)
x = calculate_probabilities(d, [Weather, Car], Class)
predict_array = final_prediction(
    x, [Weather, Car], set(Class)
)  # Testing on the training set itself

for i in range(0, len(Weather)):
    print(Weather[i], "\t", Car[i], "\t-->\tprediction is ", predict_array[i])
