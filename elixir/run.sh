#!/bin/bash

 docker run -it --rm --name islands -v "$PWD":/usr/src/islands -w /usr/src/islands elixir elixir islands.exs
