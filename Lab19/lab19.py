import time

#asciival converter, takes string and converts to ascii value
def asciival(str):
    hashAscii=[]
    hashAscii.append(time.time())#kind of double hashing by adding timestamp at the beggining
    for s in str:
        x=ord(s) # Ascii value
        hashAscii.append(x) # add to list
    changeVar(hashAscii)

#multiply function, multiple it by a specific number based on its position in the sequence
def changeVar(hashAscii):
    Counter=5
    integer=0
    while integer<len(hashAscii):
        hashAscii[integer]=hashAscii[integer]*Counter
        Counter+=5
        integer+=1
    salt(hashAscii)

#salt function, sums values, doubles them  and adds salt by the layout of current time of dayYearMonth
def salt(hashAscii):
    total=sum(hashAscii)
    total=str(total*7)+str(time.strftime("%d%y%m"))
    print("Your hashed string is: " +  total)
    return(total)

#Runs all the hashing process by calling other functions and returning hashed text
def doHash(string):
    return asciival(string)#Takes the text to ascii format

string=input("Please enter the text : ")
string=list(string)
doHash(string)

