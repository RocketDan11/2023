import numpy as np

def det(x):
    return x[0,0]*x[1,1] - x[0,1]*x[1,0]

#generate test array
X  = np.arange(1, 65).reshape(8, 8)
Z  = np.arange(1, 17).reshape(4, 4)
           
def block(matrix):
    rows, cols = matrix.shape
    #base case, return itself
    if rows <= 2 and cols <= 2:
        return [matrix]

     # Split the matrix into four quadrants
    mid_row = rows // 2
    mid_col = cols // 2
    
    quadrant1 = matrix[:mid_row, :mid_col]
    quadrant2 = matrix[:mid_row, mid_col:]
    quadrant3 = matrix[mid_row:, :mid_col]
    quadrant4 = matrix[mid_row:, mid_col:]
    
    #recursively call block on each quadrant
    #store value in submatrix list.
    submatrix = []
    submatrix.extend(block(quadrant1))
    submatrix.extend(block(quadrant2))
    submatrix.extend(block(quadrant3))
    submatrix.extend(block(quadrant4))
   

    return submatrix

submatrix = block(X)

for sub in submatrix:
    print(sub)
    print(det(sub))

q1, q2, q3, q4 = block(Z)