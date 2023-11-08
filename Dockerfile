FROM alpine as build

RUN apk update ; apk add build-base ; apk add git ; apk add ncurses-libs ; apk add ncurses-doc; apk add ncurses-dev ; apk add ncurses-libs ; apk add ncurses-static ; apk add ncurses ; apk add ncurses-terminfo-base ; apk add vdr-skincurses ; apk add ncurses-terminfo

RUN git clone https://21k0378:123456@git.bk252.ru/21k0378/DZ_OCremake
COPY . /tmp
#RUN cd /tmp; rm -r DZ_OCremake/DZ_OC;rm -r DZ_OC_remake/OS_Part2
RUN gcc /DZ_OCremake/Snake/snake.c -o /star.exe -lncurses

FROM alpine
RUN apk update; apk add ncurses-libs
COPY —from=build /star.exe /

CMD ["/star.exe"]