
108
    return predictions 
109
  
110
# Accuracy score 
111
def accuracy_rate(test, predictions): 
112
    correct = 0
113
    for i in range(len(test)): 
114
        if test[i][-1] == predictions[i]: 
115
            correct += 1
116
    return (correct / float(len(test))) * 100.0
117
  
118
  
119
# driver code 
120
  
121
# add the data path in your system 
122
filename = r'E:\user\MACHINE LEARNING\machine learning algos\Naive bayes\filedata.csv'
123
  
124
  
125
# load the file and store it in mydata list 
126
mydata = csv.reader(open(filename, "rt")) 
127
mydata = list(mydata) 
128
mydata = encode_class(mydata) 
129
for i in range(len(mydata)): 
130
    mydata[i] = [float(x) for x in mydata[i]] 
131
  
132
      
133
# split ratio = 0.7  
134
# 70% of data is training data and 30% is test data used for testing 
135
ratio = 0.7
136
train_data, test_data = splitting(mydata, ratio) 
137
print('Total number of examples are: ', len(mydata)) 
138
print('Out of these, training examples are: ', len(train_data)) 
139
print("Test examples are: ", len(test_data)) 
140
  
141
# prepare model 
142
info = MeanAndStdDevForClass(train_data) 
143
  
144
# test model 
145
predictions = getPredictions(info, test_data) 
146
accuracy = accuracy_rate(test_data, predictions) 
147
print("Accuracy of your model is: ", accuracy) 
148
​
