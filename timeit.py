#using a decorator to calculate execution time
#--------
import time
import math
import numpy as np

def timeit(func):
    #if function takes arguments, can be added like this
    def inner1(*args, **kwargs):
        begin = time.time()
        
        func(*args, **kwargs)
        
        end = time.time()
        
        print(time to execute : , func.__name__, end - begin)
        
    return inner1


#calling @timeit before function def will clock that function
#determinant of a 2x2 matrix
#----------
@timeit
def det(x):
    return x[0,0]*x[1,1] - x[0,1]*x[1,0]


#EXAMPLE

SIZE = 2
X = np.random.rand(SIZE,SIZE)

print(det(X))
