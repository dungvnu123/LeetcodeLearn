import csv

data = [
    ['Cao Manh Ha', '20', 'Hanoi'],
    ['Tran Anh Dung', '21', 'VinhPhuc'],
    ['Hoang Vu Nghi', '21', 'VinhPhuc']
]

with open('ex.csv', 'w', newline='') as file:
    writer = csv.writer(file)
    writer.writerows(data)

with open('ex.csv', 'r') as file :
    read = csv.DictReader(file)
    for row in read:
        print (row)