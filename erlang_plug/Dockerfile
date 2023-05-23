FROM erlang

WORKDIR /usr/src/app

COPY . . 

#RUN mix local.hex --force

#RUN mix compile

RUN wget https://s3.amazonaws.com/rebar3/rebar3

RUN chmod 777 rebar3

RUN ./rebar3 local install

RUN rebar3 update

RUN rebar3 compile

RUN rebar3 release -n erlang_plug

EXPOSE 8080


CMD ["/bin/bash"]   