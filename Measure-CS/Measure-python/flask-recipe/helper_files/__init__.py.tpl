from flask import Flask
from . import settings
app = Flask(__name__)

[__import__("super_app.apps.%s.views" % (i))  for i in settings.APP_PACKAGES]
