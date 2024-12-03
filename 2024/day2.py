def is_lesser(nums):
    removed=False
    for i in range(1, len(nums)):
        diff=nums[i-1]-nums[i]
        if diff<=0 or diff>=4:
            if i==1:
                removed = True
                continue
            if removed== True:
                return 0
            if i==len(nums)-1:
                return 1
            diff=nums[i-1]-nums[i+1]
            if diff>0 and diff<4:
                removed=True
            else: return 0
    return 1

def is_greator(nums):
    removed=False
    for i in range(1, len(nums)):
        diff=nums[i]-nums[i-1]
        if diff<=0 or diff>=4:
            if i==1:
                removed = True
                continue
            if removed== True:
                return 0
            if i==len(nums)-1:
                return 1
            diff=nums[i+1]-nums[i-1]
            if diff>0 and diff<4:
                removed=True
            else: return 0
    return 1

def eval(nums,id):
    if is_greator(nums) == 1 or is_lesser(nums)== 1:
        print(id)
        return 1
    return 0

def convert(line):
    line=line.split(' ')
    for i in range(len(line)):
        line[i]=int(line[i])
    return line

file=open("day2inp.txt",'r')
count=0
id=0
for line in file:
    id+=1
    line=convert(line)
    count+=eval(line,id)
print(count)
