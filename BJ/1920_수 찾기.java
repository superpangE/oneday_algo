import java.util.*;
import java.io.*;
public class Main {

	static HashMap<Integer, Integer>h= new HashMap<>();
	static int N, M;
	
	public static void main(String[] args) throws Exception{
		
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			h.put(Integer.parseInt(st.nextToken()), 1);
		}
		
		M = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++) {
			if(h.get(Integer.parseInt(st.nextToken())) == null)
				System.out.println("0");
			else
				System.out.println("1");
		}
	}
	
}
