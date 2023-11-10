# Contexual Chatbot
Chatbots are interactive tools that are used as a computerized replica of a receptionist or guide. It is expected to give meaningful responses to questions posed to it. When this happens for a specialized domain or topic, it is known as Contextual Chatbot. 

Here, I have implemented a simple chatbot, named Stary for a Coffee retail store.

# Packages
The following packages are used :
1. pytorch
2. nltk
3. numpy
4. random
5. json

# Steps of Implementation
Background : An intents file consists of tags, patterns and expected responses for a posed question/remark.
1. Using NLTK, on has to tokenize, stem and vectorize words using bag of words. This forms the X (inputs) of the training dataset.
2. The tags relating to each specific input (X) forms the Y(output). Thus, bag of words(X) and labels/tags(Y) form the labeled training set.
3. We use a simple feedforward network of 3 linear layers with Relu as the non-linearity. 
4. Model is trained based on hyperparameters and saved a file.
5. This file is loaded to perform testing.
6. To get probability of each tag from the derived predictions, we use a Softmax classifier and choose appropriate response.

# Steps to replicate results
1. Downloading this jupyter notebook on Google Colab. Alternatively, they can also load the dataset to their own computers instead of using Google Drive or Kaggle. You have to change the filepath while downloading intents file and model saved file accordingly.
2. Running all the cells **sequentially** in the order as in the notebook.
3. It's done! You can go ahead and try the same algorithm on different datasets.