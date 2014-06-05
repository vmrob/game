#!/bin/bash -e

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

(
	cd "$DIR/deps/boost"

	./bootstrap.sh
	./b2 --build-dir="$DIR/temp/boost/" --prefix="$DIR/deps/" --variant=release --link=static --runtime-link=static --with-system install
)

(
	cd "$DIR/deps/cinder/xcode"

	xcrun xcodebuild -project cinder.xcodeproj -target cinder -configuration Release
	cp $DIR/deps/cinder/lib/libcinder* $DIR/deps/lib/
	cp -r $DIR/deps/cinder/include/ $DIR/deps/include
)