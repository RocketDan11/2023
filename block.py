import numpy as np

#generate test array
X  = np.arange(1, 65).reshape(8, 8)
           
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
    print(quadrant1)

print(block(X))
