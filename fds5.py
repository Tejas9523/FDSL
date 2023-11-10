def getdata(n):
    for i in range(n):
        e=int(input("Enter marks - "))
        arr.append(e)
    print("Before sort - ",arr)
    
    
def insort(arr,n):
    for i in range(1,n):
        a=arr[i]
        j=i-1
        while j >= 0 and a < arr[j]:
            arr[j+1] = arr[j]
            j=j-1
        arr[j+1]=a
    print("After sort - ",arr)
    
def shellSort(arr,n): 
    sublistcount = n//2
    while sublistcount > 0:
        for startposition in range(sublistcount): 
            gapInsertionSort(arr,startposition,sublistcount)

        print("After increments of size",sublistcount,"The list is",arr) 
        sublistcount = sublistcount // 2
def gapInsertionSort(arr,start,gap):
    for i in range(start+gap,len(arr),gap):
        currentvalue = arr[i] 
        position = i

        while position>=gap and arr[position-gap]>currentvalue: 
            arr[position]=arr[position-gap]
            position = position-gap 
            arr[position]=currentvalue


arr=[]
k=1
while(k==1):
    marks=[]
    print("\nSelect option to perform : ")
    print("1) Insertion sort")
    print("2) Shell sort")
    print("3) Exit")
    ch=input("Enter choice - ")
    if(ch=='1'):
    	n=int(input("Enter no elements - "))
    	getdata(n)
    	insort(arr,n)
    elif(ch=='2'):
    	n=int(input("Enter no elements - "))
    	getdata(n)
    	shellSort(arr,n)
    elif(ch=='3'):
        break
    else:
        print("Please enter correct choice...!")
