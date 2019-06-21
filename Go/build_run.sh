#!/bin/bash
docker build ./ -t rci_n/zero:latest
docker run --name rci_zero -it --rm -p 1323:1323 rci_n/zero:latest
