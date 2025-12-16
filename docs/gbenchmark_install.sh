#!/bin/bash

# Just documentations of the commands, not supposed to be here, having it here to not keep it just locally.
# Commands I ran to install google benchmark library locally on my computer from zip.

unzip benchmark-main.zip
cd benchmark-main/
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$HOME/.local -DBENCHMARK_ENABLE_TESTING=OFF
make --build . --target install

