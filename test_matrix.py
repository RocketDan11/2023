def test_matrix(n, m):
    matrix = []
    for i in range(n):
        row = []
        for j in range(m):
            #element can be changed here.
            element = 1  
            row.append(element)
        matrix.append(row)
    return matrix