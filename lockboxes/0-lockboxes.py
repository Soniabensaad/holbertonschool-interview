#!/usr/bin/python3

"""method that determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    num_boxes = len(boxes)
    unlocked = [False] * num_boxes
    unlocked[0] = True
    locked = [0]

    while locked:
        current = locked.pop()
        for key in boxes[current]:
            if 0 <= key < num_boxes and not unlocked[key]:
                unlocked[key] = True
                locked.append(key)
    return all(unlocked)
