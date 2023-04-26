#!/bin/bash


## Rust - Actix
cd rust-actix
#docker build -t rust-actix .
cd ..

## TS (node) - Express
cd node-ts-express
docker build -t node-express .
cd ..

## TS (deno) - Oak
cd deno-ts-oak
docker build -t deno-oak .
cd ..

## Go - Gin
cd go-gin
docker build -t go-gin .
cd ..

## C++ - Drogon
cd c++-drogon
docker build -t c++-drogon .
cd ..