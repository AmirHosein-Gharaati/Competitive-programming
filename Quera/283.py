adad1 = int(input())
adad2 = int(input())

if adad2>=adad1 :
    print('Wrong order!')
elif (adad1 - adad2)%2 == 1:
    print('Wrong difference!')
else:
    for i in range(int((adad1-adad2)/2)):
        print(adad1*'* ')
    for i in range(adad2):
        print(int((adad1-adad2)/2)*'* '+ adad2*'  '+int((adad1-adad2)/2)*'* ')
    for i in range(int((adad1-adad2)/2)):
        print(adad1*'* ')