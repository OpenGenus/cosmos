from rnn import RNN
from tokens import tokenize, detokenize

model = RNN(61,200)
model.load('uwv.pkl')

# print(model.U.shape)
# generate(start_token, num_of_chars, top_k random predictions)
text = model.generate(tokenize('F'), 300, 3)

for i in text:
    print(detokenize(i), end="")
