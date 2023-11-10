
# function for getting marks in array
def getdata(arr,n):
    for i in range(n):
        marks=int(input("Enter marks of student - "))
        arr.append(marks)
    #print(arr)

# function fr calculating an average    
def avg(arr,n):
    sum1=0
    for i in range(n):
        marks=arr[i]
        sum1=sum1+arr[i]
    average=sum1/n
    print("Average is - ",average)

# function for counting absent students
def absent(arr,n):
    ab=0
    for i in range(n):
        if(arr[i]<=0):
            ab=ab+1
    print("Number of Present students - ",n-ab)
    print("Number of Absent students - ",ab)

# function for calculating min and max marks            
def min_max(arr,n):
    mn=arr[0]
    mx=arr[0]
    for i in range(n):
        if(arr[i]<=mn):
            mn=arr[i]
        elif(arr[i]>=mx):
            mx=arr[i]
    print("Highest score is ",mx)
    print("Lowest score is ",mn)

# function to calculate marks with highest frequency
def most_freq_marks(student_marks , student_count ):
    Max = 0
    temp = []
    for i in student_marks:
        if(student_marks.count(i) > Max):
            Max = student_marks.count(i)
    for j in student_marks:
        if(student_marks.count(j) == Max and (j not in temp)):
            temp.append(j)
    if(Max == 1):
        print("\nThere are no elements with repetative entries")
    else:
        print(temp)


# *****************************main******************************

n=int(input("Enter a No of student - "))
arr=[]

ans=True
while(ans):
    print("\n1.Enter marks")
    print("2.Average")
    print("3.Absent student")
    print("4.Minimum and Maximum marks")
    print("5.Frequency count")
    print("6.Exit")
    ch=int(input("\nEnter correct choice - "))
    if(ch==1):
        getdata(arr,n);
    elif(ch==2):
        avg(arr,n);
    elif(ch==3):
        absent(arr,n);
    elif(ch==4):
        min_max(arr,n);
    elif(ch==5):
        most_freq_marks(arr, n);
    elif(ch==6):
        ans=False
    else:
        print("\nEnter correct choice ...!!!")
