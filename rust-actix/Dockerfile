FROM rust

WORKDIR /usr/src/app

COPY . . 

#RUN cargo install --path . 

RUN cargo build --release

EXPOSE 8080

CMD ["cargo","run"]