n=int(input())
while n:
    m=int(input())
    a=list(map(int,input().split()))
    cursum=a[0]
    maxsum=a[0]
    start=0
    end=0
    for i in range(1,m,1):
        if a[i]>(cursum+a[i]):    #if a[i] is greater then start from there
          cursum=a[i] 
          start=i
        else:
          cursum=cursum+a[i]
        if cursum>maxsum:
          end=i                   #whenever maxsum changes, end changes
          maxsum=cursum
    if end<start:                 #NOTE : start exceeds end 
      start=end
      
   #max sum subsequence      

    a.sort()                      #sort elements
    if a[m-1]<0:                  #if max element is negative, all are negative
        print(maxsum)
        print(start,end)
        print(a[m-1])
    else:
        s=0
        for i in range(m-1,-1,-1):     #else sum till we have positive values
            if a[i]<0:
                break
            s+=a[i]
        print(maxsum)
        print(start,end)
        print(s)
    n=n-1
