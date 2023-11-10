#!/usr/bin/env bash

find code/ -type f -name "*.js" | xargs prettier --check
