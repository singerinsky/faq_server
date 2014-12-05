#!/usr/bin/env bash

cd template.protos
echo "generate python file for protobuf in directoy: python"
protoc --python_out=../python *.proto

echo "generate cpp file for protobuf in directory: cpp"
protoc --cpp_out=../../../prototype/ *.proto


