def simplify(n, m):
    k = len(n)
    l = len(m)
    for i in range(l - 1):
        j = k - i - 1
        if n[j] != '0':
            break
        else:
            n.pop(j)
            m.pop(l - i - 1)
    return n, m

def display(n, i):
    if i <= 0:
        print("".join(n))
    elif len(n) > i:
        j = len(n) - i
        print("".join(n[0:j]), end='.')
        print("".join(n[j:]))
    else:
        print('0.', end='')
        while len(n) < i:
            print('0', end='')
            i -= 1
        print("".join(n))

N = input()
M = input()
N, M = simplify(list(N), list(M))
display(N, len(M) - 1)
