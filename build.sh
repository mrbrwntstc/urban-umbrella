#! /bin/bash

mkdir -p out/build

pushd out/build

cmake -DGLFW_BUILD_DOCS=OFF -DUSE_ADDER=ON -S ../../ -B .

make

popd
