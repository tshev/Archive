import flask

class BasicService(object):
    def __init__(self):
        self.request = flask.request
