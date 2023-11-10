from random import choice

while (True):
    print("Rock \nPaper \nScissors!!!!!")
    player1 = input("Enter your choice: ")
    choices = ["ROCK", "PAPER", "SCISSORS"]
    player2 = choice(choices)
    print("SHOOT!!!")
    print(f"player 2 played {player2}")
    if (player1 != player2):
        if (player1.upper() == "ROCK") and (player2.upper() == "SCISSORS"):
            print("player 1 wins")
        elif (player1.upper() == "SCISSORS") and (player2.upper() == "PAPER"):
            print("player 1 wins")
        elif (player1.upper() == "PAPER") and (player2.upper() == "ROCK"):
            print("player 1 wins")
        else:
            print("player 2 wins")
    else:
        print("Tied")
    print("---------------------------------------")
    flag = input("Do you want to continue? ")
    if flag.lower() == "no":
        break
    elif flag.lower() == "yes":
        continue