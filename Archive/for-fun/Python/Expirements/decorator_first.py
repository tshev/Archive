def italic(func):
    def wrapper(*args, **kwargs):
        return "<i>%s</i>" % func(*args, **kwargs)
    return wrapper

@italic
def f(x):
    return x
print f("HELLO")


