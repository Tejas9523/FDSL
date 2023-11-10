# function for selection sort
def ssort(arr,l):
    print("Before selection sort - ",arr)
    for i in range(l):
        m=i
        for j in range(i+1,l):
            if(arr[j]<arr[m]):
                m=j
        arr[i],arr[m]=arr[m],arr[i]
    print("After selection sort - ",arr)


# function for bubble sort
def bsort(arr,l):
    print("Before Bubble  sort - ",arr)
    for i in range(l-1):
        for j in range(l-i-1):
            if(arr[j]>arr[j+1]):
                arr[j],arr[j+1]=arr[j+1],arr[j]
    print("After Bubble sort - ",arr)


# functio for getting data
def get(marks , n):
    for i in range(n):
        e=int(input("Enter element : "))
        marks.append(e)


        
k=1
while(k==1):
    marks=[]
    print("\nSelect option to perform : ")
    print("1) Selection sort")
    print("2) Bubble sort")
    print("3) Exit")
    ch=input("Enter choice - ")
    if(ch==1):
        n=int(input("Enter no elements - "))
        get(marks ,n)
        ssort(marks,n)
    elif(ch==2):
        n=int(input("Enter no elements - "))
        get(marks ,n)
        bsort(marks,n)
    elif(ch==3):
        k=0
    else:
        print("Please enter correct choice...!")
