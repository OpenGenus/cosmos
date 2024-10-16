11 Layers f VGG-11 are as follows: 
The detialed explanation has been provided in order to get better insight of how the model should be incorporated. 

Convolution using 64 filters + Max Pooling
Convolution using 128 filters + Max Pooling
Convolution using 256 filters
Convolution using 256 filters + Max Pooling
Convolution using 512 filters
Convolution using 512 filters + Max Pooling
Convolution using 512 filters
Convolution using 512 filters + Max Pooling
Fully connected with 4096 nodes
Fully connected with 4096 nodes
Output layer with Softmax activation with 1000 nodes.
Note: Here the max-pooling layer that is shown in the image is not counted among the 11 layers of VGG, 
the reason for which is listed above. In accordance with the Softmax Activation function, it can be easily verified 
from the VGG-11 architecture.
One major conclusion that can be drawn from the whole study is VGG-11 prospers with an appreciable number of layers due to small size 
of convolution filter. This accounts for good accuracy of the model and decent performance outcomes

Learn more: https://iq.opengenus.org/vgg-11/
