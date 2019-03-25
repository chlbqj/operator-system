# operator-system
前面的作業在Branch中

//---------hw4-------------
Write a multithreaded program that calculates various statistical values for a list of numbers. This program will be passed a series of numbers on the command line and will then create three separate worker threads. One thread will determine the average of the numbers, the second will determine the maximum value, and the third will determine the minimum value. For example, suppose your program is passed
the integers
  # 90 81 78 95 79 72 85
The program will report
#  The average value is 82
#  The minimum value is 72
#  The maximum value is 95
The variables representing the average, minimum, and maximum values will be stored globally. The worker threads will set these values, and the parent thread will output the values once the workers have exited. (We could obviously expand this program by creating additional threads that determine other statistical values, such as median and standard deviation.)

//---------hw3-------------
16.Section 3.6.1 describes port numbers below 1024 as being well known —that is, they provide standard services. Port 17 is known as thequote-of-the-day service. When a client connects to port 17 on a server,the server responds with a quote for that day.
  Modify the date server shown in Figure 3.21 so that it delivers a quote of the day rather than the current date. The quotes should be
printable ASCII characters and should contain fewer than 512 characters,although multiple lines are allowed. Since port 17 is well known and therefore unavailable, have your server listen to port 6017. The date client shown in Figure 3.22 can be used to read the quotes returned by your server.

18.An echo server echoes back whatever it receives from a client. For example, if a client sends the server the string Hello there!, the server will respond with Hello there!
  Write an echo server using the Java networking API described in Section 3.6.1. This server will wait for a client connection using the
accept() method. When a client connection is received, the server will loop, performing the following steps:
  # • Read data from the socket into a buffer.
  # • Write the contents of the buffer back to the client.
The server will break out of the loop only when it has determined that the client has closed the connection.
  The date server shown in Figure 3.21 uses the java.io.BufferedReader class. BufferedReader extends the java.io.Reader class, which is used for reading character streams. However, the echo server cannot guarantee that it will read characters from clients; it may receive binary data as well. The class java.io.InputStream deals with data at the byte level rather than the character level. Thus, your echo
server must use an object that extends java.io.InputStream. The read() method in the java.io.InputStream class returns −1 when the client has closed its end of the socket connection.

20.Design a file-copying program named filecopy using ordinary pipes.This program will be passed two parameters: the name of the file to be copied and the name of the copied file. The program will then create an ordinary pipe and write the contents of the file to be copied to the pipe. The child process will read this file from the pipe and write it to the destination file. For example, if we invoke the program as follows:
  # filecopy input.txt copy.txt
the file input.txt will be written to the pipe. The child process will read the contents of this file and write it to the destination file copy.txt.
You may write this program using either UNIX or Windows pipes.


//---------hw2-------------
  The second part of this project involves modifying the kernel module so that it uses the kernel linked-list data structure.
  In Section 1.10, we covered various data structures that are common in operating systems. The Linux kernel provides several of these structures. Here,we explore using the circular, doubly linked list that is available to kernel developers. Much of what we discuss is available in the Linux source code —in this instance, the include file <linux/list.h>— and we recommend that you examine this file as you proceed through the following steps.
  Initially, you must define a struct containing the elements that are to be inserted in the linked list. The following C struct defines birthdays:
  
# struct birthday {
#  int day;
#  int month;
#  int year;
#  struct list head list;
# }

Notice the member struct list head list. The list head structure is defined in the include file <linux/types.h>. Its intention is to embed the linked list within the nodes that comprise the list. This list head structure is quite simple—it merely holds two members, next and prev, that point to the next and previous entries in the list. By embedding the linked list within the structure, Linux makes it possible to manage the data structure with a series of macro functions.
