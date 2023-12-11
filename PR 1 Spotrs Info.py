print("Sports Information")
cricket=[]
badminton=[]
football=[]
cn=int(input("Enter number of students playing cricket: "))
bn=int(input("Enter number number of studentd palying badminton: "))
fn=int(input("Enter number on students playing football: "))

print("Enter names of student who play cricket: ")
for i in range(0,cn):
    cricket.append(input())
    
print("Enter names of student who play badminton: ")
for i in range(0,bn):
    badminton.append(input())
    
print("Enter names of student who play football: ")
for i in range(0,fn):
    football.append(input())

print("Student who play Cricket :",cricket)
print("Student who play badminton :",badminton)
print("Student who play football :",football)


def A(c,b):
    result=[]
    for val in c:
        if val in b:
            result.append(val)
    return result
print("List of Student who play cricket and badminton :",A(cricket,badminton))

def B(c,b):
    result=[]
    for val in c:
        if val not in b:
            result.append(val)
    for val in b:
        if val not in c:
            result.append(val)
    return result
print("list of Student who play either cricket or badminton but not both :",B(cricket,badminton))

def C(c,b,f):
    count=0
    for val in f:
        if val not in c and val not in b:
            count=count+1
    return count
print("Number of studentd who niether play cricket nor badminon :",C(cricket,badminton,football))

def D(c,b,f):
    result=[]
    count=0
    for val in c:
        if val in f:
            result.append(val)
    for val in result:
        if val not in b:
            count=count+1
    return count
print("Number of students who play cricket and football but not badminton :",D(cricket,badminton,football))
            











