data1=int(input())
count=1
my_list=[]
result_list=[]

for i in range(1,data1+1): # n번 만큼 작동
    data2=int(input())
    while count <= data2:
        my_list.append(count)
        result_list.append("+")
        count+=1
    if(my_list[-1]==data2):
        my_list.pop(-1)
        result_list.append("-")
    else:
        print("NO")
        exit(0)

print('\n'.join(result_list))