from cs50 import get_float

quarters = 25
dimes = 10
nickels = 5
pennies = 1

def main():
    while True:
        change_dollors = get_float("Change Owed: ")
        if change_dollors > 0:
            break
    
    change_cents = round(change_dollors*100 , 2 )
    greedy(change_cents)


def greedy(x):
    coin = 0
    while x != 0: 
        if x >= quarters:
            x = x - quarters
            coin += 1
        elif x >= dimes:
            x = x - dimes
            coin += 1
        elif x >= nickels:
            x = x - nickels
            coin += 1
        elif x >= pennies:
            x = x - pennies
            coin += 1
    print(coin)
    
if __name__ == "__main__":
    main()