import time
import random
import datetime
def measure(func):
    def wrapper(*args, **kwargs):
        begin = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        random_name = str(hex(random.randint(10**4, 10**15)))
        ctime = str(datetime.datetime.now())
        name = "time-%s__%s" % (ctime, random_name)
        fp = open(name, "w")
        fp.write("func_name:\t%s\n" % (func.func_name))
        fp.write("elapsed_time:\t%f" % (end - begin))
        return result
    return wrapper

@measure
def sq(x):
    return x**1000

print sq(13)
