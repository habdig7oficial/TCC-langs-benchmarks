FROM golang

WORKDIR /usr/src/app

COPY go.mod go.sum ./
COPY . . 

RUN go mod download

WORKDIR /usr/src/app/src

RUN CGO_ENABLED=0 GOOS=linux go build -o /go_gin


EXPOSE 8080

# Run
CMD ["/go_gin"]