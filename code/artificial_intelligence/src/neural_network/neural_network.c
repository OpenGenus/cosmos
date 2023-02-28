/* Basic neural network in C trained on mnist dataset */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

//#define _BIG_ENDIAN // For big endian machines
#define TRAIN_IMGS "data/train-images-idx3-ubyte"
#define TRAIN_LBLS "data/train-labels-idx1-ubyte"
#define TEST_IMGS "data/t10k-images-idx3-ubyte"
#define TEST_LBLS "data/t10k-labels-idx1-ubyte"
#define LYRS 0, 50, 40, 20, 10
#define NLYRS 5
#define STAGE_RATES 0.25, 0.18, 0.13, 0.1
#define STAGES 4

struct net {
	size_t *layers, nlayers, nws, nbs;
	double *weights, *biases, *vals, *b1, *b2, rate;
};

static struct net net;
static double *trainIn, *testIn;
static uint8_t *trainOut, *testOut;
static size_t trainSamples, testSamples;

#ifdef _BIG_ENDIAN
#define CORRECT_ENDIAN(X) (X)
#else
#define CORRECT_ENDIAN(X) (smolendian(X))
#endif
uint32_t
smolendian(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF );
	return (val << 16) | (val >> 16);
}

int
openFiles()
{
	FILE *imgs = fopen(TRAIN_IMGS, "rb"), *lbls = fopen(TRAIN_LBLS, "rb");
	fseek(imgs, 4, SEEK_SET);
	fseek(lbls, 8, SEEK_SET);

	uint32_t n, m;
	fread(&n, 4, 1, imgs);
	trainSamples = CORRECT_ENDIAN(n);
	fread(&n, 4, 1, imgs);
	n = CORRECT_ENDIAN(n);
	fread(&m, 4, 1, imgs);
	m = CORRECT_ENDIAN(m);
	net.layers[0] = n * m;
	trainIn = malloc(n * m * trainSamples * sizeof(double));
	uint8_t *buffer = malloc(n * m);
	trainOut = malloc(trainSamples);

	printf("Reading training data\n");
	for (size_t i = 0; i < trainSamples; ++i) {
		fread(buffer, n * m, 1, imgs);
		for (size_t j = 0; j < n * m; ++j)
			trainIn[i * n * m + j] = (double)buffer[j]/0xFF;
	}
	fread(trainOut, 1, trainSamples, lbls);

	fclose(imgs);
	fclose(lbls);
	free(buffer);

	imgs = fopen(TEST_IMGS, "rb");
	lbls = fopen(TEST_LBLS, "rb");
	fseek(imgs, 4, SEEK_SET);
	fseek(lbls, 8, SEEK_SET);

	fread(&n, 4, 1, imgs);
	testSamples = CORRECT_ENDIAN(n);
	fread(&n, 4, 1, imgs);
	n = CORRECT_ENDIAN(n);
	fread(&m, 4, 1, imgs);
	m = CORRECT_ENDIAN(m);
	net.layers[0] = n * m;
	testIn = malloc(n * m * testSamples * sizeof(double));
	buffer = malloc(n * m);
	testOut = malloc(testSamples);

	printf("Reading test data\n");
	for (size_t i = 0; i < testSamples; ++i) {
		fread(buffer, n * m, 1, imgs);
		for (size_t j = 0; j < n * m; ++j)
			testIn[i * n * m + j] = (double)buffer[j]/0xFF;
	}
	fread(testOut, 1, testSamples, lbls);

	fclose(imgs);
	fclose(lbls);
	free(buffer);
	return 0;
}

uint8_t
maxidx(double *arr)
{
	uint8_t idx = 0;
	double max = -1;
	for (short i = 0; i < 10; ++i) {
		if (arr[i] > max) {
			max = arr[i];
			idx = i;
		}
	}
	return idx;
}

void
add(const double *const a1, double *const a2, size_t len)
{
	for (size_t i = 0; i < len; ++i)
		a2[i] += a1[i];
}

void
sub(const double *const a1, const double *const a2, double *const out,
    size_t len)
{
	for (size_t i = 0; i < len; ++i)
		out[i] = a1[i] - a2[i];
}

double
dsquare(const double *const a, const double *const b, size_t len)
{
	double acc = 0;
	for (size_t i = 0; i < len; ++i)
		acc += (a[i] - b[i]) * (a[i] - b[i]);
	return acc;
}

void
activation(double *const a, size_t len)
{
	for (size_t i = 0; i < len; ++i)
		a[i] = 1/(1 + exp(-a[i]));
}

void
zip(double c, const double *const a, double *const b,
    size_t len)
{
	for (size_t i = 0; i < len; ++i)
		b[i] = c * a[i] * b[i] * (1 - b[i]);
}

void
multV(const double *const m, const double *const v,
    double *const vf, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; ++i) {
		vf[i] = m[i * cols] * v[0];
		for (size_t j = 1; j < cols; ++j)
			vf[i] += m[i * cols + j] * v[j];
	}
}

void
multcTV(double c, const double *const m, const double *const v,
    double *const vf, size_t rows, size_t cols)
{
	for (size_t i = 0; i < cols; ++i) {
		vf[i] = c * m[i] * v[0];
		for (size_t j = 1; j < rows; ++j)
			vf[i] += c * m[i + j * cols] * v[j];
	}
}

void
addDotT(const double *const v1, const double *const v2, double *const m,
    size_t len1, size_t len2)
{
	for (size_t i = 0; i < len1; ++i) {
		for (size_t j = 0; j < len2; ++j)
			m[i * len2 + j] += v1[i] * v2[j];
	}
}

double *
feedforward(const struct net *const net, const double *const in)
{
/* Multiply weight & add biases: Wv + B */
	multV(net->weights, in, net->vals, net->layers[1], net->layers[0]);
	add(net->biases, net->vals, net->layers[1]);
/* Apply activation function */
	activation(net->vals, net->layers[1]);
	size_t woff = 0, loff = 0; // Weight and layer offsets.
	for (size_t i = 1; i < net->nlayers - 1; ++i) {
		loff += net->layers[i];
		woff += net->layers[i] * net->layers[i - 1];
		multV(net->weights + woff, net->vals + loff - net->layers[i],
			net->vals + loff, net->layers[i + 1], net->layers[i]);
		add(net->biases + loff, net->vals + loff, net->layers[i + 1]);
		activation(net->vals + loff, net->layers[i + 1]);
	}
	return net->vals + loff;
}

void
drop(double *const layer, double p, size_t len)
{
	size_t drop = (size_t)((1 - p) * len), n = len;
	for (size_t i = 0; i < len; ++i) {
		if (rand() % n < drop) {
			layer[i] = 0.0;
			--drop;
			--n;
		}
	}
	double scale = 1/p;
	for (size_t i = 0; i < len; ++i)
		layer[i] *= scale;
}

double *
dropforward(const struct net *const net, const double *const in,
		const double *const ps)
{
/* Multiply weight & add biases: Wv + B */
	multV(net->weights, in, net->vals, net->layers[1], net->layers[0]);
	add(net->biases, net->vals, net->layers[1]);
/* Apply activation function */
	activation(net->vals, net->layers[1]);
/* Apply dropout */
	drop(net->vals, ps[0], net->layers[1]);
	size_t woff = 0, loff = 0; // Weight and layer offsets.
	for (size_t i = 1; i < net->nlayers - 1; ++i) {
		loff += net->layers[i];
		woff += net->layers[i] * net->layers[i - 1];
		multV(net->weights + woff, net->vals + loff - net->layers[i],
		    net->vals + loff, net->layers[i + 1], net->layers[i]);
		add(net->biases + loff, net->vals + loff, net->layers[i + 1]);
		activation(net->vals + loff, net->layers[i + 1]);
		drop(net->vals + loff, ps[i], net->layers[i + 1]);
	}
	return net->vals + loff;
}

void
train(struct net *const net, const double *const in,
    const double *const act)
{
	size_t loff = net->nbs - net->layers[net->nlayers - 1], woff = net->nws;
/* Last layer error */
	sub(act, net->vals + loff, net->b1, net->layers[net->nlayers - 1]);
	for (size_t i = net->nlayers - 1; i > 1; --i) {
		woff -= net->layers[i] * net->layers[i - 1];
	/* Scaled gradient */
		zip(net->rate, net->b1, net->vals + loff, net->layers[i]);
	/* Update Biases */
		add(net->vals + loff, net->biases + loff, net->layers[i]);
	/* Update weights */
		addDotT(net->vals + loff, net->vals + loff - net->layers[i - 1],
		    net->weights + woff, net->layers[i], net->layers[i - 1]);
	/* Prepare next error */
		multcTV(1/net->rate, net->weights + woff, net->vals + loff,
		    net->b2, net->layers[i], net->layers[i - 1]);
		double *tmp = net->b1;
		net->b1 = net->b2;
		net->b2 = tmp;
		loff -= net->layers[i - 1];
	}
	zip(net->rate, net->b1, net->vals + loff, net->layers[1]);
	add(net->vals + loff, net->biases + loff, net->layers[1]);
	addDotT(net->vals, in, net->weights, net->layers[1], net->layers[0]);
}

void
initNet(struct net *const net)
{
/* Initializes weights, biases, nws, nbs & buffers if not already assigned */
	size_t max;

	if (!net->nws) {
		for (size_t i = 1; i < net->nlayers; ++i)
			net->nws += net->layers[i] * net->layers[i - 1];
	}
	if (!net->nbs) {
		for (size_t i = 1; i < net->nlayers; ++i)
			net->nbs += net->layers[i];
	}
	if (!net->b1 && !net->b2) {
		max = 0;
		for (size_t i = 0; i < net->nlayers; ++i)
			max = net->layers[i] > max ? net->layers[i] : max;
		net->b1 = malloc(max * sizeof(double));
		net->b2 = malloc(max * sizeof(double));
	}
	if (!net->weights) {
		net->weights = malloc(net->nws * sizeof(double));
		for (size_t i = 0; i < net->nws; ++i) {
			double w = 0.7 * rand() / (double)RAND_MAX;
			net->weights[i] = (i & 1) ? -w : w;
		}
	}
	if (!net->biases) {
		net->biases = malloc(net->nbs * sizeof(double));
		for (size_t i = 0; i < net->nbs; ++i) {
			double b = rand() / (double)RAND_MAX;
			net->biases[i] = (i & 1) ? -b : b;
		}
	}
	if (!net->vals)
		net->vals = malloc(net->nbs * sizeof(double));
}

void
delNet(struct net *const net)
{
	free(net->weights);
	free(net->biases);
	free(net->vals);
	free(net->b1);
	free(net->b2);
}

int
main()
{
	size_t lyrs[NLYRS] = {LYRS}, succ = 0, epoch = 0;
	double rs[STAGES] = {STAGE_RATES}, *optWs, *optBs,
	outbuff[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, acc = 0, minErr;
	const double ps[4] = {0.9, 0.975, 0.975, 1};

	net.layers = lyrs;
	net.nlayers = NLYRS;
	openFiles();
	srand(time(0));
	initNet(&net);
	optWs = malloc(net.nws * sizeof(double));
	optBs = malloc(net.nbs * sizeof(double));

	for (size_t i = 0; i < testSamples; ++i) {
		outbuff[(int)testOut[i]] = 1.0;
		acc += dsquare(feedforward(&net, testIn + i * net.layers[0]),
		    outbuff, net.layers[net.nlayers - 1]);
		outbuff[(int)testOut[i]] = 0.0;
	}
	printf("Total initial error: %.3f\n", acc);
	minErr = acc;

	uint8_t misses = 0;
	printf("Training network\n");
	for (int i = 0; i < STAGES; ++i) {
		net.rate = rs[i];
		printf("\n--- Stage %d/%d, Learning rate: %.2f ---\n", (i + 1), STAGES, rs[i]);
		while (1) {
			for (size_t j = 0; j < trainSamples; ++j) {
				outbuff[(int)trainOut[j]] = 1.0;
				if (!(rand() & 7))
					dropforward(&net, trainIn + j *
					    net.layers[0], ps);
				else
					feedforward(&net, trainIn + j *
					    net.layers[0]);
				train(&net, trainIn + j * net.layers[0],
				    outbuff);
				outbuff[(int)trainOut[j]] = 0.0;
			}
			acc = 0;
			for (size_t j = 0; j < testSamples; ++j) {
				outbuff[(int)testOut[j]] = 1.0;
				acc += dsquare(feedforward(&net, testIn + j *
				   net.layers[0]),
				    outbuff, net.layers[net.nlayers - 1]);
				outbuff[(int)testOut[j]] = 0.0;
			}
			printf("Epoch #%ld accumulated error: %.3f\n", ++epoch, acc);
			if (acc < minErr) {
				misses = 0;
				minErr = acc;
				memcpy(optWs, net.weights, net.nws * sizeof(double));
				memcpy(optBs, net.biases, net.nbs * sizeof(double));
			} else if (++misses >= 10) {
				misses = 0;
				double *tmp = net.weights;
				net.weights = optWs;
				optWs = tmp;
				tmp = net.biases;
				net.biases = optBs;
				optBs = tmp;
				break;
			}
		}
	}

	for (size_t i = 0; i < testSamples; ++i)
		succ += maxidx(feedforward(&net, testIn + i * net.layers[0])) ==
		    testOut[i];
	printf("Final success rate: %.2f%%\n", 100 * (double)succ/testSamples);

	delNet(&net);
	free(trainIn);
	free(trainOut);
	free(testIn);
	free(testOut);
	free(optWs);
	free(optBs);
	return 0;
}
