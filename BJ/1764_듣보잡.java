import java.util.*;
import java.io.*;

public class Main {
	
	static HashMap<String,String>h1 = new HashMap<>();
	static HashMap<String,String>h2 = new HashMap<>();
	
	static int N, M;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		String tmp = "";
		
		for (int i = 0; i < N; i++) {
			tmp = br.readLine();
			h1.put(tmp, tmp);
		}
		for (int i = 0; i < M; i++) {
			tmp = br.readLine();
			h2.put(tmp, tmp);
		}
		int cal = 0;
		
		for (String h: h1.keySet()) {
			if(h2.get(h) != null) cal++;
		}
		System.out.println(cal);
		String arr[] = new String[cal];
		
		int idx=0;
		for (String h: h1.keySet()) {
			if(h2.get(h) != null) arr[idx++] = h;
		}
		
		Arrays.sort(arr);
		for (int i = 0; i < cal; i++) {
			System.out.println(arr[i]);
		}
	}
}
