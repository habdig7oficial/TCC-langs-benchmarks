FROM golang

COPY . . 

RUN go mod tidy 

RUN cd ./src

CMD ["go run ."]