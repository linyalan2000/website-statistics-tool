
index.cgi:index.o cgic.o connect_mysql.o pass_msg.o get_pos.o
	gcc index.o cgic.o connect_mysql.o pass_msg.o get_pos.o -o index.cgi `mysql_config --cflags --libs` -l curl
index.o:index.c
	gcc -c index.c
cgic.o:cgic.c 
	gcc -c cgic.c
pass_msg.o:pass_msg.c
	gcc -c pass_msg.c
get_pos.o:get_pos.c
	gcc -c get_pos.c
connect_mysql.o:connect_mysql.c
	gcc -c connect_mysql.c 
clean:
	rm *.cgi *.o 



