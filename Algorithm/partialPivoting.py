def partial_pivot_solve(coefficients, constants):
    n = len(constants)
    A = coefficients
    b = constants
    for i in range(n):
        max_index = i + max(range(n-i), key=lambda k: abs(A[i+k][i]))
        if i != max_index:
            A[i], A[max_index] = A[max_index], A[i]
            b[i], b[max_index] = b[max_index], b[i]
        for j in range(i+1, n):
            factor = A[j][i] / A[i][i]
            b[j] -= factor * b[i]
            for k in range(i, n):
                A[j][k] -= factor * A[i][k]
    x = [0] * n
    for i in range(n-1, -1, -1):
        sum_ax = 0
        for j in range(i+1, n):
            sum_ax += A[i][j] * x[j]
        x[i] = (b[i] - sum_ax) / A[i][i]
    return x

coefficients = []
constants = []
row = list(map(float, input().split()))
coefficients.append(row[:-1])
constants.append(row[-1])
N = len(coefficients[0])
for _ in range(N - 1):
    row = list(map(float, input().split()))
    coefficients.append(row[:-1])
    constants.append(row[-1])

solution = partial_pivot_solve(coefficients, constants)
for i in range(1, N+1):
    print(f'x{i} = {solution[i-1]:.3f}')
