FROM eclipse-temurin:latest

WORKDIR /usr/src/app

COPY . . 

RUN apt update 

RUN apt install wget -y

#RUN apt install tar -y

#WORKDIR /bin

RUN wget https://github.com/JetBrains/kotlin/releases/download/v1.8.21/kotlin-native-linux-x86_64-1.8.21.tar.gz

RUN ls 

RUN tar -xvf kotlin-native-linux-x86_64-1.8.21.tar.gz

RUN ls

RUN mv kotlin-native-linux-x86_64-1.8.21.tar.gz /bin

#RUN kotlinc --help 

CMD ["/bin/bash"]
