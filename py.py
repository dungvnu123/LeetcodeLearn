with open ('ex.txt', 'r') as file:
    lit = file.readlines()
    print(lit)
    #lien1 = file.readline(2)
    #print(lien1)

#     comment = file.read()
#     print(comment)
with open('ex.txt', 'a') as file:
    lits = ["\nLis1", "List2", "List3"]
    file.writelines(lits) 

# with open('ex.txt', 'w') as file:
#     file.write("Cao Manh Ha choi con thaM NGUEYn")    

# with open ('ex.txt', 'a') as file:
#     file.write("\nToi yeu cao manh ha ")
