# Graphing Program for Project-Shire

import matplotlib.pyplot as plt
import numpy as np

print('It works!')

# Need to add graphing function.
with open("output.csv", "r") as out:
	x_values = []
	y_values = []
	rawData = out.read()
	splitData = rawData.split('\n')

	strData = [line.split(',') for line in splitData]

	for group in strData:
		try:
			x_values.append(float(group[4]))
		except:
			continue

	x_values = np.array(x_values)
	print(x_values)

