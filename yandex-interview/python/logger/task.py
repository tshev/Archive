import collections
def common_log_counter(logfile, n=10):
  res = collections.Counter()
  with open (logfile) as fp:
    for line in fp:
      ip, *_ = fp.split(" ")
      res[ip] += 1
  return res.most_common(n=n)

print(common_log_counter("access.log")

