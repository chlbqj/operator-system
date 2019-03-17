import java.net.*;
import java.io.*;
import java.util.Random;
public class server
{
	public static void main(String[] args) {
		String[] strArray = {"I love KUO LAO",
			"Have a nice day",
			"I love OS",
			"Please let me pass",
			"I can't remember when I had a more pleasant time"}; 
		try {
			ServerSocket sock = new ServerSocket(6013);
			/* now listen for connections */
			while (true) {
				Socket client = sock.accept();
				PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
				/* write the Date to the socket */
				Random r=new Random();
        			int randomNumber=r.nextInt(strArray.length);
				pout.println(strArray[randomNumber]);
				/* close the socket and resume */
				/* listening for connections */
				client.close();
			}
		}
		catch (IOException ioe) {
			System.err.println(ioe);
		}
	}
}