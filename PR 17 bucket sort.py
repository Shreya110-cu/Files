def insertion_s(bucket):
    for i in range(1,len(bucket)):
        var=bucket[i]
        j=i-1
        while j>=0 and var < bucket[j]:
            bucket[j+1]=bucket[j]
            j=j-1
        bucket[j+1]=var

def bucket_s(marks):
    l=len(marks)
    maxx=max(marks)
    size=maxx/l

    buckets_list=[]
    for i in range(l):
        buckets_list.append([])
        
    for i in range(l):
        j=int(marks[i]/size)
        if j != l:
            buckets_list[j].append(marks[i])
        else:
            buckets_list[l-1].append(marks[i])

    for i in range(l):
        insertion_s(buckets_list[i])

    final_list=[]
    for i in range(l):
        final_list=final_list+buckets_list[i]
    return final_list
        


print("12 students percentage")
n=int(input("Enter total number of students :"))
score=[]
print("Enter Percentage :")
for i in range(n):
    ele=float(input())
    score.append(ele)

print("Unsorted Percentage of Students :",score)

sorted_score=bucket_s(score)

print("Sorted Percentage :",sorted_score)

print("Tpo Five Score :")
l=len(sorted_score)
for i in range(l-1,l-6,-1):
    print(sorted_score[i])
    
    








