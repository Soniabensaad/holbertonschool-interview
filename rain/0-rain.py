#!/usr/bin/python3
"""rain """
def rain(walls):
    if not walls:
        return 0
    
    total_water = 0
    left_max = 0
    right_max = 0

    for i in range(len(walls)):
        left_max = max(left_max, walls[i])
    
    for i in range(len(walls) - 1, -1, -1):
        right_max = max(right_max, walls[i])

    for i in range(len(walls)):
        current_wall = walls[i]
        water_at_position = max(0, min(left_max, right_max) - current_wall)
        total_water += water_at_position

    return total_water
