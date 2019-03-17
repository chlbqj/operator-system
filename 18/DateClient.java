import java.net.*;
import java.io.*;
import java.util.*;

public class DateClient
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		try {
			/* make connection to server socket */
			Socket sock = new Socket("127.0.0.1",6014);
			DataOutputStream out = new DataOutputStream(sock.getOutputStream());
			InputStream in = sock.getInputStream();
			ByteArrayOutputStream bin = new ByteArrayOutputStream();

			while(true){
      	//Take user input
      	String m = sc.nextLine();

      	byte[] byteMsg = m.getBytes();
      	String message = new String(byteMsg, "UTF-8");
        //Check if the escape character is used
     		if(message.equals("exit()")){
        	sock.close();
        	break;
      	}
				else if(message.equals("")) {
        	System.out.println("請輸入字串：");
      	}
				else {
          //Output message to the output stream
        	out.write(byteMsg);
          //Read the response from the server
        	int nRead;
        	byte[] data = new byte[16384];

        	if ((nRead = in.read(data, 0, data.length)) != -1){
        		bin.write(data,0,nRead);
        	}
        	bin.flush();
        	String res = new String(bin.toByteArray(), "UTF-8");
        	System.out.println("Server: " + res);
        	bin.reset();
				}
			}
		}
		catch (IOException ioe) {
      System.err.println(ioe);
		}
	}
}
