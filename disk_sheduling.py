# STUDENT_ID:105590026
# NAME:黃彥穎
# CLASS:資工三
# python version:3.7
# 使用方法:於cmd輸入python .\disk_sheduling.py

import random
from heapq import *

CYLINDERS = 5000
REQUESTS = 1000

def FCFS(start, array):
    requests = array.copy()
    times = 0
    pos = start
    for req in requests:
        times += abs(req - pos)
        pos = req

    return times

def SSTF(start, array):
    requests = array.copy()
    times = 0
    pos = start
    heap = []
    while len(requests) > 0:
        for req in requests:
            heappush(heap, (abs(pos - req), req))
        temp = heappop(heap)[1]
        times += abs(pos - temp)
        pos = temp
        requests.remove(temp)
        heap = []

    return times

def SCAN(start, array):
    requests = array.copy()
    times = 0
    pos = start
    for req in range(pos, CYLINDERS + 1):
        if req in requests:
            times += abs(pos - req)
            pos = req
            requests.remove(req)
    times += abs(pos - CYLINDERS)
    pos = CYLINDERS
    for req in range(CYLINDERS, -1, -1):
        if req in requests:
            times += abs(pos - req)
            pos = req
            requests.remove(req)

    return times

def C_SCAN(start, array):
    requests = array.copy()
    times = 0
    pos = start
    for req in range(pos, CYLINDERS + 1):
        if req in requests:
            times += abs(pos - req)
            # print(abs(pos - req), " ",end ="")
            # print("        ", pos, "  seeked")
            pos = req
            requests.remove(req)
    times += abs(pos - CYLINDERS + 1)
    # print(abs(pos - CYLINDERS + 1))
    pos = CYLINDERS - 1
    times += pos
    # print(pos, " ", end ="")
    pos = 0
    for req in range(0, start + 1):
        if req in requests:
            times += abs(pos - req)
            # print(abs(pos - req), " ",end ="")
            pos = req
            # print("        ", req, "  seeked")
            requests.remove(req)

    return times

def LOOK(start, array):
    requests = array.copy()
    times = 0
    pos = start
    end = max(requests)
    first = min(requests)
    for req in range(pos, end + 1):
        if req in requests:
            times += abs(pos - req)
            pos = req
            requests.remove(req)
    for req in range(end, first-1, -1):
        if req in requests:
            times += abs(pos - req)
            pos = req
            requests.remove(req)

    return times

def C_LOOK(start, array):
    requests = array.copy()
    times = 0
    pos = start
    end = max(requests)
    first = min(requests)
    for req in range(pos, end + 1):
        if req in requests:
            times += abs(pos - req)
            pos = req
            requests.remove(req)
    times += abs(pos - first)
    pos = first
    for req in range(first, start+1):
        if req in requests:
            times += abs(pos - req)
            pos = req
            requests.remove(req)

    return times

if __name__ == '__main__':
    print("Provide initial position of disc arm (total cylinders=5000)")
    start = int(input())
    while start > 5000:
        print("Invalid! input again:")
        start = int(input())
    array = []
    # 隨機生成陣列
    for i in range(CYLINDERS):
        array.append(random.randint(0, 4999))
    print(array)

    print("FCFS total amount of movement: ",end='')
    print(FCFS(start, array))

    print("SSTF total amount of movement: ",end='')
    print(SSTF(start, array))

    print("SCAN total amount of movement: ",end='')
    print(SCAN(start, array))

    print("C_SCAN total amount of movement: ",end='')
    print(C_SCAN(start, array))

    print("LOOK total amount of movement: ",end='')
    print(LOOK(start, array))

    print("C_LOOK total amount of movement: ",end='')
    print(C_LOOK(start, array))
