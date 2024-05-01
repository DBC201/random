from setuptools import setup

setup(
    name="postman",
    version='0.0.2',
    author="dbc201",
    author_email="denizbcakiroglu@gmail.com",
    packages=["postman"],
    url="https://github.com/DBC201/Postman",
    license='LICENSE.txt',
    description="A script for sending files to web server via post requests",
    long_description=open('Readme.txt').read(),
    install_requires=[
        "requests"
    ],
    python_requires='>=3.7',
)
