function NeuralNetwork(size, data, options) {

  if (!options) { options = {}; }
  
  this.data = data;
  
  var init, neuron_id = 0, self = this;
  

  this.layers = [];
  this.iterations = options.iterations || 1000;
  this.alpha = options.alpha || 0.3;

  function Neuron(options) {
    this.id = options.id;
    this.inputs = [];
    this.outputs = [];
    this.raw = null;
    this.output = null;
    this.is_bias = (options && options.bias) ? true : false;
  }

  Neuron.prototype.activate = function () {
    this.raw = 0;

    if (this.is_bias) {
    
      this.output = -1;
    
    } else {
      
      for (var i = 0; i < this.inputs.length; i++) {
        var input = this.inputs[i];
        this.raw += input.from.output * input.weight;
      }

      this.output = this.sigmoid(this.raw);

    }
    
  };

  Neuron.prototype.sigmoid = function (value) {
    return 1 / (1 + (Math.exp(-1 * value)));
  };

  Neuron.prototype.add_input = function (input) {
    this.inputs.push(input);
  };

  Neuron.prototype.add_output = function (output) {
    this.outputs.push(output);
  };

  function Connection(from, to, weight) {
    this.weight = weight || this.random_weight();
    this.from = from;
    this.to = to;
  }

  Connection.prototype.random_weight = function() {
    return ((Math.random() * 2) - 1) * 0.0001;
  };

  init = function() {

    for (var i = 0; i < size.length; i++) {
      var layer = [];

      if (i !== size.length - 1) {
        layer.push(new Neuron({ id: neuron_id++, bias: true }));
      }

      for (var j = 0; j < size[i]; j++) {
        layer.push(new Neuron({ id: neuron_id++ }));
      }

      self.layers.push(layer);
    }

    for (var i = 1; i < size.length; i++) {
      
      var from_layer = self.layers[i-1];
      var to_layer = self.layers[i];
      
      for (var j = 0; j < from_layer.length; j++) {
        
        var start = (i === size.length - 1) ? 0 : 1;

        for (var k = start; k < to_layer.length; k++) {
          var from = from_layer[j];
          var to = to_layer[k];
          var weight = (j === 0) ? 1 : null; // non-random weights for bias units
          var connection = new Connection(from, to, weight);
          to.add_input(connection);
          from.add_output(connection);
        }
      }
    }

  };

  init();

}

NeuralNetwork.prototype.forward_propagate = function () {

  for (var i = 1; i < this.layers.length; i++) {
    var layer = this.layers[i];
    
    for (var j = 0; j < layer.length; j++) {
      var neuron = layer[j];
      neuron.activate();
    }
  }
};

NeuralNetwork.prototype.back_propagate = function () {

  // delta[j] := g_prime(input[j]) * (y - a)

  var deltas = [];

  var output_layer = this.layers[this.layers.length - 1];
  

  for (var i = 0; i < output_layer.length; i++) {
    var neuron = output_layer[i];
    var g_prime = neuron.output * (1 - neuron.output);
    var error = this.expected_output[i] - neuron.output;
    deltas[neuron.id] = g_prime * error;
    this.cost += Math.abs(error);
  }


  for (var i = this.layers.length - 2; i >= 1; i--) {
    var layer = this.layers[i];

    for (var j = 0; j < layer.length; j++) {
      var neuron = layer[j];

      // delta[i] := g_prime(output[i]) * sum(weights[i][j] * delta[j])
      var g_prime = neuron.output * (1 - neuron.output);
      var sum = 0;
      
      for (var k = 0; k < neuron.outputs.length; k++) {
        var out_connection = neuron.outputs[k];
        var out_neuron = out_connection.to;
        var out_delta = deltas[out_neuron.id];
        
        sum += out_connection.weight * out_delta;
      }

      deltas[neuron.id] = g_prime * sum;
    }
  }
  
  // w[i][j] := w[i][j] + alpha * activation[i] * delta[j]
  for (var i = 1; i < this.layers.length; i++) {
    var layer = this.layers[i];
    
    for (var j = 0; j < layer.length; j++) {
      var neuron = layer[j];

      for (var k = 0; k < neuron.inputs.length; k++) {
        var input = neuron.inputs[k];
        input.weight = input.weight + (this.alpha * input.from.output * deltas[neuron.id])
      }
    }
  }

};

NeuralNetwork.prototype.run_once = function () {
  
  var input_layer = this.layers[0];
  
  for (var i = 0; i < this.data.X.length; i++) {
    this.training_example = this.data.X[i];
    this.expected_output = this.data.y[i];

    for (var j = 1; j < input_layer.length; j++) {
      input_layer[j].output = this.training_example[j-1];
    }

    this.forward_propagate();
    this.back_propagate();
  }

};

NeuralNetwork.prototype.predict = function (input) {
  var input_layer = this.layers[0];
  
  for (var i = 1; i < input_layer.length; i++) {
    input_layer[i].output = input[i-1];
  }
  
  this.forward_propagate();
  
  var output = this.layers[this.layers.length-1];
  var vals = []
  
  for (var i = 0; i < output.length; i++) {
    vals[i] = output[i].output;
  }
  
  return vals;
};


NeuralNetwork.prototype.train = function () {

  for (var i = 0; i < this.iterations; i++) {
    
    this.cost = 0;  
    
    this.run_once();
    
    console.log('Iteration:', i+1, ' Cost:', this.cost);
    
  }

  console.log('Training complete');
};
