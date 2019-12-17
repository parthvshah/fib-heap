file = open("inp.txt").readlines()

p = []
q = []
odd = -1

for f in file:
    f = f.strip()
    if not f:
        continue
    if odd == -1:
        p.append(float(f.split()[2]))
    else:
        q.append(float(f.split()[2]))
    odd *= -1

print(p, sum(p)/len(p))
print(q, sum(q)/len(q))
