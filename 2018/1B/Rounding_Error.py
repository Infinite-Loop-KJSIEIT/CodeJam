

def remain(x,N):
  return 100.*x/N-int(100.*x/N)

T = int(input())
for t in range(T):
  
  N, L = map(int,input().split())
  n = N
  a = list(map(int, list(input().split())))
  n -= sum(a)
  a = sorted(a, key = lambda x:remain(x,N), reverse = True)
  i = 0
  while n:
    if i==len(a):
      a += [1]
      n -= 1
      if n == 0:
        break
    if 0.5>remain(a[i],N)>0:
      a[i] += 1
      n -= 1
    else:
      i += 1 
  print('Case #%d: '%(t+1), sum(int(100.*c/N+0.5) for c in a) )   
