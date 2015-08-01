# perf2.py
# requests/sec of fast requests

from socket import *
import time
import sys
sock = socket(AF_INET, SOCK_DGRAM)
sock.connect(('localhost', 4321))

n = 0

from threading import Thread
def monitor():
    global n
    while True:
        time.sleep(1)
        print(n, 'reqs/sec')
        n = 0
Thread(target=monitor).start()

UDP_IP = "127.0.0.1"
UDP_PORT = 4321
while True:
    MESSAGE = "1"
    sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))

    n += 1
