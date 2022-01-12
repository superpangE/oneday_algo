import java.util.*;
import java.io.*;

public class Main {
	static HashMap<String, String>h = new HashMap<>();
	static int N, M;
	
	static void init() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		for (int i = 1; i <= N; i++) {
			String tmp = br.readLine();
			h.put(tmp, Integer.toString(i));
			h.put(Integer.toString(i),tmp);
		}
		
		for (int i = 0; i < M; i++) {
			System.out.println(h.get(br.readLine()));
		}
	}
	public static void main(String[] args) throws Exception{
		init();

	}
}
