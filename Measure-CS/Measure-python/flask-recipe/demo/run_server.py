import super_app
import os
import sys

if __name__ == '__main__':
    HOST = os.environ.get('SERVER_HOST', 'localhost')
    PORT = 8010
    super_app.app.run(HOST, PORT)
