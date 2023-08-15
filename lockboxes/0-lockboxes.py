#!/usr/bin/python3

"""method that determines if all the boxes can be opened."""
def canUnlockAll(boxes):
    for box in boxes:
        if not isinstance(box, list) or not box:
            return False
    return True

    
