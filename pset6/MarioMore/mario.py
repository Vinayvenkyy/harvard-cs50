from cs50 import get_int

def main():
    while True:
        height = get_int("Height of pyramid: ")
        if height > 0 and height < 9:
            break
        else:
            print("**** Enter valid height ****")
    pyramid(height)

def pyramid(height):
    for i in range(1,height+1 ):
        print(" "*(height - i ) + "#"*i + "  "+ "#"* i)
    
if __name__ == "__main__":
    main()