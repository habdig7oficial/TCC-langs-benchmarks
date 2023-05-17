FROM gcc:bullseye

WORKDIR /usr/src/app

COPY . . 

RUN apt update

RUN apt install cmake -y    

RUN cmake /usr/src/app/

RUN make 

RUN make install

EXPOSE 8080

CMD ["./main"]