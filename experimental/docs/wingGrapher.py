# Graphing Program for Project-Shire

# Import numpy and matplotlib for data visualization.
import matplotlib.pyplot as plt
import numpy as np

# Initialize Lists for graphing.
x_values = []
y_values = []
z1_values = []
z2_values = []

# Open and read file.
with open("output.csv", "r") as out:
    rawData = out.read()
    
# Split data by newlines.
splitData = rawData.split('\n')
# Split data by ','.
strData = [line.split(',') for line in splitData]

# Create labels for the graphs.
x_label = strData[0][3]
y_label = strData[0][2]
z1_label = strData[0][4]
z2_label = strData[0][5]

# Other Parameters
velocity = []
for i in strData:
    try:
        velocity.append(float(i[1]))
    except:
        continue

velocity = sorted([*set(velocity)])


# Convert string data to float for each list.
for group in strData:
    try:
        x_values.append(float(group[3]))
        y_values.append(float(group[2]))
        z1_values.append(float(group[4]))
        z2_values.append(float(group[5]))
    except:
        continue

# Convert lists to numpy arrays.
# 100 KIAS
# Wingspan
x_values_f = np.array(sorted([*set(x_values)]))
# Chord Length
y_values_f = np.array(sorted([*set(y_values)]))
# Lift-Wingspan
z1_values_f = np.array(z1_values[:len(x_values_f)])
# Drag-Wingspan
z2_values_f = np.array(z2_values[:len(x_values_f)])
# Lift-Chord TODO: Fix ALL Chord calcs
z3_values_f = np.array(z1_values[:len(y_values_f)])
# Drag-Chord TODO: Fix ALL Chord calcs
z4_values_f = np.array(z2_values[:len(y_values_f)])

# 125 KIAS
# Lift-Wingspan
z5_values_f = np.array(z1_values[63:(63 + len(x_values_f))])
# Drag-Wingspan
z6_values_f = np.array(z2_values[63:(63 + len(x_values_f))])
# Lift-Chord TODO: Fix ALL Chord calcs
z7_values_f = np.array(z1_values[63:(63 + len(y_values_f))])
# Drag-Chord TODO: Fix ALL Chord calcs
z8_values_f = np.array(z2_values[63:(63 + len(y_values_f))])

# 150 KIAS
# Lift-Wingspan
z9_values_f = np.array(z1_values[126:(126 + len(x_values_f))])
# Drag-Wingspan
z10_values_f = np.array(z2_values[126:(126 + len(x_values_f))])
# Lift-Chord TODO: Fix ALL Chord calcs
z11_values_f = np.array(z1_values[126:(126 + len(y_values_f))])
# Drag-Chord TODO: Fix ALL Chord calcs
z12_values_f = np.array(z2_values[126:(126 + len(y_values_f))])

print(z11_values_f)
print(z12_values_f)

# Print each array including the header. Toggle comment to enable/disable output.
print(x_label + ":\t\t", x_values_f)
print(y_label + ":\t\t", y_values_f)
print(z1_label + ":\t", z1_values_f)
print(z2_label + ":\t", z2_values_f)
print(z1_label + ":\t", z3_values_f)
print(z2_label + ":\t", z4_values_f)

# vvv --- For Debugging --- vvv #
# print(max(z1_values), np.where(z1_values == max(z1_values)), len(z1_values))
# print(max(z2_values), np.where(z2_values == max(z2_values)), len(z2_values))
# ^^^ --- For Debugging --- ^^^ #

# Graph output @ 100 KIAS.
plt.figure("Chord-Wingspan Relationship @ 100 KIAS")
plt.title("100 KIAS", fontdict=None, loc="center")
plt.subplot(211)
plt.plot(x_values_f, z1_values_f, 'g-', label='wingspan-lift')
plt.ylabel(z1_label + '/' + z2_label)
plt.xlabel(x_label)
plt.plot(x_values_f, z2_values_f, 'r-', label='wingspan-drag')
plt.legend()
plt.subplot(212)
plt.plot(y_values_f, z3_values_f, 'g-', label='chord-length-lift')
plt.ylabel(z1_label + '/' + z2_label)
plt.xlabel(y_label)
plt.plot(y_values_f, z4_values_f, 'r-', label='chord-length-drag')
plt.legend()

# Graph output @ 125 KIAS.
plt.figure("Chord-Wingspan Relationship @ 125 KIAS")
plt.title("125 KIAS", loc="center")
plt.subplot(211)
plt.plot(x_values_f, z5_values_f, 'b-', label='wingspan-lift')
plt.ylabel(z1_label + '/' + z2_label)
plt.xlabel(x_label)
plt.plot(x_values_f, z6_values_f, 'y-', label='wingspan-drag')
plt.legend()
plt.subplot(212)
plt.plot(y_values_f, z7_values_f, 'b-', label='chord-length-lift')
plt.ylabel(z1_label + '/' + z2_label)
plt.xlabel(y_label)
plt.plot(y_values_f, z8_values_f, 'y-', label='chord-length-drag')
plt.legend()

plt.show()
