#!/bin/bash

docker run -it --rm --name ruby-islands -v "$PWD":/usr/src/islands -w /usr/src/islands ruby:2.5 ruby islands.rb
