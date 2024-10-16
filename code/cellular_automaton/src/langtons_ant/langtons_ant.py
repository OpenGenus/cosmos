import turtle
import numpy


def update_maps(graph, turtle, color):
    graph[turtle_pos(turtle)] = color
    return None


def turtle_pos(turtle):
    return (round(turtle.xcor()), round(turtle.ycor()))


def langton_move(turtle, pos, maps, step):
    if pos not in maps or maps[pos] == "white":
        turtle.fillcolor("black")
        turtle.stamp()
        update_maps(maps, turtle, "black")
        turtle.right(90)
        turtle.forward(step)
        pos = turtle_pos(turtle)
    elif maps[pos] == "black":
        turtle.fillcolor("white")
        update_maps(maps, turtle, "white")
        turtle.stamp()
        turtle.left(90)
        turtle.forward(step)
        pos = turtle_pos(turtle)
    return pos


def move():
    # Screen
    BACKGROUND_COLOR = "white"
    WIDTH = 2000
    HEIGHT = 2000
    # Ant
    SHAPE = "square"
    SHAPE_SIZE = 0.5
    SPEED = -1
    STEP = 11

    # Data structure ex. {(x, y): "black", ..., (x_n, y_n): "white"}
    maps = {}

    # Initialize Window
    window = turtle.Screen()
    window.bgcolor(BACKGROUND_COLOR)
    window.screensize(WIDTH, HEIGHT)

    # Initialize Ant
    ant = turtle.Turtle()
    ant.shape(SHAPE)
    ant.shapesize(SHAPE_SIZE)
    ant.penup()
    ant.speed(SPEED)
    ant.right(180)
    pos = turtle_pos(ant)

    moves = 0
    while True:
        pos = langton_move(ant, pos, maps, STEP)
        moves += 1
        print("Movements:", moves)


move()
