import flask
import repository
import service

app = flask.Flask(__name__)
@app.route('/')
def homeServiceExec():
    x = service.IndexService()
    return x.index()
app.run()
