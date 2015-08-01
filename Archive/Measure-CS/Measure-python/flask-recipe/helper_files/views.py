from super_app import app


@app.route("/")
def home():
    return "Welcome to home page!"
