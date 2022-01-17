from cs50 import get_string
import re

def main():
    sentence = get_string("Text: ")
    grade(sentence)
    
def grade(sentence):
    count_letters = 0
    
    for i in range(len(sentence)):
        if sentence[i].isalpha():
            count_letters += 1
    
    count_words = len(sentence.split())
    count_sentences = len(re.split("[.!?]", sentence)) - 1
    
    L = round((count_letters * 100) / count_words, 2)
    S = round((count_sentences * 100) / count_words, 2)
    
    
    index = 0.0588 * L - 0.296 * S - 15.8
    index = round(index)
    
    if (index >= 16):
        print("Grade 16+")
    elif index <= 1:
        print("Before Grade 1")
    else:
        print("Grade " + str(index))

    
if __name__ == "__main__":
    main()