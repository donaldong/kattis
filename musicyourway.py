title = input().split()
attrs = {x: i for i in range(len(title), )}
n = int(input())
songs = [None] * n
for i in range(n):
    songs[i] = input().split()
m = int(input())
for i in range(m):
    k = attrs[input()]
    songs.sort(key=lambda x: x[k])
    print(" ".join(title))
    for song in songs:
        print(" ".join(song))
