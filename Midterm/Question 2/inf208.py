import random

print("0-Spielen Sie das Spiel mit einem anderen Spieler")
print("1-Spielen Sie das Spiel gegen die CPU")
print("2-Lassen Sie die beiden CPU-Spieler das Spiel spielen")
print("3-Rock")
print("4-Papier")
print("5-Schere")

i = 10
p1 = 0
p2 = 0
g = 0

def choose1(k):
        if (k == 3):
            print("Player1 choosed Rock")
        if (k == 4):
            print("Player1 choosed Papier")
        if (k == 5):
            print("Player1 choosed Schere")


def choose2(i):
    if (i == 3):
        print("Player2 choosed Rock")
    if (i == 4):
        print("Player2 choosed Papier")
    if (i == 5):
        print("Player2 choosed Schere")

def vergleich(k,i):
    global p1
    global p2
    global g
    if(k == 3 and i ==3):
        print("Unentschieden Spielen")
        g += 1
    if(k == 4 and i == 4):
        print("Unentschieden Spielen")
        g += 1
    if(k == 5 and i == 5):
         print("Unentschieden Spielen")
         g += 1
    if(k == 3 and i == 4):
        print("Rock gegen Papier, Papier gewinnt")
        p2 +=1
    if(k == 3 and i == 5):
        print("Rock gegen Schere , Rock gewinnt")
        p1 += 1
    if(k == 4 and i == 3):
        print("Papier gegen Rock, Papier gewinnt")
        p1 += 1
    if(k == 4 and i == 5):
        print("Papier gegen Schere, Schere gewinnt")
        p2 += 1
    if(k == 5 and i == 3):
        print("Schere gegen Rock, Rock gewinnt")
        p2 += 1
    if(k == 5 and i == 4):
        print("Schere gegen Papier, Schere gewinnt")
        p1 += 1


while i != -1:
    i = int(input())
    if(i == 0):
        while i != -1:
            i = int(input())
            k = i
            if(k == -1):
                break
            choose1(k)
            i = int(input())
            if(i == -1):
                break
            choose2(i)
            vergleich(k,i)
    if(i == 1):
        while i != -1:
            k = random.randint(3,5)
            choose1(k)
            i = int(input())
            choose2(i)
            vergleich(k,i)
            if(i == -1):
                break
    if(i == 2):
        for k in range(7):
            x = random.randint(3,5)
            choose1(x)
            y = random.randint(3,5)
            choose2(y)
            vergleich(x,y)
        break

print("Spieler1: ",p1)
print("Spieler2 :", p2)
print("Total: ", p1+p2+g)