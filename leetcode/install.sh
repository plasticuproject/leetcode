#!/bin/sh
pip uninstall leetcode -y
rm -r build/ leetcode.egg-info/
CC=gcc pip install .
