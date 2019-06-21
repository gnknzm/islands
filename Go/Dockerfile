FROM golang:latest

RUN apt-get update && \
	go get -u github.com/labstack/echo

ADD ./main /go

CMD ["go", "run", "main.go"]
