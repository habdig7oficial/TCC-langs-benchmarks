FROM elixir

WORKDIR /usr/src/app

COPY . . 

RUN mix local.hex --force

RUN mix deps.get

#RUN mix compile

EXPOSE 8080


CMD ["mix","run","--no-halt"]