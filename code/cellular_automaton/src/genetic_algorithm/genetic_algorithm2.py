import math
import random


def poblacion_inicial(max_poblacion, num_vars):
    # Crear poblacion inicial aleatoria
    poblacion = []
    for i in range(max_poblacion):
        gen = []
        for j in range(num_vars):
            if random.random() > 0.5:
                gen.append(1)
            else:
                gen.append(0)
        poblacion.append(gen[:])
    return poblacion


def adaptacion_3sat(gen, solucion):
    # contar clausulas correctas
    n = 3
    cont = 0
    clausula_ok = True
    for i in range(len(gen)):
        n = n - 1
        if gen[i] != solucion[i]:
            clausula_ok = False
        if n == 0:
            if clausula_ok:
                cont = cont + 1
            n = 3
            clausula_ok = True
    if n > 0:
        if clausula_ok:
            cont = cont + 1
    return cont


def evalua_poblacion(poblacion, solucion):
    # evalua todos los genes de la poblacion
    adaptacion = []
    for i in range(len(poblacion)):
        adaptacion.append(adaptacion_3sat(poblacion[i], solucion))
    return adaptacion


def seleccion(poblacion, solucion):
    adaptacion = evalua_poblacion(poblacion, solucion)
    # suma de todas las puntuaciones
    total = 0
    for i in range(len(adaptacion)):
        total = total + adaptacion[i]
    # escogemos dos elementos
    val1 = random.randint(0, total)
    val2 = random.randint(0, total)
    sum_sel = 0
    for i in range(len(adaptacion)):
        sum_sel = sum_sel + adaptacion[i]
        if sum_sel >= val1:
            gen1 = poblacion[i]
            break
    sum_sel = 0
    for i in range(len(adaptacion)):
        sum_sel = sum_sel + adaptacion[i]
        if sum_sel >= val2:
            gen2 = poblacion[i]
            break
    return gen1, gen2


def cruce(gen1, gen2):
    # creuza 2 genes y obtiene 2 descendientes
    nuevo_gen1 = []
    nuevo_gen2 = []
    corte = random.randint(0, len(gen1))
    nuevo_gen1[0:corte] = gen1[0:corte]
    nuevo_gen1[corte:] = gen2[corte:]
    nuevo_gen2[0:corte] = gen2[0:corte]
    nuevo_gen2[corte:] = gen1[corte:]
    return nuevo_gen1, nuevo_gen2


def mutacion(prob, gen):
    # muta un gen con una probabilidad prob
    if random.random() < prob:
        cromosoma = random.randint(0, len(gen))
        if gen[cromosoma - 1] == 0:
            gen[cromosoma - 1] = 1
        else:
            gen[cromosoma - 1] = 0
    return gen


def elimina_peores_genes(poblacion, solucion):
    # elimina los dos peores genes
    adaptacion = evalua_poblacion(poblacion, solucion)
    i = adaptacion.index(min(adaptacion))
    del poblacion[i]
    del adaptacion[i]
    i = adaptacion.index(min(adaptacion))
    del poblacion[i]
    del adaptacion[i]


def mejor_gen(poblacion, solucion):
    # devuelve el mejor gen de la poblacion
    adaptacion = evalua_poblacion(poblacion, solucion)
    return poblacion[adaptacion.index(max(adaptacion))]


def algoritmo_genetico():
    max_iter = 10
    max_poblacion = 50
    num_vars = 10
    fin = False
    solucion = poblacion_inicial(1, num_vars)[0]
    poblacion = poblacion_inicial(max_poblacion, num_vars)

    iteraciones = 0
    while not fin:
        iteraciones = iteraciones + 1
        for i in range(len(poblacion) // 2):
            gen1, gen2 = seleccion(poblacion, solucion)
            nuevo_gen1, nuevo_gen2 = cruce(gen1, gen2)
            nuevo_gen1 = mutacion(0.1, nuevo_gen1)
            nuevo_gen2 = mutacion(0.1, nuevo_gen2)
            poblacion.append(nuevo_gen1)
            poblacion.append(nuevo_gen2)
            elimina_peores_genes(poblacion, solucion)

        if max_iter < iteraciones:
            fin = True

    print("Solucion: " + str(solucion))
    mejor = mejor_gen(poblacion, solucion)
    return mejor, adaptacion_3sat(mejor, solucion)


if __name__ == "__main__":
    random.seed()
    mejor_gen = algoritmo_genetico()
    print("Mejor gen encontrado:" + str(mejor_gen[0]))
    print("Funcion de adaptacion: " + str(mejor_gen[1]))
