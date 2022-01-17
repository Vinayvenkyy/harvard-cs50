import sys
from cs50 import get_string
import csv

def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py CSV_FILE TXT_FILE ")

    columns = []
    rows = []

    #READ CSV FILE
    CSVfilename = sys.argv[1]
    with open(CSVfilename) as csvfile:
        reader = csv.reader(csvfile)
        columns = next(reader)

        for row in reader:
            rows.append(row)

    #READ THE TEXT FILE
    TXTfilename = sys.argv[2]
    with open(TXTfilename) as txtfile:
        sequence = txtfile.read()

    #Check for each sequence
    max_count = [0]*len(columns)
    for i in range(1,len(columns)):
        STR = columns[i]
        
        for j in range(len(sequence)):
            count = 0
            if (sequence[j:j+len(STR)] == STR):
               k = 0
               while (sequence[j+k:j+k+len(STR)] == STR):
                   count += 1
                   k += len(STR)
               if count > max_count[i]:
                   max_count[i] = count
                   
            
            
    max_count = max_count[1::]
    max_count = [str(x) for x in max_count]
    
    temp = 0
    for i in range(len(rows)):
        if (rows[i][1::] == max_count):
            print(rows[i][0])
            temp += 1
        elif i == len(rows) - 1 and temp == 0:
            print("No Match")
            
if __name__ == "__main__":
    main()