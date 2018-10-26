from rnn import RNN
from tokens import tokenize

f = open('input.txt', 'r')
sentences = list(filter(None, f.read().split('\n\n')))
f.close()
# print((sentences))
tokens = []
X = []
Y = []
# word_dim = 58
for i in range(len(sentences)):
    tokens.append([])
    for j in range(len(sentences[i])):
        if(tokenize(sentences[i][j])!="UNKNOWN"):
            tokens[i].append(tokenize(sentences[i][j]))
    X.append(tokens[i][:-1])
    Y.append(tokens[i][1:])

model = RNN(61, 200, 10)
model.load('uwv.pkl')
model.train(X, Y, 0.03, 10, 1)



