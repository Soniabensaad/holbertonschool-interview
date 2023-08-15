#!/usr/bin/python3

"""method that determines if all the boxes can be opened."""
def canUnlockAll(boxes):
    opened = all(isinstance(box, list) and box for box in boxes)
    if not opened:
        return False
    return True
