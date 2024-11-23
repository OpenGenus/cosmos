from random import choice

while (True):
    print("Rock \nPaper \nScissors!!!!!")
    player1 = input("Enter your choice: ").upper()
    choices = ["ROCK", "PAPER", "SCISSORS"]

    if player1 not in choices:
        print("Invalid choice, please choose ROCK, PAPER, or SCISSORS.")
        continue

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
    flag = input("Do you want to continue? ").lower()
    if flag.lower() == "no":
        break
    elif flag.lower() == "yes":
        continue