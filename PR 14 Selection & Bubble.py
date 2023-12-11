def selection_s(score):
    n=len(score)
    for i in range(n):
        min=i
        for j in range(i+1,n):
            if score[min]>score[j]:
                min=j
        score[i],score[min]=score[min],score[i]
                   
    print("After sorting Percentage :")
    for i in range(n):
        print(marks[i])

def bubble_sort(score):
    n=len(score)
    for i in range(n-1):
        for j in range(0,n-i-1):
            if score[j]>score[j+1]:
                score[j],score[j+1]=score[j+1],score[j]
   
    print("After sorting Percentage :")
    for i in range(n):
        print(marks[i])

def top(score):
    n=len(score)
    for i in range(n-1,n-6,-1):
       print(score[i])


print("First Year Percentage ")
marks=[]
no=int(input("Enter total number of student :"))
print("Enter Percentage")
for i in range(no):
    marks.append(float(input()))
print("Percentage :",marks)

flag=1
while flag==1:

    print("1.selection Sort")
    print("2. bubble sort")
    print("3. Exit")

    ch=int(input("Enter your choice :"))

    if ch==1:
        selection_s(marks)
        a=input("Are You Want to display top  5 percentage :(yes/no)")
        if a=='yes':
            top(marks)
        else:
            flag=0

    elif ch==2:
       bubble_sort(marks)
       a=input("Are You Want to display top  5 percentage :(yes/no)")
       if a=='yes':
            top(marks)
       else:
            flag=0
       
    elif ch==3:
        print("End Of Program")
        flag=0
    else:
        print("Entered wrong choice")
