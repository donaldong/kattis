#  @brief   Kattis - House of Cards 
#  @author  Donald Dong (@donaldong)
#  @date    MM/DD/YYYY
#  
#  + Big Integer
#  + Combinatorial
#

h0 = input()
h = int(h0)
while h * (3 * h + 1) % 8 != 0:
    h = h + 1
print(h)
