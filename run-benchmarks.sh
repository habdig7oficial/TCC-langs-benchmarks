#!/bin/bash

## Run Rust with Actix

kill $(lsof -t -i:8080)

cd rust-actix

cargo run . &

until pids=$(lsof -t -i:8080)
do   
    sleep 1
done

ab -n 100000 -c 1020  http://localhost:8080/ > ../benchmaks/$(basename $(pwd))
#ab -n 50 -c 5  http://localhost:8080/ >../benchmaks/$(basename $(pwd))
kill $(lsof -t -i:8080)

echo feito $(basename $(pwd)) no arquivo ../benchmaks/$(basename $(pwd))

cd .. 

###################################################################################




## Run Go with Gin

kill $(lsof -t -i:8080)

cd go-gin

go run ./src/ &

until pids=$(lsof -t -i:8080)
do   
    sleep 1
done

ab -n 100000 -c 1020  http://localhost:8080/ > ../benchmaks/$(basename $(pwd))
#ab -n 50 -c 5  http://localhost:8080/ > ../benchmaks/$(basename $(pwd))
kill $(lsof -t -i:8080)

echo feito $(basename $(pwd)) no arquivo ../benchmaks/$(basename $(pwd))

cd .. 

###################################################################################




## Run TS (Node) with Express 

kill $(lsof -t -i:8080)

cd node-ts-express

npm run dev &

until pids=$(lsof -t -i:8080)
do   
    sleep 1
done

ab -n 100000 -c 1020  http://localhost:8080/ > ../benchmaks/$(basename $(pwd))
#ab -n 50 -c 5  http://localhost:8080/ > ../benchmaks/$(basename $(pwd))
kill $(lsof -t -i:8080)

echo feito $(basename $(pwd)) no arquivo ../benchmaks/$(basename $(pwd))

cd .. 

###################################################################################




## Run TS (Deno) with Oak 

kill $(lsof -t -i:8080)

cd deno-ts-oak

deno run --allow-net trigger.ts &

until pids=$(lsof -t -i:8080)
do   
    sleep 1
done

ab -n 100000 -c 1020  http://localhost:8080/ > ../benchmaks/$(basename $(pwd))
#ab -n 50 -c 5  http://localhost:8080/ > ../benchmaks/$(basename $(pwd))
kill $(lsof -t -i:8080)

echo feito $(basename $(pwd)) no arquivo ../benchmaks/$(basename $(pwd))

cd .. 

###################################################################################






## Run C++ with Drogon

kill $(lsof -t -i:8080)

cd c++-drogon/build

cmake .. && make
./c++-drogon

until pids=$(lsof -t -i:8080)
do   
    sleep 1
done

ab -n 100000 -c 1020  http://localhost:8080/ > ../benchmaks/$(basename $(pwd))
#ab -n 50 -c 5  http://localhost:8080/ > ../benchmaks/$(basename $(pwd))
kill $(lsof -t -i:8080)

echo feito $(basename $(pwd)) no arquivo ../benchmaks/$(basename $(pwd))

cd .. 

###################################################################################


