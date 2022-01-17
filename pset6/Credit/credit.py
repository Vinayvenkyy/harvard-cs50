from cs50 import get_int

def main():
  number = get_int("Enter the number: ")
  cardType(number)

def is_valid(number):
  Num = []
  for digit in str(number):
    Num.append(int(digit))
 #PART 1 
  RevNum = Num[::-1]
  temp = RevNum[1::2]
  EvenList = [i*2 for i in temp]
  

  #SINGLE DIGIT LIST
  for element in range(len(EvenList)):
    if EvenList[element] > 9 :
      sum = 0
      for digit in str(EvenList[element]):
          sum = sum + int(digit)
      EvenList[element] = sum
      

  #SUM OF SINGLE DIGIT LIST
  sumEven = 0
  for digit in EvenList:
    sumEven = sumEven +  digit

 #PART 2
  OddList = RevNum[::2] 
  sumOdd = 0
  for digit in OddList:
    sumOdd = sumOdd + digit
  
 #PART 3
  SUM = sumEven + sumOdd

  if SUM % 10 == 0:
    return True

def cardType(number):
  if is_valid(number) == True:
    Num = []
    for digit in str(number):
      Num.append(int(digit))
    if (len(Num) == 15 and Num[0] == 3 and (Num[1] == 4 or Num[1] == 7)):
      print("AMEX")
    elif (len(Num) == 16 and Num[0] == 5 and (Num[1] == 1 or Num[1] == 2 or Num[1] == 3 or Num[1] == 4 or Num[1] == 5 )):
      print("MASTERCARD")
    elif ((len(Num) == 13 or len(Num) == 16) and Num[0] == 4):
      print("VISA")
  else :
    print("INVALID")


if __name__ == "__main__":
  main()