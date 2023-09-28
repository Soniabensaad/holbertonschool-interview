#!/usr/bin/python3
"""Write a script that reads
stdin line by line and computes metrics"""
import sys

if __name__ == "__main__":
    """code"""
    code_status = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }
    count = 0
    file_size = 0

def parsed_line(line):
    """read parse line"""
    try:
        parse_line = line.split()
        status_code = parse_line[-2]
        if status_code in code_status.keys():
            code_status[status_code] += 1
        return int(parse_line[-1])
    except Exception:
        return 0

def print_stats():
    """print stats in ascending order"""
    print("File size: {}".format(file_size))
    for k in sorted(code_status.keys()):
        if code_status[k]:
            print("{}: {}".format(k, code_status[k]))

try:
    for line in sys.stdin:
        file_size += parsed_line(line)
        if count % 10 == 0:
            print_stats()
        count += 1
except KeyboardInterrupt:
    print_stats()
    raise
print_stats()
