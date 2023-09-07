""" K Nearest Neighbours (KNN) algorithm implemented from Scratch in Python on the famous iris data set, 
without using any pre-trained models"""

# Import necessary python packages
import csv
import random
import math
import operator

# Load the dataset file
def loadDataset(filename, split, trainingSet=[], testSet=[]):
    with open(filename, "rt") as csvfile:
        lines = csv.reader(csvfile)
        dataset = list(lines)
        for x in range(len(dataset) - 1):
            for y in range(4):
                dataset[x][y] = float(dataset[x][y])
            if random.random() < split:
                trainingSet.append(dataset[x])
            else:
                testSet.append(dataset[x])

# Function to calculate the Euclidean Distance between 2 vectors (sqrt(sum i to N (x1_i – x2_i)^2))
def euclideanDistance(instance1, instance2, length):
    distance = 0
    for x in range(length):
        distance += pow((instance1[x] - instance2[x]), 2)
    return math.sqrt(distance)

# Function to get the most similar neighbours by calculating the distance between each record in the dataset to the new piece of data
def getNeighbors(trainingSet, testInstance, k):
    distances = []
    length = len(testInstance) - 1
    for x in range(len(trainingSet)):
        dist = euclideanDistance(testInstance, trainingSet[x], length)
        distances.append((trainingSet[x], dist))
    distances.sort(key=operator.itemgetter(1))
    neighbors = []
    for x in range(k):
        neighbors.append(distances[x][0])
    return neighbors

# Function to get responses from the neighbours
def getResponse(neighbors):
    classVotes = {}
    for x in range(len(neighbors)):
        response = neighbors[x][-1]
        if response in classVotes:
            classVotes[response] += 1
        else:
            classVotes[response] = 1
    sortedVotes = sorted(classVotes.items(), key=operator.itemgetter(1), reverse=True)
    return sortedVotes[0][0]

# Function to evaluate the model accuracy in percent
def getAccuracy(testSet, predictions):
    correct = 0
    for x in range(len(testSet)):
        if testSet[x][-1] == predictions[x]:
            correct += 1
    return (correct / float(len(testSet))) * 100.0


def main():
    # prepare data
    trainingSet = []
    testSet = []
    split = 0.67
    loadDataset("iris.data", split, trainingSet, testSet)
    print("Train set: " + repr(len(trainingSet)))
    print("Test set: " + repr(len(testSet)))
    # generate predictions
    predictions = []
    k = 3
    for x in range(len(testSet)):
        neighbors = getNeighbors(trainingSet, testSet[x], k)
        result = getResponse(neighbors)
        predictions.append(result)
        print("> predicted=" + repr(result) + ", actual=" + repr(testSet[x][-1]))
    accuracy = getAccuracy(testSet, predictions)
    print("Accuracy: " + repr(accuracy) + "%")


main()
