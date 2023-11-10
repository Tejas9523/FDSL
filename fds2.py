
# print length of a string
def length():
    print("\nLength of ",string ," is ",len(string))

# print occurence of character
def frq():
    n=input("\nEnter a character to check occurence - ")
    print("frequency of ",n," is ",string.count(n))

# to check palindrome or not 
def chk():
    if(string==string[::-1]):
        print("\nString is Palindrome")
    else:
        print("\nString is Not Plaindrome")

# find index of given substring
def sub():
    sub=input("\nEnter a substring - ")
    print("Index of ",sub," is ",string.index(sub))

# print charatcter occurence count
def ocr():
    for i in string:
        print(i," - ",string.count(i))



# input string from user
string=input("\nEnter string - ")

ans=True
while(ans):
    print("\n1.Length")
    print("2.Character occurence")
    print("3.Check Palindrome or not !")
    print("4.Substring index")
    print("5.Exit")
    ch=int(input("\nEnter correct choice - "))
    if(ch==1):
        length();
    elif(ch==2):
        frq();
    elif(ch==3):
        chk();
    elif(ch==4):
        ocr();
    elif(ch==5):
        ans=False
    else:
        print("\nEnter correct choice ...!!!")