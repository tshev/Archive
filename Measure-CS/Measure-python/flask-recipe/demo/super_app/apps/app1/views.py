from super_app import app

print("IMPOROT APP1")

@app.route("/")
def home():
    return "Welcome to home page!"
