from super_app import app
import flask
print("IMPOROT APP2")

@app.route("/app2")
def app2():
    return flask.render_template("app2/index.html")

