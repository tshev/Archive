from flask import Flask
import flask
app = Flask(__name__, static_folder="static")
@app.route('/')
def f1():
	#fp = open('/home/tshev/Art/Projects/Service/imdb/views/layout/application.html')
	#text = fp.read()
	#return flask.render_template('application.html')
	return "<html>"
@app.route('/json')
def f2():
	import model
	return model.get()	
app.run()
