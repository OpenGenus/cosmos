#!/usr/bin/env python
"""A python script to generate the meta-data of the cosmos repository for search tool"""
from os import walk
import json

if __name__ == "__main__":
    data = {}
    for (dirpath, dirnames, filenames) in walk('code/'):
        if dirnames == []:
            data[dirpath] = filenames
    with open('metadata.json', 'w') as f:
        json.dump(data, f)
