FROM rust

COPY . . 

RUN cargo install --path . 

RUN cargo build --release

#RUN ls

CMD ["cargo run"]