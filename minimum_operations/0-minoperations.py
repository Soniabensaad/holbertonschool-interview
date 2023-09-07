#!/usr/bin/python3
"""
Minimum Operations
"""
def minOperations(n):
    
    if n <= 1:
        return 0
    o = 0
    d = 2
    while n > 1:
        while n % d == 0:
            o += 2
            n //= d  
        d += 1
    return o


        
       