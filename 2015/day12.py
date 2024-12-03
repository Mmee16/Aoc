import json

def contains(obj):
    for i in obj:
        if type(obj[i]) == str and obj[i] == "red":
            return True
    return False


def parse_json(obj):
    summ=0
    if type(obj) == str:
        return 0
    if type(obj) == int:
        summ+=obj
        return summ;
    if type(obj) == list:
        for i in obj:
            if type(i) == int:
                summ+=i
            else:
                summ+=parse_json(i)
    elif type(obj) == dict:
        if contains(obj) == False:
            for i in obj:
                summ+=parse_json(obj[i])
    
    
    return summ



f = open('input.txt', 'r').read()
y = json.loads(f)
print(parse_json(y))
