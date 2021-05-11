### Imports required for this solution

import math
import random as rdm

###############

############ Quantum Part (START) ############

### QuantumMapping: Keeps track of state and amplitude of an electron.


class QuantumMapping:
    def __init__(self, state, amplitude):
        self.state = state
        self.amplitude = amplitude


###############

### QuantumState: Keeps track properties amplitude, register, and entangled list.


class QuantumState:
    def __init__(self, amplitude, register):
        self.amplitude = amplitude
        self.register = register
        self.entangled = {}

    ## entangle(fromState, amplitude): Sets the entangled to QuantumState initialised with fromState.

    def entangle(self, fromState, amplitude):
        register = fromState.register
        entanglement = QuantumMapping(fromState, amplitude)
        try:
            self.entangled[register].append(entanglement)
        except KeyError:
            self.entangled[register] = [entanglement]

    ## entangles(register): Returns the length of the entangled states.
    def entangles(self, register=None):
        entangles = 0
        if register is None:
            for states in self.entangled.values():
                entangles += len(states)
        else:
            entangles = len(self.entangled[register])
        return entangles


###############

### QuantumRegister: Contains numBits, numStates, entangled list and states array.


class QuantumRegister:
    def __init__(self, numBits):
        self.numBits = numBits
        self.numStates = 1 << numBits
        self.entangled = []
        self.states = [QuantumState(complex(0.0), self) for x in range(self.numStates)]
        self.states[0].amplitude = complex(1.0)

    ## propagate(fromRegister): Sets the propagate on the register.

    def propagate(self, fromRegister=None):
        if fromRegister is not None:
            for state in self.states:
                amplitude = complex(0.0)
                try:
                    entangles = state.entangled[fromRegister]
                    for entangle in entangles:
                        amplitude += entangle.state.amplitude * entangle.amplitude
                    state.amplitude = amplitude
                except KeyError:
                    state.amplitude = amplitude
        for register in self.entangled:
            if register is fromRegister:
                continue
            register.propagate(self)

    ## map(toRegister, mapping, propagate): Sets the normalized tensor X and Y lists.

    def map(self, toRegister, mapping, propagate=True):
        self.entangled.append(toRegister)
        toRegister.entangled.append(self)
        mapTensorX = {}
        mapTensorY = {}
        for x in range(self.numStates):
            mapTensorX[x] = {}
            codomain = mapping(x)
            for element in codomain:
                y = element.state
                mapTensorX[x][y] = element
                try:
                    mapTensorY[y][x] = element
                except KeyError:
                    mapTensorY[y] = {x: element}

        def normalize(tensor, p=False):
            lSqrt = math.sqrt
            for vectors in tensor.values():
                sumProb = 0.0
                for element in vectors.values():
                    amplitude = element.amplitude
                    sumProb += (amplitude * amplitude.conjugate()).real
                normalized = lSqrt(sumProb)
                for element in vectors.values():
                    element.amplitude = element.amplitude / normalized

        normalize(mapTensorX)
        normalize(mapTensorY, True)

        # Entangle the registers
        for x, yStates in mapTensorX.items():
            for y, element in yStates.items():
                amplitude = element.amplitude
                toState = toRegister.states[y]
                fromState = self.states[x]
                toState.entangle(fromState, amplitude)
                fromState.entangle(toState, amplitude.conjugate())

        if propagate:
            toRegister.propagate(self)

    ## measure(): Returns the final X state.

    def measure(self):
        measure = rdm.random()
        sumProb = 0.0

        # Pick a state
        finalXval = None
        finalState = None
        for x, state in enumerate(self.states):
            amplitude = state.amplitude
            sumProb += (amplitude * amplitude.conjugate()).real
            if sumProb > measure:
                finalState = state
                finalXval = x
                break

        # If state was found, update the system
        if finalState is not None:
            for state in self.states:
                state.amplitude = complex(0.0)
            finalState.amplitude = complex(1.0)
            self.propagate()
        return finalXval

    ## entangles(): Returns the entangled state value.

    def entangles(self, register=None):
        entanglevals = 0
        for state in self.states:
            entanglevals += state.entangles(None)
        return entanglevals

    ## amplitudes(): Returns the amplitudes array based on the Quantum States.

    def amplitudes(self):
        amplitudesarr = []
        for state in self.states:
            amplitudesarr.append(state.amplitude)
        return amplitudesarr


###############

### ListEntangles(register): Print list of entangles.


def ListEntangles(register):
    print("Entangles: " + str(register.entangles()))


###############

### ListAmplitudes(register): Print values of amplitudes of the register.


def ListAmplitudes(register):
    amplitudes = register.amplitudes()
    for x, amplitude in enumerate(amplitudes):
        print("State #" + str(x) + "'s Amplitude value: " + str(amplitude))


###############

### hadamard(lambda_x, QBit): Returns the codomain array after appending the Quantum Mapping of the QBits.

def hadamard(x, Q):
    codomainarr = []
    for y in range(Q):
        amplitude = complex(pow(-1.0, bitCount(x & y) & 1))
        codomainarr.append(QuantumMapping(y, amplitude))
    
    return codomainarr


###############

### QModExp(a_value, exp_val, mod_value): Quantum Modular Exponentiation.


def QModExp(a_val, exp_val, mod_val):
    state = ModExp(a_val, exp_val, mod_val)
    amplitude = complex(1.0)
    return [QuantumMapping(state, amplitude)]


###############

### QFT(x, QBit): Quantum Fourier Transform


def QFT(x, Q):
    fQ = float(Q)
    k = -2.0 * math.pi
    codomainarr = []
    for y in range(Q):
        theta = (k * float((x * y) % Q)) / fQ
        amplitude = complex(math.cos(theta), math.sin(theta))
        codomainarr.append(QuantumMapping(y, amplitude))
    return codomainarr


###############

### FindPeriod(a, N): Returns the period 'r' for the function.


def FindPeriod(a, N):
    nNumBits = N.bit_length()
    inputNumBits = (2 * nNumBits) - 1
    inputNumBits += 1 if ((1 << inputNumBits) < (N * N)) else 0
    Q = 1 << inputNumBits

    print("Finding the period...")
    print("Q = " + str(Q) + "\ta = " + str(a))

    inputRegister = QuantumRegister(inputNumBits)
    hmdInputRegister = QuantumRegister(inputNumBits)
    qftInputRegister = QuantumRegister(inputNumBits)
    outputRegister = QuantumRegister(inputNumBits)

    print("Registers generated")
    print("Performing Hadamard on input register")

    inputRegister.map(hmdInputRegister, lambda x: hadamard(x, Q), False)

    print("Hadamard Success")
    print("Mapping input register to output register, where f(x) is a^x mod N")

    hmdInputRegister.map(outputRegister, lambda x: QModExp(a, x, N), False)

    print("Modular exponentiation success")
    print("Performing quantum Fourier transform on output register")

    hmdInputRegister.map(qftInputRegister, lambda x: QFT(x, Q), False)
    inputRegister.propagate()

    print("Quantum Fourier transform success")
    print("Performing a measurement on the output register")

    y = outputRegister.measure()

    print("Output register measured\ty = " + str(y))
    print("Performing a measurement on the periodicity register")

    x = qftInputRegister.measure()

    print("QFT register measured\tx = " + str(x))

    if x is None:
        return None

    print("Finding the period via continued fractions")

    rperiod = ContinuedFraction(x, Q, N)

    print("Candidate period\tr = " + str(rperiod))

    return rperiod


###############

############ Quantum Part (END) ############

############ Classical Functions for Shor's Algorithm (START) ############

### bitCount(x_value): Returns no. of set bits in x.

BIT_LIMIT = 12


def bitCount(x_val):
    sumBits = 0
    while x_val > 0:
        sumBits += x_val & 1
        x_val >>= 1

    return sumBits


###############

### GCD(a, b): Returns GCD(a,b) by using Euclid's Algorithm.


def GCD(a, b):
    while b != 0:
        rem = a % b
        a = b
        b = rem
    return a


###############

### ExtendedGCD(a, b): Returns GCD(a,b) using Extended Euclidean Algorithm.


def ExtendedGCD(a, b):
    fractions = []
    while b != 0:
        fractions.append(a // b)
        rem = a % b
        a = b
        b = rem

    return fractions


###############

### ContinuedFraction(y, Q, N): Returns a continued fraction based on partial fractions derived from extended GCD.


def ContinuedFraction(y, Q, N):
    fractions = ExtendedGCD(y, Q)
    depth = 2

    def partial(fractions, depth):
        c = 0
        r = 1
        for i in reversed(range(depth)):
            tR = fractions[i] * r + c
            c = r
            r = tR
        return c

    rcf = 0
    for d in range(depth, len(fractions) + 1):
        tR = partial(fractions, d)
        if tR == rcf or tR >= N:
            return rcf
        rcf = tR
    return rcf


###############

### ModExp(a, exp, mod): Returns (a^exp)%mod.


def ModExp(a, exp, mod):
    fx = 1
    while exp > 0:
        if (exp & 1) == 1:
            fx = fx * a % mod
        a = (a * a) % mod
        exp = exp >> 1

    return fx


###############

### Pick(N): Returns a random value < N.


def Pick(N_val):
    return math.floor((rdm.random() * (N_val - 1)) + 0.5)


###############

### CheckCandidates(a, r, n, neighbourhood): Returns candidates which have period 'r'.


def CheckCandidates(a, r, n, nbrhood):
    if r is None:
        return None

    # Check multiples
    for i in range(1, nbrhood + 2):
        tR = i * r
        if ModExp(a, a, N) == ModExp(a, a + tR, N):
            return tR

    # Check lower neighborhood
    for tR in range(r - nbrhood, r):
        if ModExp(a, a, N) == ModExp(a, a + tR, N):
            return tR

    # Check upper neigborhood
    for tR in range(r + 1, r + nbrhood + 1):
        if ModExp(a, a, N) == ModExp(a, a + tR, N):
            return tR
    return None


###############

############ Classical Functions for Shor's Algorithm (START) ############

###### The Main Shor's Algorithm ######

### ShorAlgo(N, attempts, neighborhood, no_of_periods): Runs Shor’s algorithm to find the prime factors of a given Number N.


def ShorAlgo(N, attempts=1, nbrhood=0.0, no_of_Periods=1):
    if N.bit_length() > BIT_LIMIT or N < 3:
        return False

    periods = []
    nbrhood = math.floor(N * nbrhood) + 1

    print("N = " + str(N))
    print("Neighborhood = " + str(nbrhood))
    print("Number of Periods = " + str(no_of_Periods))

    for attempt in range(attempts):
        print("\nAttempt #" + str(attempt))

        a = Pick(N)
        while a < 2:
            a = Pick(N)
        d = GCD(a, N)
        if d > 1:
            print("Found factors classically, re-attempt")
            continue

        r = FindPeriod(a, N)

        print("Checking candidate period, nearby values, and multiples")

        r = CheckCandidates(a, r, N, nbrhood)

        if r is None:
            print("Period was not found, re-attempt")
            continue

        if (r % 2) > 0:
            print("Period was odd, re-attempt")
            continue

        d = ModExp(a, (r // 2), N)
        if r == 0 or d == (N - 1):
            print("Period was trivial, re-attempt")
            continue

        print("Period found\tr = " + str(r))

        periods.append(r)
        if len(periods) < no_of_Periods:
            continue

        print("\nFinding LCM of all periods")

        r = 1
        for period in periods:
            d = GCD(period, r)
            r = (r * period) // d

        b = ModExp(a, (r // 2), N)
        f1 = GCD(N, b + 1)
        f2 = GCD(N, b - 1)

        return [f1, f2]

    return None


###############

### Driver-Code


def main():
    N = 35  # Integer whose Prime-Factorization is to be done
    attempts = 5  # Number of quantum attemtps to perform
    nbrhood = 0.01  # Neighborhood size for checking candidates (as percentage of N)
    periods = 2  # Number of periods to get before determining LCM

    factors = ShorAlgo(N, attempts, nbrhood, periods)
    if factors is not None:
        print("Factors:\t" + str(factors[0]) + ", " + str(factors[1]))


if __name__ == "__main__":
    main()

###############
