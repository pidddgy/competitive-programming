print((lambda a:str(a[0])+" "+str(a[len(a)-1])+" "+str((a[len(a)//2]+a[len(a)//2-((len(a)&1)^1)])/2))(sorted([int(x) for x in input().split()])))
