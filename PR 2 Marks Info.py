def Avg(score):
    sum=0
    for val in score:
        if val != -1:
            sum=sum+val
    avg=sum/len(score)
    return avg

def HighLow(score):
    h=score[0]
    l=score[0]
    for val in score:
        if val > h:
            h=val
        if val != -1 and val < l:
            l=val
    return h,l

def Absent(score):
    count=0
    for val in score:
        if val == -1:
            count=count+1
    return count

def Frequency(score):
    max=0
    i=0
    print("Marks  |  frequency")
    for j in score:
        if score.index(j)==i:
            print(j,"  |  ",score.count(j))
            if score.count(j)>max:
                max=score.count(j)
                ml=j
        i=i+1
    return ml,max
            
           
print("Score Information")
marks=[]
num=int(input("Enter total number of students :"))
print("Enter Marks serially (For absent student enter -1):")
for i in range(0,num):
    print("Enter marks of student ",i+1)
    ele=int(input())
    marks.append(ele)
print("marks of studentd :",marks)

flag=1
while flag==1:
    print("1.Average Score of class")
    print("2.Highest score and lowest score of class")
    print("3.count of the students who are absent")
    print("4.Marks With highest frequency")
    print("5.Exit")

    ch=int(input("Enter Your Choice :"))

    if ch==1:
        print("Average score of class :",Avg(marks))
    elif ch==2:
        print("Highest and Lowest Score of class :",HighLow(marks))
    elif ch==3:
        print("Number of Absent Students :",Absent(marks))
    elif ch==4:
        print("Marks With highest freqency :",Frequency(marks))
    elif ch==5:
        print("Program End successfully")
        flag=0
    else:
        print("You have entered wrong choice ")
    
