import matplotlib.pyplot as plt

# Define the x values
x = list(range(1, 10))

# non-decreasing function
y1 = [1, 2, 3, 4, 5, 6, 7, 8, 9]
# non-increasing function
y2 = [9, 8, 7, 6, 5.7, 5.3, 4, 3, 2]

y = [min(y1[i], y2[i])-0.1 for i in range(len(x))]

# Plot the functions
plt.figure(figsize=(8, 6))
plt.plot(x, y1, marker='o', linestyle='--', color='blue', label='Non-decreasing Function')
plt.plot(x, y2, marker='s', linestyle='--', color='green', label='Non-increasing Function')
plt.plot(x, y, marker='s', linestyle='--', color='red', label='min')



# Add labels, title, and legend
plt.text(9, y1[-1]+0.4, r'$y=f_1(x)$', fontsize=10, color='blue', va='center')
plt.text(9, y2[-1]+0.4, r'$y=f_2(x)$', fontsize=10, color='green', va='center')
plt.text(7, y[6]+0.4, r'$y=min(f_1(x), f_2(x))$', fontsize=10, color='red', va='center')

plt.gca().spines['top'].set_visible(False)
plt.gca().spines['right'].set_visible(False)
# plt.gca().spines['left'].set_visible(False)
# plt.gca().spines['bottom'].set_visible(False)

# plt.legend()

# fade whole plot
plt.gca().set_alpha(0.1)

plt.text(x[4], y[4]-0.5, 'p1', fontsize=10, ha='center', va='bottom', color='red')
plt.text(x[5], y[5]-0.5, 'p2', fontsize=10, ha='center', va='bottom', color='red')
# plt.text(x[2], y[2]-0.5, 'j', fontsize=10, ha='center', va='bottom', color='red')
# plt.text(x[5], y[5]-0.5, 'j+k', fontsize=10, ha='center', va='bottom', color='red')

# Show the plot
plt.show()