FROM golang

WORKDIR /usr/src/app

COPY . . 

RUN go mod tidy 

RUN cd ./src

EXPOSE 8080

CMD ["go run ."]