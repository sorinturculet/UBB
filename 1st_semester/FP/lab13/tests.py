# def isSet(x):
#     return True
# def backtracking(x, DIM):
#     if len(x) == DIM:
#         print(x)
#         return  # Stop recursion
#     x.append(0)
#     for i in range(0, DIM):
#         x[-1] = i
#         if isSet(x):
#             # Continue only if x can lead to a solution
#             backtracking(x, DIM)
#
#     x.pop()
# backtracking([], 3)
#
#
# def consistentQ(x, dim):
#     # Check if the current queen conflicts with the previous queens
#     for i in range(len(x) - 1):
#         # No queen on the same column
#         if x[i] == x[-1]:
#             return False
#         # No queen on the same diagonal
#         if abs(i - len(x) + 1) == abs(x[i] - x[-1]):
#             return False
#     return True
#
# def solutionQ(x, dim):
#     # Check if a solution is found
#     return len(x) == dim
#
# def solutionFoundQ(x, dim):
#     # Print the chess board
#     for row in range(dim):
#         # Prepare a line
#         cLine = ["0"] * dim
#         cLine[x[row]] = "X"
#         print(" ".join(cLine))
#     print("__" * dim)
#
# def backRecQ(x, dim):
#     # Base case: check if a solution is found
#     if solutionQ(x, dim):
#         solutionFoundQ(x, dim)
#         return
#     # Recursive case: try placing the queen in each column
#     for i in range(dim):
#         x.append(i)
#         if consistentQ(x, dim):
#             backRecQ(x, dim)
#         x.pop()
#
# # Example usage:
# backRecQ([], 8)
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def prime_sum_backtracking(target_sum, current_sum, current_solution, current_number):
    if current_sum == target_sum:
        print(current_solution)
        return

    if current_sum > target_sum or not is_prime(current_number):
        return

    for i in range(current_number, target_sum):
        if is_prime(i):
            current_solution.append(i)
            prime_sum_backtracking(target_sum, current_sum + i, current_solution, i)
            current_solution.pop()


# Example usage:
target_sum = 7
prime_sum_backtracking(target_sum, 0, [], 2)
