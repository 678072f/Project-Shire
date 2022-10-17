# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                                                                   #
# Wing Design Datapoint Generator                                                   #
#                                                                                   #
# This script generates a file with datapoints for use in designing an airplane.    #
#                                                                                   #
# By: Daniel Duhon                                                                  #
# 10/12/2022                                                                        #
#                                                                                   #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Libraries - for extra tools and graphing
import numpy as np

# Functions - for calculating outputs
def lift_coeff(lift, dynamic_pressure, wing_area):
    c_l = lift / (dynamic_pressure * wing_area)
    return c_l
    

def dynamic_pressure(density, velocity):
    q = (1/2) * density * (velocity ** 2)
    return q
    

def aspect_ratio(wingspan, area):
    ar = (wingspan ** 2) / area
    return ar
    
    
# Design Input Parameters - variables
weight = np.linspace(5000, 6000, num=6)
velocity = np.linspace(100, 250, num=16)
chord_length = np.linspace(4, 6, num=21)
angle_of_attack = 0
wingspan = np.linspace(20, 50, num=11)

# Constants - assumptions
density = 0.002377
lift = weight

# Iterations - iterate through each scenario and graph them.
ar = []
output = []
for i in lift:
    for j in velocity:
        for k in chord_length:
            for l in wingspan:
                q = dynamic_pressure(density, j)
                area = k * l
                ar.append(aspect_ratio(l, area))
                c_l = lift_coeff(i, q, area)
                output.append([i, j, k, l, c_l])

print(output)

# Output to file for saving later
with open('output.csv', 'w') as out_file:
    out_file.write("Weight, Velocity, Chord Length, Wing Span, Lift Coefficient\n")
    for i in output:
        out_file.write("%.4f, %.4f, %.4f, %.4f, %.4f\n" % (i[0], i[1], i[2], i[3], i[4]))
