import java.util.*;
import java.io.*;

public class Main {
	
	static int N;
	static Stack<Integer>s = new Stack<>();
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			String tmp = st.nextToken();
			
			if(tmp.equals("push")) {
				s.add(Integer.parseInt(st.nextToken()));
			}
			else if(tmp.equals("top")) {
				if(s.isEmpty()) System.out.println("-1");
				else System.out.println(s.peek());
			}
			else if(tmp.equals("size")) {
				System.out.println(s.size());
			}
			else if(tmp.equals("empty")) {
				if(s.isEmpty()) System.out.println("1");
				else System.out.println("0");
			}
			else {
				if(s.isEmpty()) System.out.println("-1");
				else {
					System.out.println(s.pop());
				}
			}
		}
	}
}
