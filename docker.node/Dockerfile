FROM sungyong/gtest:latest

RUN apt-get update \
  && apt-get install -q -y \
  python-is-python3 pip golang nodejs \
  procps apt-transport-https gnupg2
RUN npm install -g adr-tools tig nvm npx yarn