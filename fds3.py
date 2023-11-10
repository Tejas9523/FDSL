#function to print matrix
def print_matrix(matrix ,  row , col):
    for i in range(row):
        for j in range(col):
            print(matrix[i][j] , end = "  ")
        print()
    print("---------------------------***----------------------------")

#function to input a matirx
def input_matrix(matrix , row , col):
    for i in range(row):
        matrix.append([])
        for j in range(col):
            m = int(input())
            matrix[i].append(m)

    return matrix


# function for Matrix transpose        
def trans(matrix , row , col):
    tran_matrix = []
    for i in range(row):
        tran_matrix.append([])
        for j in range(col):
            tran_matrix[i].append(matrix[j][i])
    print("Transpose :")
    print_matrix(tran_matrix , row , col)

# matrix addition function        
def add(matrix_1,matrix_2,row,col):
    add=[]
    for i in range(row):
        add.append([])
        for j in range(col):
            add[i].append(matrix_1[i][j] + matrix_2[i][j])
    print("Addition :")
    print_matrix(add , row , col)
    

# matrix substraction function        
def sub(matrix_1,matrix_2,row,col):
    add=[]
    for i in range(row):
        add.append([])
        for j in range(col):
            add[i].append(matrix_1[i][j] - matrix_2[i][j])
    print("Substraction :")
    print_matrix(add , row , col)

# matrix multiplication function        
def mul(matrix_1,matrix_2,row_1,row_2,col_1,col_2):
    multi_matrix = []
    for h in range(row_1):
        multi_matrix.append([])
        for k in range(col_2):
            multi_matrix[h].append(0)
    
    for i in range(row_1):
        for j in range(col_2):
            for m in range(row_2):
                multi_matrix[i][j] += matrix_1[i][m] * matrix_2[m][j]
    print("Multiplication :")
    print_matrix(multi_matrix , row_1, col_2)

matrix_1=[]
matrix_2=[]


# Matrix_1 get from user
print("\nMatrix 1 : ")
row_1=int(input("Enter number of rows - "))
col_1=int(input("Enter number of column - "))
print("Enter elements of 1st matrix - ")
input_matrix(matrix_1 , row_1 , col_1)
print("\nFirst Matrix is - ")
print_matrix(matrix_1 ,  row_1 , col_1)


# Matrix_2 get from user
print("\nMatrix 2 : ")
row_2=int(input("Enter number of rows - "))
col_2=int(input("Enter number of column - "))
print("Enter elements of 2nd matrix - ")
input_matrix(matrix_2 , row_2 , col_2)
print("\nSecond Matrix is - ")
print_matrix(matrix_2 ,  row_2 , col_2)

ans=True
while(ans):
    print("\n1.Transpose matrix_1")
    print("2.Transpose matrix_1")
    print("3.Addition")
    print("4.Substraction")
    print("5.Multiplication")
    print("6.Exit")
    ch=int(input("\nEnter correct choice - "))

    if(ch==1):
        #Transpose
        trans(matrix_1,row_1,col_1)
    elif(ch==2):
        trans(matrix_2,row_2,col_2)
    elif(ch==3):
        #Addition 
        if(row_1 == row_2 and col_1 == col_2):
            add(matrix_1,matrix_2,row_1,col_1)
        else:
            print("\nInvalid dimensions of matrix for this operation")
    elif(ch==4):
        #Substraction 
        if(row_1 == row_2 and col_1 == col_2):
            sub(matrix_1,matrix_2,row_1,col_1)
        else:
            print("\nInvalid dimensions of matrix for this operation")
    elif(ch==5):
        #Multiplication
        if(col_1==row_2):
            mul(matrix_1,matrix_2,row_1,row_2,col_1,col_2)
        else:
            print("\nInvalid dimensions of matrix for this operation")
    elif(ch==6):
        ans=False
    else:
        print("\nPlease Enter correct choice ...!!!")

    







