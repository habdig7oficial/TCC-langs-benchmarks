FROM debian:latest as ideps

WORKDIR /usr/src/app

COPY . . 

WORKDIR /usr/src/

##

RUN apt update

RUN apt install git -y
#RUN apt install gcc -y
RUN apt install gcc -y
RUN apt install g++ -y
RUN apt install cmake -y

RUN apt install libjsoncpp-dev -y 

RUN apt install uuid-dev -y 

RUN apt install openssl -y 
RUN apt install libssl-dev -y 

RUN apt install zlib1g-dev -y


##

FROM ideps as drogon

RUN git clone https://github.com/drogonframework/drogon drogon

WORKDIR /usr/src/drogon

RUN git submodule update --init

RUN mkdir build

WORKDIR /usr/src/drogon/build

RUN cmake ..
    
RUN make 

RUN make install

FROM drogon as cpp-drogon

WORKDIR /usr/src/app/build

RUN cmake .. 

RUN make

EXPOSE 8080

CMD ["./c++-drogon"]