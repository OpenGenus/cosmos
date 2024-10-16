#!/usr/bin/env bash

find code/ -type f -name "*.py" | xargs black --check
