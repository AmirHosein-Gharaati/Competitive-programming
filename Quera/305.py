def hcfnaive(a,b): 
    if(b==0): 
        return a 
    else: 
        return hcfnaive(b,a%b)


adad1 = int(input())
adad2 = int(input())
print(hcfnaive(adad1,adad2))
    
    

