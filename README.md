README
======

Building
--------

Clone this repo __recursively__ and run the bootstrap.sh script to install the required dependencies:

    git clone --recursively https://github.com/vmrob/game.git game
    cd game
    ./bootstrap.sh

Then, you'll need [Boost Build](https://github.com/boostorg/build) to actually build the project. Once you have Boost Build installed and in your PATH, building should be as simple as running `b2` from the root directory.

    cd game
    b2
