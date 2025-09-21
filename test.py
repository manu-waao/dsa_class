import matplotlib.pyplot as plt
import numpy as np
x = np.linspace(5,100,20)
y = 5*x + 2*np.log(x)
big_oh = 7*x
big_omega = 5*x
small_oh = 7*x**1.1
small_omega = 5*x**0.9

plt.plot(x , y , label="f(x) = 5x+2logx" , marker='o')
plt.plot(x , big_oh ,label="Big oh" ,marker="o")
plt.plot(x , big_omega ,label="Big omega" ,marker="o")
plt.plot(x , small_oh ,label="small oh" ,marker="o")
plt.plot(x , small_omega ,label="small omega" ,marker="o")
plt.title("Graphical Representation 5x+2logx")
plt.xlabel("x")
plt.ylabel("y")
plt.grid(True)
plt.legend()
plt.show()
