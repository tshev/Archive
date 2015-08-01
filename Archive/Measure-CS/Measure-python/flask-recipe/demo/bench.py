import threading
import time
import requests
from concurrent.futures import ThreadPoolExecutor as Pool
n = 0
url = "http://localhost:8000/"
start = time.time()

def delta():
    return time.time() - start


def counter():
    global n
    while True:
        time.sleep(1)
        print("Requests/per 1 sec: %d" % (n / int(delta())))
        # n = 0


def get_page(url):
      r = requests.get(url)
      global n
      if r.status_code == 200:
        n += 1

threading.Thread(target=counter, daemon=True).start()

pool = Pool(40)


def submit():
    global n
    # get_page(url)
    pool.submit(get_page, url)

while True:
    submit()
