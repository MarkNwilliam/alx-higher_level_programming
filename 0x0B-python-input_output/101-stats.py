#!/usr/bin/python3
import sys
import signal

lines_processed = 0
total_size = 0
status_code_counts = {}

def handle_keyboard_interrupt(signal, frame):
    print("File size: {}".format(total_size))
    for status_code in sorted(status_code_counts.keys()):
        print("{}: {}".format(status_code, status_code_counts[status_code]))
    sys.exit(0)

signal.signal(signal.SIGINT, handle_keyboard_interrupt)

for line in sys.stdin:
    lines_processed += 1
    parts = line.strip().split()
    status_code = int(parts[-2])
    size = int(parts[-1])
    total_size += size

    if status_code in status_code_counts:
        status_code_counts[status_code] += 1
    else:
        status_code_counts[status_code] = 1

    if lines_processed % 10 == 0:
        handle_keyboard_interrupt(None, None)