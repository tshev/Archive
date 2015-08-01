#!/usr/bin/python
import flask
from flask import request
app = flask.Flask("Application", static_folder='static')
app.debug = True
@app.route("/", methods = ["GET"])
def hello():
    return flask.render_template("index.html")
@app.route("/", methods = ["POST"])
def greating():
    return "Hello, %s" % request.form["name"]

app.run()
