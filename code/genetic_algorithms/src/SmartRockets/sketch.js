var lifespan = 400, count = 0, gen = 0;
var obsH = 15, obsW = 60;
var populationSize = 50;
var population, logP;
var target;
function DNA(){
	this.genes = [];
	for (var i = 0; i < lifespan;i++){
		this.genes[i] = p5.Vector.random2D();
		this.genes[i].setMag(0.1);
	}
}

function Rocket(){
	this.pos = createVector(width/2, height);
	this.vel = createVector();
	this.acc = createVector();
	this.dna = new DNA();
	this.r = floor(random(255));
	this.g = floor(random(255));
	this.b = floor(random(255));
	this.fitness = 0;
	this.complete = false;
	this.crashed = false;
	
	this.applyForce = function(force){
		this.acc.add(force);
	}
	this.update = function(){
		var x = this.pos.x;
		var y = this.pos.y;
		var d = dist(x, y, target.x, target.y);
		if (d < 15){
			this.complete = true;
			this.pos = target;
		}
		if ( abs(x - width/2) < obsW/2 && abs(y-height/2) < obsH/2){
			this.crashed = true;
		}
		if (!this.complete && !this.crashed){
			this.applyForce(this.dna.genes[count]);
			this.vel.add(this.acc);
			this.pos.add(this.vel);
			this.acc.mult(0);
		}
	}
	this.show = function(){
		push();
		noStroke();
		fill(this.r,this.g,this.b,100);
		translate(this.pos.x, this.pos.y);
		rotate(this.vel.heading());
		rectMode(CENTER);
		rect(0,0,20,4);
		pop();
	}
	this.calcFitness = function (){
		var d = dist(this.pos.x, this.pos.y, target.x, target.y);
		this.fitness = map(d, 0, width, 1, 0);
		if (this.complete)
			this.fitness *= 10;
		if (this.crashed)
			this.fitness /= 10;
	}
	this.crossover = function(partner){
		var nr = new Rocket();
		var mid = floor(random(this.dna.genes.length));
		for (var i = 0; i < this.dna.genes.length;i++){
			if (i<mid)
				nr.dna.genes[i] = this.dna.genes[i];
			else
				nr.dna.genes[i] = partner.dna.genes[i];
		}
		return nr;
	}	
}
function Population(size){
	this.rockets = [];
	this.matingPool = [];
	this.size = size;
	for (var i = 0;i<this.size;i++){
		this.rockets[i] = new Rocket();
	}
	this.run = function(){
		for (var i = 0;i<this.size;i++){
			this.rockets[i].update();
			this.rockets[i].show();
		}
	}
	
	this.evaluate = function(){
		var maxFit = 0.001;
		this.matingPool = [];
		for (var i = 0;i<this.size;i++){
			this.rockets[i].calcFitness(); 
			maxFit = max(maxFit, this.rockets[i].fitness);
		}
		for (var i = 0;i<this.size;i++){
			var n = floor(this.rockets[i].fitness*100/ maxFit);
			for (var j = 0;j<n;j++)
				this.matingPool.push(this.rockets[i]);
		}
		//createP(maxFit);
	}
	this.selection = function(){
		var newRockets = []
		for (var i = 0; i< this.rockets.length;i++){
			var a = random(this.matingPool);
			var b = random(this.matingPool);
			var child = a.crossover(b);
			newRockets.push(child);
		}
		this.rockets = newRockets;
	}
}

function setup() { 
  var canvas = createCanvas(700, 400);
  canvas.parent('sketch-div');
  logP = createP();
  population = new Population(populationSize);
  target = createVector(width/2, 50);
} 
function draw() { 
  background(0);
  fill(0,255,0,200);
  ellipse(target.x, target.y, 16, 10);
  fill(255,0,0, 200);
  rectMode(CENTER);
  rect(width/2,height/2, obsW, obsH);
  if (count == lifespan){
	  count = 0;
	  population.evaluate();
	  population.selection();
	  gen++;
  }
  population.run();
  logP.html("Generation: "+gen+" lifespan: "+count);
  count++;
  
  fill(250);
  noStroke();
  textFont('monospace');
  textSize(25);
  text("Smart Rockets", 80, 80);
}