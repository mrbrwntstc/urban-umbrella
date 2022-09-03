#! /bin/bash

mkdir -p out/build

pushd out/build

cmake -DGLFW_BUILD_DOCS=OFF -S ../../ -B .

make

popd
