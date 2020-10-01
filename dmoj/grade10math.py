#!python3

# Python program to find largest power of  
# a number (which may be composite) that 
# divides factorial. 
import math 
  
# For find maximum power of prime number  
# p which can divide fact number 
def findPowerPrime(fact, p): 
    res = 0
    while fact:      
        res += fact // p 
        fact //= p 
  
    return res 
  
# Returns sum of all factors of n 
def findPowerComposite(fact, n): 
      
    # To store result (minimum power of a  
    # prime factor that divides fact! ) 
    res = math.inf 
  
    # Traverse through all prime factors 
    # of n. 
    for i in range(2, int(n**0.5) + 1):  
  
        # Counter for count the 
        # power of prime number 
        count = 0
        if not n % i: 
            count += 1
            n = n // i 
  
        if count: 
  
            # Maximum power of i that divides  
            # fact!. We divide by count to handle 
            # multiple occurrences of a prime factor. 
            curr_pow = findPowerPrime(fact, i) // count 
            res = min(res, curr_pow) 
  
    # This condition is to handle 
    # the case when n is a prime 
    # number greater than 2. 
    if n >= 2: 
        curr_pow = findPowerPrime(fact, n) 
        res = min(res, curr_pow) 
  
    return res 
  
  
# Driver code 
  
n, fact = map(int, input().split())
print(findPowerComposite(fact, n)) 
  
  
# This code is contributed by Ansu Kumari 
