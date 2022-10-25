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


def drag_coeff(drag, dynamic_pressure, wing_area, c_l, aspect_ratio):
    c_d = (drag / (dynamic_pressure * wing_area)) + ((c_l**2) / (np.pi * 0.8 * aspect_ratio))
    return c_d
    

def dynamic_pressure(density, velocity):
    q = (1/2) * density * (velocity ** 2)
    return q
    

def aspect_ratio(wingspan, area):
    ar = (wingspan ** 2) / area
    return ar


def knots_feet_s(velocity):
    hrs_seconds = 3600
    nautical_miles_feet = 6076.11549
    fts = (velocity * hrs_seconds) / nautical_miles_feet
    return fts
    
    
# Design Input Parameters - variables
weight = np.linspace(6000, 12500, num=14)
velocity = np.linspace(100, 250, num=7)
chord_length = np.linspace(4, 6, num=9)
angle_of_attack = 0
wingspan = np.linspace(20, 50, num=7)

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
                q = dynamic_pressure(density, knots_feet_s(j))
                area = k * l
                ar.append(aspect_ratio(l, area))
                c_l = lift_coeff(i, q, area)
                c_d = drag_coeff(1000, q, area, c_l,aspect_ratio(l, area))
                output.append([i, j, k, l, c_l, c_d])

for i in output:
    print("%.4f, %.4f, %.4f, %.4f, %.4f, %.4f\n" %(i[0], i[1], i[2], i[3], i[4], i[5]))


# Output to file for saving later
with open('output.csv', 'w') as out_file:
    out_file.write("Weight, Velocity, Chord Length, Wing Span, Lift Coefficient, Drag Coefficient\n")
    for i in output:
        out_file.write("%.4f, %.4f, %.4f, %.4f, %.4f, %.4f\n" % (i[0], i[1], i[2], i[3], i[4], i[5]))
