import java.util.*;
import java.io.*;

public class Main {
	static int N, M, res;
	static int arr[];
	static void init() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
	}
	static void calc() {
		int t = 0, cal = 0;
		for(int i = 0; i < N; i++) {
			cal += arr[i];
			while(cal > M) {
				cal -= arr[t++];
			}
			if(cal == M) res++;
		}
	}
	public static void main(String[] args) throws Exception{
		init();
		calc();
		System.out.println(res);
		
	}
}
