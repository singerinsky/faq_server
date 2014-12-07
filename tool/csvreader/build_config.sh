#!/usr/bin/env bash

python parse_config.py
cp -vf streams/*.bin ../../game_exe/streams/
echo "all protobuff binary files are stored in directory streams"
