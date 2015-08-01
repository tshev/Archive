import re


def check_login(login):
    regex = re.compile("(^[a-zA-Z][a-zA-Z0-9\.\-]*[a-zA-Z0-9]$)|([a-zA-Z])")
    return regex.match(login) is not regex
