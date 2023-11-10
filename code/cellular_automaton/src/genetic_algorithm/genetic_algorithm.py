import random

#
# Global variables
# Setup optimal string and GA input variables.
#

OPTIMAL = "Hello, World"
DNA_SIZE = len(OPTIMAL)
POP_SIZE = 20
GENERATIONS = 5000

#
# Helper functions
# These are used as support, but aren't direct GA-specific functions.
#


def weighted_choice(items):
    """
  Chooses a random element from items, where items is a list of tuples in
  the form (item, weight). weight determines the probability of choosing its
  respective item. Note: this function is borrowed from ActiveState Recipes.
  """
    weight_total = sum((item[1] for item in items))
    n = random.uniform(0, weight_total)
    for item, weight in items:
        if n < weight:
            return item
        n = n - weight
    return item


def random_char():
    """
  Return a random character between ASCII 32 and 126 (i.e. spaces, symbols,
  letters, and digits). All characters returned will be nicely printable.
  """
    return chr(int(random.randrange(32, 126, 1)))


def random_population():
    """
  Return a list of POP_SIZE individuals, each randomly generated via iterating
  DNA_SIZE times to generate a string of random characters with random_char().
  """
    pop = []
    for i in range(POP_SIZE):
        dna = ""
        for c in range(DNA_SIZE):
            dna += random_char()
        pop.append(dna)
    return pop


#
# GA functions
# These make up the bulk of the actual GA algorithm.
#


def fitness(dna):
    """
  For each gene in the DNA, this function calculates the difference between
  it and the character in the same position in the OPTIMAL string. These values
  are summed and then returned.
  """
    fitness = 0
    for c in range(DNA_SIZE):
        fitness += abs(ord(dna[c]) - ord(OPTIMAL[c]))
    return fitness


def mutate(dna):
    """
  For each gene in the DNA, there is a 1/mutation_chance chance that it will be
  switched out with a random character. This ensures diversity in the
  population, and ensures that is difficult to get stuck in local minima.
  """
    dna_out = ""
    mutation_chance = 100
    for c in range(DNA_SIZE):
        if int(random.random() * mutation_chance) == 1:
            dna_out += random_char()
        else:
            dna_out += dna[c]
    return dna_out


def crossover(dna1, dna2):
    """
  Slices both dna1 and dna2 into two parts at a random index within their
  length and merges them. Both keep their initial sublist up to the crossover
  index, but their ends are swapped.
  """
    pos = int(random.random() * DNA_SIZE)
    return (dna1[:pos] + dna2[pos:], dna2[:pos] + dna1[pos:])


#
# Main driver
# Generate a population and simulate GENERATIONS generations.
#

if __name__ == "__main__":
    # Generate initial population. This will create a list of POP_SIZE strings,
    # each initialized to a sequence of random characters.
    population = random_population()

    # Simulate all of the generations.
    for generation in range(GENERATIONS):
        print("Generation %s... Random sample: '%s'" % (generation, population[0]))
        weighted_population = []

        # Add individuals and their respective fitness levels to the weighted
        # population list. This will be used to pull out individuals via certain
        # probabilities during the selection phase. Then, reset the population list
        # so we can repopulate it after selection.
        for individual in population:
            fitness_val = fitness(individual)

            # Generate the (individual,fitness) pair, taking in account whether or
            # not we will accidently divide by zero.
            if fitness_val == 0:
                pair = (individual, 1.0)
            else:
                pair = (individual, 1.0 / fitness_val)

            weighted_population.append(pair)

        population = []

        # Select two random individuals, based on their fitness probabilites, cross
        # their genes over at a random point, mutate them, and add them back to the
        # population for the next iteration.
        for _ in range(POP_SIZE // 2):
            # Selection
            ind1 = weighted_choice(weighted_population)
            ind2 = weighted_choice(weighted_population)

            # Crossover
            ind1, ind2 = crossover(ind1, ind2)

            # Mutate and add back into the population.
            population.append(mutate(ind1))
            population.append(mutate(ind2))

    # Display the highest-ranked string after all generations have been iterated
    # over. This will be the closest string to the OPTIMAL string, meaning it
    # will have the smallest fitness value. Finally, exit the program.
    fittest_string = population[0]
    minimum_fitness = fitness(population[0])

    for individual in population:
        ind_fitness = fitness(individual)
        if ind_fitness <= minimum_fitness:
            fittest_string = individual
            minimum_fitness = ind_fitness

    print("Fittest String: %s" % fittest_string)
    exit(0)
