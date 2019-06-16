n = 5
p = [1.0/n for i in range(n)]
world=['green', 'red', 'red', 'green', 'green']
measurements = ['red','red']
motions = [1,1] 
pHit = .6; pMiss = .2

def sense(p, Z):
    q = [p[i]*pHit if world[i] == Z else p[i]*pMiss for i in range(len(p))]
    s = sum(q)
    q = [i/s for i in q]
    return q

#for m in measurements:
#    p = sense(p,m) 

p = [0,1,0,0,0]
def exact_move(p, U):
    return [p[(i-U)%len(p)] for i in range(len(p))]

print exact_move(p, 1)

pExact = 0.8
pOvershoot = 0.1
pUndershoot = 0.1

def inexact_move(p, U):
    q = [0 for i in range(len(p))]
    for i in range(len(p)):
        val = p[i]
        q[(i+U-1)%len(q)] += val*pUndershoot 
        q[(i+U)%len(q)] += val*pExact
        q[(i+U+1)%len(q)] += val*pOvershoot
    return q
    

## Will give uniform distribution
#times = 1000
#for i in range(times):
#    p = inexact_move(p, 1)

## Sense and move
p = [1.0/n for i in range(n)]
for x,y in zip(measurements, motions):
    p = sense(p, x)
    p = inexact_move(p, y)

print max(p)
print p  