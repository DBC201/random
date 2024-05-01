import requests
import os
import sys
import argparse


def post_files(url, files, verbose=False):
    for file in files:
        if os.path.isfile(file):
            if verbose:
                print(f"Uploading \"{file}\"...")
                try:
                    requests.post(url, files={"file": open(file, "rb")})
                except Exception as e:
                    print(e)
                    print(f"\"{file}\" could not be uploaded")
                else:
                    print(f"\"{file}\" successfully uploaded to \"{url}\"")
            else:
                try:
                    requests.post(url, files={"file": open(file, "rb")})
                except:
                    pass
        elif os.path.isdir(file):
            sub_files = os.listdir(file)
            sub_files = join_paths(file, sub_files)
            post_files(url, sub_files)
        elif verbose:
            print(f"Invalid file path: {file}")


def input_parse():
    parser = argparse.ArgumentParser(description="A program for sending files via post request")
    parser.add_argument("url")
    parser.add_argument("file_path")
    parser.add_argument("-v", "--verbose", action="store_true", dest="verbose")
    return parser


def join_paths(path, files):
    for i in range(len(files)):
        files[i] = os.path.join(path, files[i])
    return files


def main(argv):
    parser = input_parse()
    args = parser.parse_args(argv)
    url = ''
    file_path = ''
    verbose = False

    if args.url:
        url = args.url
    if args.file_path:
        file_path = args.file_path
    if args.verbose:
        verbose = True

    if os.path.isdir(file_path):
        files = os.listdir(file_path)
        files = join_paths(file_path, files)
    elif os.path.isfile(file_path):
        files = [file_path]
    else:
        raise RuntimeError(f"Invalid file path: {file_path}")

    post_files(url, files, verbose)


if __name__ == "__main__":
    main(sys.argv[1:])
