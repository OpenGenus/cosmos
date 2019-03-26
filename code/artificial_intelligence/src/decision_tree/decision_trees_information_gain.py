from math import log
import numpy as np
from collections import Counter


class Node:
    def __init__(self):
        self.split_column = None
        self.split_value = None
        self.left = None
        self.right = None
        self.node_def = True
        self.label = None


class decision_tree:
    def __init__(self):
        self.head = Node()
        self.max_depth = 3
        self.root_entropy = 1
        self.min_samples = 0

    def train(self, x_train, y_train):
        self.head = self.build(self.head, x_train, y_train, self.root_entropy, 1)

    def build(self, current_node, x_train, y_train, entropy_parent, cur_depth):
        if cur_depth > self.max_depth or len(y_train) <= self.min_samples:
            temp_node = Node()
            temp_node.node_def = False
            return temp_node

        row_length = len(x_train)
        col_length = len(x_train[0])
        count = {}
        prob = {}
        entropy = {}
        information_gain = {}
        weighted_avg = {}
        output_set = set(y_train)

        for i in range(0, col_length):
            count[i] = {}
            prob[i] = {}
            entropy[i] = {}
            s = set(x_train[:, i])
            for j in s:
                count[i][j] = 0
                entropy[i][j] = 0
                for k in output_set:
                    count[i][j + "and" + k] = 0
                    prob[i][j + "and" + k] = 0

        for i in range(0, col_length):
            for j in range(0, row_length):
                count[i][x_train[j][i]] = count[i][x_train[j][i]] + 1
                count[i][x_train[j][i] + "and" + y_train[j]] = (
                    count[i][x_train[j][i] + "and" + y_train[j]] + 1
                )

        for i in range(0, col_length):
            s = set(x_train[:, i])
            weighted_avg[i] = 0
            temp_sum = 0
            for j in s:
                for k in output_set:
                    prob[i][j + "and" + k] = count[i][j + "and" + k] / count[i][j]
                    if prob[i][j + "and" + k]:
                        entropy[i][j] = entropy[i][j] + prob[i][j + "and" + k] * (
                            log(prob[i][j + "and" + k]) / log(2)
                        )
                if entropy[i][j]:
                    entropy[i][j] = entropy[i][j] * -1

                weighted_avg[i] = weighted_avg[i] + entropy[i][j] * count[i][j]
                temp_sum = temp_sum + count[i][j]
            weighted_avg[i] = weighted_avg[i] / temp_sum
            information_gain[i] = entropy_parent - weighted_avg[i]

        max_key = max(information_gain, key=information_gain.get)
        split_set = set(x_train[:, max_key])
        split_value = None

        for i in split_set:
            split_value = i
            break

        x_train_left = []
        x_train_right = []
        y_train_left = []
        y_train_right = []
        split_data_left = []
        split_data_right = []

        for j in range(0, row_length):
            if x_train[j, max_key] == split_value:
                split_data_left.append(j)
            else:
                split_data_right.append(j)

        x_train_left = x_train[split_data_left]
        y_train_left = y_train[split_data_left]
        x_train_right = x_train[split_data_right]
        y_train_right = y_train[split_data_right]
        current_node.split_column = max_key
        current_node.split_value = split_value
        temp_dict = {}

        for i in y_train:
            temp_dict[i] = 0
        for i in y_train:
            temp_dict[i] = temp_dict[i] + 1

        current_node.label = Counter(temp_dict).most_common(1)[0][0]
        current_node.left = Node()
        current_node.right = Node()
        current_node.left = self.build(
            current_node.left,
            x_train_left,
            y_train_left,
            entropy[current_node.split_column][current_node.split_value],
            cur_depth + 1,
        )
        current_node.right = self.build(
            current_node.right,
            x_train_right,
            y_train_right,
            entropy[current_node.split_column][current_node.split_value],
            cur_depth + 1,
        )

        return current_node

    def predict(self, test):
        temp_list = []
        for i in test:
            temp_list.append(self.test_fun(self.head, i))
        return temp_list

    def test_fun(self, cur_node, test):

        if cur_node.left.node_def is False and cur_node.right.node_def is False:
            return cur_node.label

        if test[cur_node.split_column] == cur_node.split_value:
            return self.test_fun(cur_node.left, test)
        else:
            return self.test_fun(cur_node.right, test)


x_train = [
    ["Steep", "Bumpy", "Yes"],
    ["Steep", "Smooth", "Yes"],
    ["Flat", "Bumpy", "No"],
    ["Steep", "Smooth", "No"],
]
y_train = ["Slow", "Slow", "Fast", "Fast"]

x_train = np.array(x_train)
y_train = np.array(y_train)

clf = decision_tree()
clf.train(x_train, y_train)
print(clf.predict(x_train))
