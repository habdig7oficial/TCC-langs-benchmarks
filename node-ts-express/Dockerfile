FROM node

WORKDIR /usr/src/app

COPY package*.json ./
COPY . . 

RUN npm install
#RUN npm ci --omit=dev ## Production

EXPOSE 8080

CMD ["npm","run","dev"]