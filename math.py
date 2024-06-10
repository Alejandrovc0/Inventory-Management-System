import numpy as np
import matplotlib.pyplot as plt

# Choose a range for t
t_values = np.linspace(-2, 2, 100)

# Calculate x and y values
x_values = np.exp(t_values)
y_values = np.exp(3 * t_values) + 1

# Plot the points
plt.plot(x_values, y_values, label='Parametric Curve')
plt.scatter(x_values, y_values, color='red', label='Points')

# Add labels and title
plt.xlabel('x')
plt.ylabel('y')
plt.title('Parametric Curve: $x = e^t, y = e^{3t} + 1$')

# Add a legend
plt.legend()

# Show the plot
plt.show()