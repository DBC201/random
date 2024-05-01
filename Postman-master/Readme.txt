This script/package can be used to send files to a web server via post requests.

Using postman.py as a script:
url: url the post request is going to be made to
files: folder or the file path that want to be sent to server
-v, --verbose: prints out information about uploads on console

to install as a python package do pip install -e git+https://github.com/DBC201/Postman#egg=postman
this can be used in certain programs, especially post_files() is useful

example:
from postman import post_files

post_files(url, files, True) #true for making it show prompts

there is also a premade server which can be seen in the server folder
