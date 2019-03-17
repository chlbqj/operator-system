import java.net.*;
import java.io.*;

public class DateServer
{
	private ServerSocket sock;
	private Socket client;
	private boolean connection = true;

	public DateServer () {
		try {
			sock = new ServerSocket(6014);
			System.out.println("[Server]: Started.");
			/* now listen for connections */
			while (connection) {
				client = sock.accept();
				// Get the input and output stream from the socket connection
     		DataOutputStream out = new DataOutputStream(client.getOutputStream());
     		ByteArrayOutputStream buffer = new ByteArrayOutputStream();
     		InputStream in = client.getInputStream();
        while(connection){
       		//Get the message from the input stream
        	int nRead;
        	byte[] data = new byte[16384];

        	if ((nRead = in.read(data, 0, data.length)) != -1){
        		buffer.write(data,0,nRead);
        	}
				  else if ((nRead = in.read(data, 0, data.length)) == -1){
          	break;
        	}
  				buffer.flush();
  				byte[] byteMsg = buffer.toByteArray();
			    String msg = new String(byteMsg, "UTF-8");
       		out.write(byteMsg);
       		out.flush();
       		buffer.reset();
     		}
        connection = false;
   		}

   		//Server has been terminated by the exit symbol
   		client.close();
   		System.out.println("[Server]: Server process terminated by client.");
  	}
		catch (IOException ioe) {
			System.err.println(ioe);
		}
 	}

 	public static void main (String [] args) {
  		new DateServer();
 	}
}
