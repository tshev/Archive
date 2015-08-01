import re


def validate_login_first(login):
    if len(login) > 20:
        return False

    if len(login) == 1:
        return login[0].isalpha()

    regex = re.compile(r"^[a-zA-Z][\.\-A-Za-z0-9]*[a-zA-Z0-9]$")
    try:
        if regex.match(login).pos == 0:
            return True
        else:
            return False
    except Exception:
        return False


def validate_login_second(login):
    if len(login) > 20:
        return False

    if len(login) == 1:
        return login[0].isalpha()

    regex = re.compile(r"^[a-zA-Z][\.\-A-Za-z0-9]*[a-zA-Z0-9]$")
    matches = regex.findall(login)
    return len(matches) != 0



def validate_login_third(login):
    if len(login) > 20:
        return False

    regex = re.compile(r"(^[a-zA-Z]$)|(^[a-zA-Z][\.\-A-Za-z0-9]*[a-zA-Z0-9]$)")
    matches = regex.findall(login)
    return len(matches) != 0


def validate_login_without_regex(login):
    length = len(login)
    if length < 1 or length > 20:
        return False, "fail, length"

    if not login[0].isalpha():
        return False, "fail, first letter"

    if not login[-1].isalpha() and not login[-1].isdigit():
        return False, "fail, last letter"

    acceptable = [".", "-"]
    fail_inside = "fail, between and begin and end"

    for sym in login[1: -1]:
        if not sym.isalpha() and not sym.isdigit() and sym not in acceptable:
            return False, fail_inside

    return True, "Ok"


if __name__ == '__main__':
    print(validate_login_without_regex("taras"))
    print(validate_login_without_regex("9aras"))
