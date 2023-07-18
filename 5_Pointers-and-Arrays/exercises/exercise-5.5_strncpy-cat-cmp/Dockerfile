FROM ubuntu
RUN apt-get update; \
    apt-get install -y build-essential; \
    apt-get install -y valgrind; \
    apt-get install -y check

WORKDIR /home/

ENTRYPOINT [ "make", "clean" ]
CMD [ "leaks" ]
#  ENTRYPOINT [ "/bin/bash" ]
